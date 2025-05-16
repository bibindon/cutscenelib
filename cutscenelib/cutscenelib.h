// CSVファイル読み込みは保留。このクラスを使う機会が3回くらいしかないなら、作っても意味ない。
#pragma once
#include <string>
#include <vector>
#include <chrono>

namespace NSCutScenelib
{
class ISprite
{
public:
    virtual void DrawImage(const int x, const int y, const int transparency = 255) = 0;
    virtual void Load(const std::wstring& filepath) = 0;
    virtual ~ISprite() {};
};

class IFont
{
public:
    virtual void DrawText_(const std::wstring& msg, const int x, const int y) = 0;
    virtual void Init(const bool bEnglish) = 0;
    virtual ~IFont() {};
};

class ISoundEffect
{
public:
    virtual void Play(const std::wstring& filename, const int volume = 100, const bool loop = false) = 0;
    virtual void Stop() = 0;
    virtual void Init() = 0;
    virtual ~ISoundEffect() {};
};

class ICamera
{
public:
    virtual void SetPosAndRot(const float posX, const float posY, const float posZ,
                              const float AtX,  const float AtY,  const float AtZ) = 0;
    virtual ~ICamera() {};
};

class IModel
{
public:
    virtual void SetPosAndRot(const float posX, const float posY, const float posZ,
                              const float AtX,  const float AtY,  const float AtZ) = 0;
    virtual void SetAnim(const std::wstring& animName) = 0;
    virtual ~IModel() {};
};

class IModelCreator
{
public:
    virtual IModel* CreateModel(const std::wstring& xfilename, const int subId) = 0;
};

class Action
{
public:
    void Init(const std::vector<std::wstring>& scriptLine,
              IModelCreator* modelCreator,
              IFont* font,
              ISprite* sprTextBack,
              ISoundEffect* SE,
              ICamera* camera);
    bool Update(const int elapsed);
    void Render(const int elapsed);
    void Finalize();

private:
    enum class eType
    {
        CAMERA,
        MODEL_POS,
        MODEL_MOVE,
        MODEL_ANIM,
        TEXT,
        SE,
    };
    eType m_eType = eType::CAMERA;

    int m_id = 0;
    int m_start = 0;
    int m_end = 0;

    struct stCamera
    {
        float m_startPosX = 0.f;
        float m_startPosY = 0.f;
        float m_startPosZ = 0.f;
        float m_startAtX = 0.f;
        float m_startAtY = 0.f;
        float m_startAtZ = 0.f;

        float m_endPosX = 0.f;
        float m_endPosY = 0.f;
        float m_endPosZ = 0.f;
        float m_endAtX = 0.f;
        float m_endAtY = 0.f;
        float m_endAtZ = 0.f;
    };

    struct stModelPos
    {
        std::wstring m_XFileName;
        IModel* m_model = nullptr;
        int m_subId = 0;

        float m_PosX = 0.f;
        float m_PosY = 0.f;
        float m_PosZ = 0.f;
        float m_RotX = 0.f;
        float m_RotY = 0.f;
        float m_RotZ = 0.f;

        bool m_Done = false;
    };

    struct stModelMove
    {
        std::wstring m_XFileName;
        IModel* m_model = nullptr;
        int m_subId = 0;

        float m_startPosX = 0.f;
        float m_startPosY = 0.f;
        float m_startPosZ = 0.f;
        float m_startRotX = 0.f;
        float m_startRotY = 0.f;
        float m_startRotZ = 0.f;

        float m_endPosX = 0.f;
        float m_endPosY = 0.f;
        float m_endPosZ = 0.f;
        float m_endRotX = 0.f;
        float m_endRotY = 0.f;
        float m_endRotZ = 0.f;
    };

    struct stModelAnim
    {
        std::wstring m_XFileName;
        IModel*     m_model     = nullptr;
        int         m_subId     = 0;
        std::wstring m_animName;
        bool        m_Done      = false;
    };

    struct stText
    {
        std::vector<std::wstring> m_text;

        // 表示されている文字（文字送り演出用）
        std::vector<std::wstring> m_textShow;

        // 表示されている文字数（文字送り演出用）
        size_t m_charCount = 0;

        int m_counter = 0;
    };

    struct stSE
    {
        std::wstring m_fileName;
        int m_volume = 0;
        bool m_loop = false;
        bool m_Started = false;
        bool m_Stopped = false;
    };

    stCamera m_stCamera;
    stModelPos m_stModelPos;
    stModelMove m_stModelMove;
    stModelAnim m_stModelAnim;
    stText m_stText;
    stSE m_stSE;

    IFont* m_font = nullptr;
    ISprite* m_sprTextBack = nullptr;
    ISoundEffect* m_SE = nullptr;
    ICamera* m_camera = nullptr;
};

class CutScene
{
public:

    void Init(const std::wstring& csvfilepath,
              IFont* font,
              ISoundEffect* SE,
              ISprite* sprTextBack,
              ISprite* sprFade,
              IModelCreator* modelCreator,
              ICamera* restore,
              const float eyeX,
              const float eyeY,
              const float eyeZ,
              const float lookAtX,
              const float lookAtY,
              const float lookAtZ,
              const bool bEnglish);

    std::vector<Action> CreateActionList();

    bool Update();
    void Render();

    void Finalize();

private:

    std::chrono::system_clock::time_point m_startTime;
    std::chrono::system_clock::time_point m_currentTime;

    std::wstring m_csvfilepath;
    ISprite* m_sprTextBack = nullptr;
    IFont* m_font = nullptr;
    ISoundEffect* m_SE = nullptr;
    std::vector<Action> m_actionList;
    int m_pageIndex = 0;

    ISprite* m_sprFade = nullptr;
    const int FADE_FRAME_MAX = 30;
    bool m_isFadeIn = false;
    int m_FadeInCount = 0;
    bool m_isFadeOut = false;
    bool m_fadeOutFinish = false;
    int m_FadeOutCount = 0;

    const int WAIT_NEXT_FRAME = 60;
    int m_waitNextCount = 0;

    IModelCreator* m_modelCreator = nullptr;
    ICamera* m_camera = nullptr;

    float m_restoreEyeX    = 0.f;
    float m_restoreEyeY    = 0.f;
    float m_restoreEyeZ    = 0.f;
    float m_restoreLookAtX = 0.f;
    float m_restoreLookAtY = 0.f;
    float m_restoreLookAtZ = 0.f;
};

std::vector<std::wstring> split(const std::wstring& s, wchar_t delim);
}
