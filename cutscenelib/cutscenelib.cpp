﻿#include "cutscenelib.h"
#include <sstream>
#include "HeaderOnlyCsv.hpp"
#include <deque>
#include <tchar.h>

using namespace NSCutScenelib;

std::vector<std::wstring> NSCutScenelib::split(const std::wstring& s, wchar_t delim)
{
    std::vector<std::wstring> result;
    std::wstringstream ss(s);
    std::wstring item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

void CutScene::Init(const std::wstring& csvfilepath,
                    IFont* font,
                    ISoundEffect* SE,
                    ISprite* sprTextBack,
                    ISprite* sprFade,
                    IModelCreator* modelCreator,
                    ICamera* camera,
                    const float eyeX,
                    const float eyeY,
                    const float eyeZ,
                    const float lookAtX,
                    const float lookAtY,
                    const float lookAtZ,
                    const bool bEnglish)
{
    m_csvfilepath = csvfilepath;
    m_font = font;
    m_SE = SE;
    m_sprTextBack = sprTextBack;
    m_sprFade = sprFade;
    m_modelCreator = modelCreator;
    m_camera = camera;
    m_restoreEyeX = eyeX;
    m_restoreEyeY = eyeY;
    m_restoreEyeZ = eyeZ;
    m_restoreLookAtX = lookAtX;
    m_restoreLookAtY = lookAtY;
    m_restoreLookAtZ = lookAtZ;

    m_font->Init(bEnglish);
    m_SE->Init();
    m_sprTextBack->Load(_T("textBack.png"));
    m_sprFade->Load(_T("black.png"));

    m_isFadeIn = true;

    std::vector<Action> actionList = CreateActionList();
    m_actionList = actionList;
    m_startTime = std::chrono::system_clock::now();
}

std::vector<Action> CutScene::CreateActionList()
{
    std::vector<Action> actionList;
    std::vector<std::vector<std::wstring> > vss = csv::Read(m_csvfilepath);

    for (std::size_t i = 1; i < vss.size(); ++i)
    {
        Action action;
        action.Init(vss.at(i), m_modelCreator, m_font, m_sprTextBack, m_SE, m_camera);
        actionList.push_back(action);
    }
    return actionList;
}

bool CutScene::Update()
{
    m_currentTime = std::chrono::system_clock::now();
    int duration = (int)std::chrono::duration_cast<std::chrono::milliseconds>(
                   m_currentTime - m_startTime).count();

    std::deque<bool> finishDeq;
    for (std::size_t i = 0; i < m_actionList.size(); ++i)
    {
        bool work = m_actionList.at(i).Update(duration);
        finishDeq.push_back(work);
    }
    std::size_t cnt = std::count(finishDeq.begin(), finishDeq.end(), false);

    if (duration <= 500)
    {
        m_isFadeIn = true;
        m_FadeInCount++;
    }
    else
    {
        m_isFadeIn = false;
    }

    if (cnt == 0)
    {
        m_isFadeOut = true;
    }

    if (m_isFadeOut)
    {
        m_FadeOutCount++;
        if (m_FadeOutCount > 30)
        {
            m_fadeOutFinish = true;
        }
    }
    return m_fadeOutFinish;
}

void CutScene::Render()
{
    m_currentTime = std::chrono::system_clock::now();
    int duration = (int)std::chrono::duration_cast<std::chrono::milliseconds>(
                   m_currentTime - m_startTime).count();
    for (std::size_t i = 0; i < m_actionList.size(); ++i)
    {
        m_actionList.at(i).Render(duration);
    }

    if (m_isFadeIn)
    {
        int transparency = 255 - (m_FadeInCount  * 255 / FADE_FRAME_MAX); 
        if (transparency >= 0)
        {
            m_sprFade->DrawImage(0, 0, transparency);
        }
    }
    if (m_isFadeOut)
    {
        int transparency = m_FadeOutCount  * 255 / FADE_FRAME_MAX; 
        if (transparency >= 0)
        {
            m_sprFade->DrawImage(0, 0, transparency);
        }
    }
}

void CutScene::Finalize()
{

    for (std::size_t i = 0; i < m_actionList.size(); ++i)
    {
        m_actionList.at(i).Finalize();
    }

    if (m_camera != nullptr)
    {
        m_camera->SetPosAndRot(m_restoreEyeX,    m_restoreEyeY,    m_restoreEyeZ,
                               m_restoreLookAtX, m_restoreLookAtY, m_restoreLookAtZ);
    }
    delete m_camera;
    m_camera = nullptr;

    delete m_modelCreator;
    m_modelCreator = nullptr;

    delete m_sprTextBack;
    m_sprTextBack = nullptr;

    delete m_sprFade;
    m_sprFade = nullptr;

    delete m_font;
    m_font = nullptr;

    delete m_SE;
    m_SE = nullptr;
}

