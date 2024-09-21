#include "cutscenelib.h"
#include <sstream>
#include "HeaderOnlyCsv.hpp"

std::vector<std::string> split(const std::string& s, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

void CutScene::Init(
    const std::string& csvfilepath,
    IFont* font,
    ISoundEffect* SE,
    ISprite* sprTextBack,
    ISprite* sprFade,
    ICamera* camera,
    const float eyeX,
    const float eyeY,
    const float eyeZ,
    const float lookAtX,
    const float lookAtY,
    const float lookAtZ)
{
    m_csvfilepath = csvfilepath;
    m_font = font;
    m_SE = SE;
    m_sprTextBack = sprTextBack;
    m_sprFade = sprFade;
    m_camera = camera;
    m_restoreEyeX = eyeX;
    m_restoreEyeY = eyeY;
    m_restoreEyeZ = eyeZ;
    m_restoreLookAtX = lookAtX;
    m_restoreLookAtY = lookAtY;
    m_restoreLookAtZ = lookAtZ;

    m_font->Init();
    m_SE->Init();
    m_sprTextBack->Load("textBack.png");
    m_sprFade->Load("black.png");

    m_isFadeIn = true;

    std::vector<Action> actionList = CreateActionList();
    m_actionList = actionList;
    m_startTime = std::chrono::system_clock::now();
}

std::vector<Action> CutScene::CreateActionList()
{
    std::vector<Action> actionList;
    std::vector<std::vector<std::string> > vss = csv::Read(m_csvfilepath);

    for (std::size_t i = 1; i < vss.size(); ++i)
    {
        Action action;
        action.Init(vss.at(i), m_camera);
        actionList.push_back(action);
    }
    return actionList;
}

bool CutScene::Update()
{
    for (std::size_t i = 0; i < m_actionList.size(); ++i)
    {
        m_currentTime = std::chrono::system_clock::now();
        int duration = (int)std::chrono::duration_cast<std::chrono::milliseconds>(
                       m_currentTime - m_startTime).count();

        m_actionList.at(i).Update(duration);
    }
    return false;
}

void CutScene::Render()
{
}

void CutScene::Finalize()
{
    m_camera->SetPosAndRot(m_restoreEyeX,    m_restoreEyeY,    m_restoreEyeZ,
                           m_restoreLookAtX, m_restoreLookAtY, m_restoreEyeZ);

    delete m_sprTextBack;
    m_sprTextBack = nullptr;

    delete m_sprFade;
    m_sprFade = nullptr;

    delete m_font;
    m_font = nullptr;

    delete m_SE;
    m_SE = nullptr;
}

void Action::Init(const std::vector<std::string>& scriptLine, ICamera* camera)
{
    m_camera = camera;

    m_id    = std::atoi(scriptLine.at(0).c_str());
    m_start = std::atoi(scriptLine.at(1).c_str());
    m_end   = std::atoi(scriptLine.at(2).c_str());

    if (scriptLine.at(3) == "カメラ")
    {
        m_eType = eType::CAMERA;
    }
    else if (scriptLine.at(3) == "モデル位置")
    {
        m_eType = eType::MODEL_POS;
    }
    else if (scriptLine.at(3) == "モデルアニメ")
    {
        m_eType = eType::MODEL_ANIM;
    }
    else if (scriptLine.at(3) == "テキスト")
    {
        m_eType = eType::TEXT;
    }
    else if (scriptLine.at(3) == "効果音")
    {
        m_eType = eType::SE;
    }

    if (m_eType == eType::CAMERA)
    {
        std::vector<std::string> vs;
        vs = split(scriptLine.at(4), ':');
        m_stCamera.m_startPosX = (float)std::atof(vs.at(0).c_str());
        m_stCamera.m_startPosY = (float)std::atof(vs.at(1).c_str());
        m_stCamera.m_startPosZ = (float)std::atof(vs.at(2).c_str());

        vs = split(scriptLine.at(5), ':');
        m_stCamera.m_startAtX = (float)std::atof(vs.at(0).c_str());
        m_stCamera.m_startAtY = (float)std::atof(vs.at(1).c_str());
        m_stCamera.m_startAtZ = (float)std::atof(vs.at(2).c_str());

        vs = split(scriptLine.at(6), ':');
        m_stCamera.m_endPosX = (float)std::atof(vs.at(0).c_str());
        m_stCamera.m_endPosY = (float)std::atof(vs.at(1).c_str());
        m_stCamera.m_endPosZ = (float)std::atof(vs.at(2).c_str());

        vs = split(scriptLine.at(7), ':');
        m_stCamera.m_endAtX = (float)std::atof(vs.at(0).c_str());
        m_stCamera.m_endAtY = (float)std::atof(vs.at(1).c_str());
        m_stCamera.m_endAtZ = (float)std::atof(vs.at(2).c_str());
    }
}

void Action::Update(const int elapsed)
{
    std::string work = std::to_string(elapsed);
    work += "\n";
    OutputDebugString(work.c_str());

    if (elapsed < m_start || m_end <= elapsed)
    {
        return;
    }
    if (m_eType == eType::CAMERA)
    {
        // progressは0.f ~ 1.f
        float progress = (float)(elapsed - m_start) / (m_end - m_start) ;
        float workEyeX = 0.f;
        float workEyeY = 0.f;
        float workEyeZ = 0.f;
        float workAtX = 0.f;
        float workAtY = 0.f;
        float workAtZ = 0.f;
        workEyeX = m_stCamera.m_startPosX + (m_stCamera.m_endPosX - m_stCamera.m_startPosX) * progress;
        workEyeY = m_stCamera.m_startPosY + (m_stCamera.m_endPosY - m_stCamera.m_startPosY) * progress;
        workEyeZ = m_stCamera.m_startPosZ + (m_stCamera.m_endPosZ - m_stCamera.m_startPosZ) * progress;
        workAtX = m_stCamera.m_startAtX + (m_stCamera.m_endAtX - m_stCamera.m_startAtX) * progress;
        workAtY = m_stCamera.m_startAtY + (m_stCamera.m_endAtY - m_stCamera.m_startAtY) * progress;
        workAtZ = m_stCamera.m_startAtZ + (m_stCamera.m_endAtZ - m_stCamera.m_startAtZ) * progress;
        m_camera->SetPosAndRot(workEyeX, workEyeY, workEyeZ, workAtX, workAtY, workAtZ);
    }
}

void Action::Render()
{
    if (m_eType == eType::CAMERA)
    {
        // do nothing.
    }
}

void Action::Finalize()
{
}
