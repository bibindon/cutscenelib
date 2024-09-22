#include "cutscenelib.h"

void Action::Init(const std::vector<std::string>& scriptLine,
                  IModelCreator* modelCreator,
                  IFont* font,
                  ICamera* camera)
{
    m_font = font;
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
    else if (scriptLine.at(3) == "モデル移動")
    {
        m_eType = eType::MODEL_MOVE;
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
    else if (m_eType == eType::MODEL_POS)
    {
        m_stModelPos.m_model = modelCreator->CreateModel(scriptLine.at(4));
        m_stModelPos.m_subId = std::atoi(scriptLine.at(5).c_str());

        std::vector<std::string> vs;
        vs = split(scriptLine.at(6), ':');
        m_stModelPos.m_PosX = (float)std::atof(vs.at(0).c_str());
        m_stModelPos.m_PosY = (float)std::atof(vs.at(1).c_str());
        m_stModelPos.m_PosZ = (float)std::atof(vs.at(2).c_str());

        vs = split(scriptLine.at(7), ':');
        m_stModelPos.m_RotX = (float)std::atof(vs.at(0).c_str());
        m_stModelPos.m_RotY = (float)std::atof(vs.at(1).c_str());
        m_stModelPos.m_RotZ = (float)std::atof(vs.at(2).c_str());
    }
    else if (m_eType == eType::MODEL_MOVE)
    {
        m_stModelMove.m_model = modelCreator->CreateModel(scriptLine.at(4));
        m_stModelMove.m_subId = std::atoi(scriptLine.at(5).c_str());

        std::vector<std::string> vs;
        vs = split(scriptLine.at(6), ':');
        m_stModelMove.m_startPosX = (float)std::atof(vs.at(0).c_str());
        m_stModelMove.m_startPosY = (float)std::atof(vs.at(1).c_str());
        m_stModelMove.m_startPosZ = (float)std::atof(vs.at(2).c_str());

        vs = split(scriptLine.at(7), ':');
        m_stModelMove.m_startRotX = (float)std::atof(vs.at(0).c_str());
        m_stModelMove.m_startRotY = (float)std::atof(vs.at(1).c_str());
        m_stModelMove.m_startRotZ = (float)std::atof(vs.at(2).c_str());

        vs = split(scriptLine.at(8), ':');
        m_stModelMove.m_endPosX = (float)std::atof(vs.at(0).c_str());
        m_stModelMove.m_endPosY = (float)std::atof(vs.at(1).c_str());
        m_stModelMove.m_endPosZ = (float)std::atof(vs.at(2).c_str());

        vs = split(scriptLine.at(9), ':');
        m_stModelMove.m_endRotX = (float)std::atof(vs.at(0).c_str());
        m_stModelMove.m_endRotY = (float)std::atof(vs.at(1).c_str());
        m_stModelMove.m_endRotZ = (float)std::atof(vs.at(2).c_str());
    }
    else if (m_eType == eType::MODEL_ANIM)
    {
        m_stModelAnim.m_model = modelCreator->CreateModel(scriptLine.at(4));
        m_stModelAnim.m_subId = std::atoi(scriptLine.at(5).c_str());
        m_stModelAnim.m_animName = scriptLine.at(6).c_str();
    }
    else if (m_eType == eType::TEXT)
    {
        std::vector<std::string> vs = split(scriptLine.at(4), '\n');
        m_stText.m_text = vs;
    }
}

void Action::Update(const int elapsed)
{
//    std::string work = std::to_string(elapsed);
//    work += "\n";
//    OutputDebugString(work.c_str());

    if (m_end != -1)
    {
        if (elapsed < m_start || m_end <= elapsed) {
            return;
        }
    }
    else
    {
        if (elapsed < m_start) {
            return;
        }
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
    else if (m_eType == eType::MODEL_POS)
    {
        if (m_stModelPos.m_Done == false)
        {
            m_stModelPos.m_Done = true;
            m_stModelPos.m_model->SetPosAndRot(m_stModelPos.m_PosX,
                                               m_stModelPos.m_PosY,
                                               m_stModelPos.m_PosZ,
                                               m_stModelPos.m_RotX,
                                               m_stModelPos.m_RotY,
                                               m_stModelPos.m_RotZ);
        }
    }
    else if (m_eType == eType::MODEL_MOVE)
    {
        float progress = (float)(elapsed - m_start) / (m_end - m_start) ;
        float workPosX = 0.f;
        float workPosY = 0.f;
        float workPosZ = 0.f;
        float workRotX = 0.f;
        float workRotY = 0.f;
        float workRotZ = 0.f;
        workPosX = m_stModelMove.m_startPosX + (m_stModelMove.m_endPosX - m_stModelMove.m_startPosX) * progress;
        workPosY = m_stModelMove.m_startPosY + (m_stModelMove.m_endPosY - m_stModelMove.m_startPosY) * progress;
        workPosZ = m_stModelMove.m_startPosZ + (m_stModelMove.m_endPosZ - m_stModelMove.m_startPosZ) * progress;
        workRotX = m_stModelMove.m_startRotX + (m_stModelMove.m_endRotX - m_stModelMove.m_startRotX) * progress;
        workRotY = m_stModelMove.m_startRotY + (m_stModelMove.m_endRotY - m_stModelMove.m_startRotY) * progress;
        workRotZ = m_stModelMove.m_startRotZ + (m_stModelMove.m_endRotZ - m_stModelMove.m_startRotZ) * progress;
        m_stModelMove.m_model->SetPosAndRot(workPosX, workPosY, workPosZ,
                                            workRotX, workRotY, workRotZ);
    }
    else if (m_eType == eType::MODEL_ANIM)
    {
        if (m_stModelAnim.m_Done == false)
        {
            m_stModelAnim.m_Done = true;
            m_stModelAnim.m_model->SetAnim(m_stModelAnim.m_animName);
        }
    }
    else if (m_eType == eType::TEXT)
    {
        // TODO 文字送り
    }
}

void Action::Render(const int elapsed)
{
    if (m_end != -1)
    {
        if (elapsed < m_start || m_end <= elapsed) {
            return;
        }
    }
    else
    {
        if (elapsed < m_start) {
            return;
        }
    }
    if (m_eType == eType::CAMERA)
    {
        // do nothing.
    }
    else if(m_eType == eType::MODEL_POS)
    {
        // do nothing
    }
    else if(m_eType == eType::MODEL_MOVE)
    {
        // do nothing
    }
    else if(m_eType == eType::MODEL_ANIM)
    {
        // do nothing
    }
    else if (m_eType == eType::TEXT)
    {
        if (m_stText.m_text.size() >= 1)
        {
            m_font->DrawText_(m_stText.m_text.at(0), 100, 730);
        }

        if (m_stText.m_text.size() >= 2)
        {
            m_font->DrawText_(m_stText.m_text.at(1), 100, 780);
        }

        if (m_stText.m_text.size() >= 3)
        {
            m_font->DrawText_(m_stText.m_text.at(2), 100, 830);
        }
    }
}

void Action::Finalize()
{
}

