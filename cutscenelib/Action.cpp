﻿#include "cutscenelib.h"

#include <tchar.h>

using namespace NSCutScenelib;

void Action::Init(const std::vector<std::wstring>& scriptLine,
                  IModelCreator* modelCreator,
                  IFont* font,
                  ISprite* sprTextBack,
                  ISoundEffect* SE,
                  ICamera* camera)
{
    m_font = font;
    m_sprTextBack = sprTextBack;
    m_SE = SE;
    m_camera = camera;

    m_id    = std::stoi(scriptLine.at(0).c_str());
    m_start = std::stoi(scriptLine.at(1).c_str());
    m_end   = std::stoi(scriptLine.at(2).c_str());

    if (scriptLine.at(3) == _T("カメラ"))
    {
        m_eType = eType::CAMERA;
    }
    else if (scriptLine.at(3) == _T("モデル位置"))
    {
        m_eType = eType::MODEL_POS;
    }
    else if (scriptLine.at(3) == _T("モデル移動"))
    {
        m_eType = eType::MODEL_MOVE;
    }
    else if (scriptLine.at(3) == _T("モデルアニメ"))
    {
        m_eType = eType::MODEL_ANIM;
    }
    else if (scriptLine.at(3) == _T("テキスト"))
    {
        m_eType = eType::TEXT;
    }
    else if (scriptLine.at(3) == _T("効果音"))
    {
        m_eType = eType::SE;
    }

    if (m_eType == eType::CAMERA)
    {
        std::vector<std::wstring> vs;
        vs = split(scriptLine.at(4), ':');
        m_stCamera.m_startPosX = (float)std::stof(vs.at(0).c_str());
        m_stCamera.m_startPosY = (float)std::stof(vs.at(1).c_str());
        m_stCamera.m_startPosZ = (float)std::stof(vs.at(2).c_str());

        vs = split(scriptLine.at(5), ':');
        m_stCamera.m_startAtX = (float)std::stof(vs.at(0).c_str());
        m_stCamera.m_startAtY = (float)std::stof(vs.at(1).c_str());
        m_stCamera.m_startAtZ = (float)std::stof(vs.at(2).c_str());

        vs = split(scriptLine.at(6), ':');
        m_stCamera.m_endPosX = (float)std::stof(vs.at(0).c_str());
        m_stCamera.m_endPosY = (float)std::stof(vs.at(1).c_str());
        m_stCamera.m_endPosZ = (float)std::stof(vs.at(2).c_str());

        vs = split(scriptLine.at(7), ':');
        m_stCamera.m_endAtX = (float)std::stof(vs.at(0).c_str());
        m_stCamera.m_endAtY = (float)std::stof(vs.at(1).c_str());
        m_stCamera.m_endAtZ = (float)std::stof(vs.at(2).c_str());
    }
    else if (m_eType == eType::MODEL_POS)
    {
        m_stModelPos.m_XFileName = scriptLine.at(4);
        m_stModelPos.m_subId     = std::stoi(scriptLine.at(5).c_str());
        m_stModelPos.m_model     = modelCreator->CreateModel(m_stModelPos.m_XFileName,
                                                             m_stModelPos.m_subId);

        std::vector<std::wstring> vs;
        vs = split(scriptLine.at(6), ':');
        m_stModelPos.m_PosX = (float)std::stof(vs.at(0).c_str());
        m_stModelPos.m_PosY = (float)std::stof(vs.at(1).c_str());
        m_stModelPos.m_PosZ = (float)std::stof(vs.at(2).c_str());

        vs = split(scriptLine.at(7), ':');
        m_stModelPos.m_RotX = (float)std::stof(vs.at(0).c_str());
        m_stModelPos.m_RotY = (float)std::stof(vs.at(1).c_str());
        m_stModelPos.m_RotZ = (float)std::stof(vs.at(2).c_str());
    }
    else if (m_eType == eType::MODEL_MOVE)
    {
        m_stModelMove.m_XFileName = scriptLine.at(4);
        m_stModelMove.m_subId     = std::stoi(scriptLine.at(5).c_str());
        m_stModelMove.m_model     = modelCreator->CreateModel(m_stModelMove.m_XFileName,
                                                              m_stModelMove.m_subId);

        std::vector<std::wstring> vs;
        vs = split(scriptLine.at(6), ':');
        m_stModelMove.m_startPosX = (float)std::stof(vs.at(0).c_str());
        m_stModelMove.m_startPosY = (float)std::stof(vs.at(1).c_str());
        m_stModelMove.m_startPosZ = (float)std::stof(vs.at(2).c_str());

        vs = split(scriptLine.at(7), ':');
        m_stModelMove.m_startRotX = (float)std::stof(vs.at(0).c_str());
        m_stModelMove.m_startRotY = (float)std::stof(vs.at(1).c_str());
        m_stModelMove.m_startRotZ = (float)std::stof(vs.at(2).c_str());

        vs = split(scriptLine.at(8), ':');
        m_stModelMove.m_endPosX = (float)std::stof(vs.at(0).c_str());
        m_stModelMove.m_endPosY = (float)std::stof(vs.at(1).c_str());
        m_stModelMove.m_endPosZ = (float)std::stof(vs.at(2).c_str());

        vs = split(scriptLine.at(9), ':');
        m_stModelMove.m_endRotX = (float)std::stof(vs.at(0).c_str());
        m_stModelMove.m_endRotY = (float)std::stof(vs.at(1).c_str());
        m_stModelMove.m_endRotZ = (float)std::stof(vs.at(2).c_str());
    }
    else if (m_eType == eType::MODEL_ANIM)
    {
        m_stModelAnim.m_XFileName = scriptLine.at(4);
        m_stModelAnim.m_subId     = std::stoi(scriptLine.at(5).c_str());
        m_stModelAnim.m_animName  = scriptLine.at(6).c_str();
        m_stModelAnim.m_model     = modelCreator->CreateModel(m_stModelAnim.m_XFileName,
                                                              m_stModelAnim.m_subId);
    }
    else if (m_eType == eType::TEXT)
    {
        std::wstring work = scriptLine.at(4);
        work.erase(remove(work.begin(), work.end(), '\"'), work.end());
        std::vector<std::wstring> vs = split(work, '\n');
        m_stText.m_text = vs;
        m_stText.m_textShow.resize(3);
    }
    else if (m_eType == eType::SE)
    {
        m_stSE.m_fileName = scriptLine.at(4);
        m_stSE.m_volume = std::stoi(scriptLine.at(5).c_str());
        if (scriptLine.at(6) == _T("LOOP"))
        {
            m_stSE.m_loop = true;
        }
    }
}

