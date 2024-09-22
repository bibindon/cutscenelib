// CSVファイル読み込みは保留。このクラスを使う機会が3回くらいしかないなら、作っても意味ない。
#pragma once
#include <string>
#include <vector>
#include <chrono>

class ISprite
{
public:
    virtual void DrawImage(const int x, const int y, const int transparency = 255) = 0;
    virtual void Load(const std::string& filepath) = 0;
    virtual ~ISprite() {};
};

class IFont
{
public:
    virtual void DrawText_(const std::string& msg, const int x, const int y) = 0;
    virtual void Init() = 0;
    virtual ~IFont() {};
};

class ISoundEffect
{
public:
    // TODO PlayMoveではない気がする
    virtual void PlayMove() = 0;
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
    virtual void SetAnim(const std::string& animName) = 0;
    virtual ~IModel() {};
};

class IModelCreator
{
public:
    virtual IModel* CreateModel(const std::string& xfilename) = 0;
};

class Action
{
public:
    void Init(const std::vector<std::string>& scriptLine,
              IModelCreator* modelCreator,
              ICamera* camera);
    void Update(const int elapsed);
    void Render();
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
        std::string m_XFileName;
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
        std::string m_XFileName;
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
        std::string m_XFileName;
        IModel* m_model = nullptr;
        int m_subId = 0;
        std::string m_animName;

        bool m_Done = false;
    };

    struct stText
    {
        std::string m_text;
    };

    struct stSE
    {
        std::string m_fileName;
        int m_volume = 0;
    };

    stCamera m_stCamera;
    stModelPos m_stModelPos;
    stModelMove m_stModelMove;
    stModelAnim m_stModelAnim;
    stText m_stText;
    stSE m_stSE;

    ICamera* m_camera = nullptr;
};

class CutScene
{
public:

    void Init(
        const std::string& csvfilepath,
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
        const float lookAtZ);

    std::vector<Action> CreateActionList();

    bool Update();
    void Render();

    void Finalize();

private:

    std::chrono::system_clock::time_point m_startTime;
    std::chrono::system_clock::time_point m_currentTime;

    std::string m_csvfilepath;
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

std::vector<std::string> split(const std::string& s, char delim);

