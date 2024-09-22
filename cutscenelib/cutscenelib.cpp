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
    IModelCreator* modelCreator,
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
    m_modelCreator = modelCreator;
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

    for (std::size_t i = 0; i < m_actionList.size(); ++i)
    {
        m_actionList.at(i).Update(duration);
    }
    return false;
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
}

void CutScene::Finalize()
{
    if (m_camera != nullptr)
    {
        m_camera->SetPosAndRot(m_restoreEyeX,    m_restoreEyeY,    m_restoreEyeZ,
                               m_restoreLookAtX, m_restoreLookAtY, m_restoreEyeZ);
    }

    delete m_sprTextBack;
    m_sprTextBack = nullptr;

    delete m_sprFade;
    m_sprFade = nullptr;

    delete m_font;
    m_font = nullptr;

    delete m_SE;
    m_SE = nullptr;
}