bool Action::Update(const int elapsed)
{
    bool finish = true;
    if (elapsed < m_start)
    {
        return false;
    }

    if (m_eType == eType::CAMERA)
    {
        if (elapsed < m_end)
        {
            finish = false;
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
    else if (m_eType == eType::MODEL_POS)
    {
        if (m_stModelPos.m_Done == false)
        {
            finish = false;
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
        if (elapsed < m_end)
        {
            finish = false;
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
    }
    else if (m_eType == eType::MODEL_ANIM)
    {
        if (elapsed < m_end)
        {
            finish = false;
            if (m_stModelAnim.m_Done == false)
            {
                m_stModelAnim.m_Done = true;
                m_stModelAnim.m_model->SetAnim(m_stModelAnim.m_animName);
            }
        }
    }
    else if (m_eType == eType::TEXT)
    {
        if (elapsed < m_end)
        {
            finish = false;
            // 30フレーム経過してから文字の表示を始める

            // 文字送り処理
            m_stText.m_textShow.at(0).clear();
            m_stText.m_textShow.at(1).clear();
            m_stText.m_textShow.at(2).clear();
            m_stText.m_counter++;
            if (m_stText.m_counter >= 30)
            {
                m_stText.m_charCount++;
            }

            // 一行目
            if (m_stText.m_charCount < (int)m_stText.m_text.at(0).size())
            {
                // マルチバイト文字は1文字で2バイトであることを考慮する
                if (m_stText.m_charCount % 2 == 0)
                {
                    m_stText.m_textShow.at(0) = m_stText.m_text.at(0).substr(0, m_stText.m_charCount);
                }
                else
                {
                    m_stText.m_textShow.at(0) = m_stText.m_text.at(0).substr(0, m_stText.m_charCount - 1);
                }
            }
            else
            {
                m_stText.m_textShow.at(0) = m_stText.m_text.at(0);
            }

            size_t total = 0;

            // 二行目
            total = m_stText.m_text.at(0).size() + m_stText.m_text.at(1).size();
            size_t secondLineCount = m_stText.m_charCount - m_stText.m_text.at(0).size();
            if (m_stText.m_charCount < total)
            {
                if (secondLineCount >= 0)
                {
                    // マルチバイト文字は1文字で2バイトであることを考慮する
                    if (secondLineCount % 2 == 0)
                    {
                        m_stText.m_textShow.at(1) = m_stText.m_text.at(1).substr(0, secondLineCount);
                    }
                    else
                    {
                        m_stText.m_textShow.at(1) = m_stText.m_text.at(1).substr(0, secondLineCount - 1);
                    }
                }
            }
            else
            {
                m_stText.m_textShow.at(1) = m_stText.m_text.at(1);
            }

            // 三行目
            total = m_stText.m_text.at(0).size() + m_stText.m_text.at(1).size()
                                                 + m_stText.m_text.at(2).size();

            size_t thirdLineCount = m_stText.m_charCount - m_stText.m_text.at(0).size()
                                                         - m_stText.m_text.at(1).size();
            if (m_stText.m_charCount < total)
            {
                if (thirdLineCount >= 0)
                {
                    // マルチバイト文字は1文字で2バイトであることを考慮する
                    if (thirdLineCount % 2 == 0)
                    {
                        m_stText.m_textShow.at(2) = m_stText.m_text.at(2).substr(0, thirdLineCount);
                    }
                    else
                    {
                        m_stText.m_textShow.at(2) = m_stText.m_text.at(2).substr(0, thirdLineCount - 1);
                    }
                }
            }
            else
            {
                m_stText.m_textShow.at(2) = m_stText.m_text.at(2);
            }
        }
    }
    else if (m_eType == eType::SE)
    {
        if (m_stSE.m_Stopped == false)
        {
            finish = false;
        }
    }
    return finish;
}

void Action::Render(const int elapsed)
{
    if (elapsed < m_start) {
        return;
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
        if (elapsed < m_end)
        {
            m_sprTextBack->DrawImage(0, 0);
            if (m_stText.m_textShow.size() >= 1)
            {
                m_font->DrawText_(m_stText.m_textShow.at(0), 100, 730);
            }

            if (m_stText.m_textShow.size() >= 2)
            {
                m_font->DrawText_(m_stText.m_textShow.at(1), 100, 780);
            }

            if (m_stText.m_textShow.size() >= 3)
            {
                m_font->DrawText_(m_stText.m_textShow.at(2), 100, 830);
            }
        }
    }
    else if(m_eType == eType::SE)
    {
        if (elapsed < m_end)
        {
            if (m_stSE.m_Started == false)
            {
                m_stSE.m_Started = true;
                m_SE->Play(m_stSE.m_fileName, m_stSE.m_volume, m_stSE.m_loop);
            }
        }
        else
        {
            if (m_stSE.m_Stopped == false)
            {
                m_stSE.m_Stopped = true;
                m_SE->Stop();
            }
        }
    }
}

void Action::Finalize()
{
    delete m_stModelPos.m_model;
    m_stModelPos.m_model = nullptr;

    delete m_stModelMove.m_model;
    m_stModelMove.m_model = nullptr;

    delete m_stModelAnim.m_model;
    m_stModelAnim.m_model = nullptr;

}

