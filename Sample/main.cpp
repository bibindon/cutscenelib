#pragma comment(lib, "d3d9.lib")
#ifdef _DEBUG
#pragma comment(lib, "d3dx9d.lib")
#else
#pragma comment(lib, "d3dx9.lib")
#endif

#pragma comment(lib, "cutscenelib.lib")

#pragma comment (lib, "winmm.lib")

#include "Common.h"
#include "Mesh.h"
#include "AnimMesh.h"

#include "..\cutscenelib\cutscenelib.h"

#include <windows.h>
#include <string>
#include <d3dx9.h>

const std::string   TITLE = "simple anim mesh";
LPDIRECT3DDEVICE9   g_D3DDevice;
LPDIRECT3D9         g_D3D;
Mesh*               g_Mesh { nullptr };
AnimMesh*           g_AnimMesh = { nullptr };

const D3DXVECTOR3   UPWARD { 0.0f, 1.0f, 0.0f };
D3DXVECTOR3         g_eyePos { 4.0f, 4.0f, 4.0f };
D3DXVECTOR3         g_lookAtPos { 0.0f, 1.0f, 0.0f };
float               g_viewAngle { D3DX_PI / 4 };
float               g_radian { D3DX_PI * 3 / 4 };

CutScene*               g_talk = nullptr;

class Sprite : public ISprite
{
public:

    Sprite(LPDIRECT3DDEVICE9 dev)
        : m_pD3DDevice(dev)
    {
    }

    void DrawImage(const int x, const int y, const int transparency) override
    {
        D3DXVECTOR3 pos { (float)x, (float)y, 0.f };
        m_D3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
        RECT rect = {
            0,
            0,
            static_cast<LONG>(m_width),
            static_cast<LONG>(m_height) };
        D3DXVECTOR3 center { 0, 0, 0 };
        m_D3DSprite->Draw(
            m_pD3DTexture,
            &rect,
            &center,
            &pos,
            D3DCOLOR_ARGB(transparency, 255, 255, 255));
        m_D3DSprite->End();

    }

    void Load(const std::string& filepath) override
    {
        LPD3DXSPRITE tempSprite { nullptr };
        if (FAILED(D3DXCreateSprite(m_pD3DDevice, &m_D3DSprite)))
        {
            throw std::exception("Failed to create a sprite.");
        }

        if (FAILED(D3DXCreateTextureFromFile(
            m_pD3DDevice,
            filepath.c_str(),
            &m_pD3DTexture)))
        {
            throw std::exception("Failed to create a texture.");
        }

        D3DSURFACE_DESC desc { };
        if (FAILED(m_pD3DTexture->GetLevelDesc(0, &desc)))
        {
            throw std::exception("Failed to create a texture.");
        }
        m_width = desc.Width;
        m_height = desc.Height;
    }

    ~Sprite()
    {
        m_D3DSprite->Release();
        m_D3DSprite = nullptr;
        m_pD3DTexture->Release();
        m_pD3DTexture = nullptr;
    }

private:

    LPDIRECT3DDEVICE9 m_pD3DDevice = NULL;
    LPD3DXSPRITE m_D3DSprite = NULL;
    LPDIRECT3DTEXTURE9 m_pD3DTexture = NULL;
    UINT m_width { 0 };
    UINT m_height { 0 };
};

class Font : public IFont
{
public:

    Font(LPDIRECT3DDEVICE9 pD3DDevice)
        : m_pD3DDevice(pD3DDevice)
    {
    }

    void Init()
    {
        HRESULT hr = D3DXCreateFont(
            m_pD3DDevice,
            24,
            0,
            FW_NORMAL,
            1,
            false,
            SHIFTJIS_CHARSET,
            OUT_TT_ONLY_PRECIS,
            ANTIALIASED_QUALITY,
            FF_DONTCARE,
            "ÇlÇr ñæí©",
            &m_pFont);
    }

    virtual void DrawText_(const std::string& msg, const int x, const int y)
    {
        RECT rect = { x, y, 0, 0 };
        m_pFont->DrawText(NULL, msg.c_str(), -1, &rect, DT_LEFT | DT_NOCLIP,
            D3DCOLOR_ARGB(255, 255, 255, 255));
    }

    ~Font()
    {
        m_pFont->Release();
        m_pFont = nullptr;
    }

private:

    LPDIRECT3DDEVICE9 m_pD3DDevice = NULL;
    LPD3DXFONT m_pFont = NULL;
};


class SoundEffect : public ISoundEffect
{
    virtual void PlayMove() override
    {
        PlaySound("cursor_move.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    virtual void Init() override
    {

    }
};

class Camera : public ICamera
{
public:

    virtual void SetPosAndRot(const float posX, const float posY, const float posZ,
                              const float AtX, const float AtY, const float AtZ)
    {
        g_eyePos    = D3DXVECTOR3(posX, posY, posZ);
        g_lookAtPos = D3DXVECTOR3(AtX, AtY, AtZ);
    }

};

class Model : public IModel
{
public:
    Model(const D3DXVECTOR3& startEye, const D3DXVECTOR3& startAt,
          const D3DXVECTOR3& endEye,   const D3DXVECTOR3& endAt)
        : m_startEye(startEye), m_startAt(startAt)
        , m_endEye(endEye),     m_endAt(endAt)
    {
    }

    // progressÇÕ 0 ~ 100Ç™ó^Ç¶ÇÁÇÍÇÈÅB
    virtual void SetPosAndRot(const int progress)
    {
//        g_eyePos = m_startEye;
//        g_lookAtPos = m_startAt;
    }

private:

    D3DXVECTOR3 m_startEye;
    D3DXVECTOR3 m_startAt;
    D3DXVECTOR3 m_endEye;
    D3DXVECTOR3 m_endAt;
};

D3DXMATRIX GetViewMatrix()
{
    D3DXMATRIX viewMatrix { };
    D3DXMatrixLookAtLH(&viewMatrix, &g_eyePos, &g_lookAtPos, &UPWARD);
    return viewMatrix;
}

D3DXMATRIX GetProjMatrix()
{
    D3DXMATRIX projection_matrix { };
    D3DXMatrixPerspectiveFovLH(&projection_matrix,
                               g_viewAngle,
                               static_cast<float>(1600) / 900,
                               0.1f,
                               500.0f);
    return projection_matrix;
}

void Update()
{
    //g_radian += 1/100.f;
    //g_eyePos.x = g_lookAtPos.x + std::sin(g_radian)*4;
    //g_eyePos.z = g_lookAtPos.z + std::cos(g_radian)*4;
}

void StartCutScene()
{
    ISoundEffect* pSE = new SoundEffect();
    Sprite* sprTextBack = new Sprite(g_D3DDevice);
    Sprite* sprFade = new Sprite(g_D3DDevice);
    IFont* pFont = new Font(g_D3DDevice);
    ICamera* pCamera = new Camera();

    if (g_talk != nullptr)
    {
        g_talk->Finalize();
        delete g_talk;
        g_talk = nullptr;
    }
    g_talk = new CutScene();
    g_talk->Init("cutsceneSample.csv", pFont, pSE, sprTextBack, sprFade, pCamera,
                 g_eyePos.x,    g_eyePos.y,    g_eyePos.z,
                 g_lookAtPos.x, g_lookAtPos.y, g_lookAtPos.z);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case 'Q':
        {
            PostQuitMessage(0);
            break;
        }
        case 'M':
        {
            StartCutScene();
            break;
        }
        }
    }
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

void Init(const HINSTANCE& hInstance)
{
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX),
                        CS_HREDRAW | CS_VREDRAW,
                        WndProc,
                        0,
                        0,
                        hInstance,
                        NULL,
                        NULL,
                        (HBRUSH)(COLOR_WINDOW + 1),
                        NULL,
                        TITLE.c_str(), NULL
    };

    if (!RegisterClassEx(&wcex))
    {
        throw std::exception("");
    }

    RECT rect;
    SetRect(&rect, 0, 0, 1600, 900);
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
    rect.right = rect.right - rect.left;
    rect.bottom = rect.bottom - rect.top;
    rect.top = 0;
    rect.left = 0;

    HWND hWnd = CreateWindow(TITLE.c_str(),
                             TITLE.c_str(),
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT,
                             CW_USEDEFAULT,
                             rect.right,
                             rect.bottom,
                             NULL,
                             NULL,
                             hInstance,
                             NULL);

    if (hWnd == nullptr)
    {
        throw std::exception("");
    }

    if (!(g_D3D = Direct3DCreate9(D3D_SDK_VERSION)))
    {
        throw std::exception("");
    }

    D3DPRESENT_PARAMETERS d3dpp = { 0,
                                    0,
                                    D3DFMT_UNKNOWN,
                                    0,
                                    D3DMULTISAMPLE_NONE,
                                    0,
                                    D3DSWAPEFFECT_DISCARD,
                                    NULL,
                                    TRUE,
                                    TRUE,
                                    D3DFMT_D24S8,
                                    0,
                                    D3DPRESENT_RATE_DEFAULT,
                                    D3DPRESENT_INTERVAL_DEFAULT };

    LPDIRECT3DDEVICE9 D3DDevice = nullptr;
    if (FAILED(g_D3D->CreateDevice(D3DADAPTER_DEFAULT,
                                   D3DDEVTYPE_HAL,
                                   hWnd,
                                   D3DCREATE_HARDWARE_VERTEXPROCESSING,
                                   &d3dpp,
                                   &D3DDevice)))
    {
        if (FAILED(g_D3D->CreateDevice(D3DADAPTER_DEFAULT,
                                       D3DDEVTYPE_HAL,
                                       hWnd,
                                       D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                       &d3dpp,
                                       &D3DDevice)))
        {
            g_D3D->Release();
            throw std::exception("");
        }
    }
    g_D3DDevice = D3DDevice;

    g_Mesh = new Mesh(g_D3DDevice,
                      "tiger.x",
                      D3DXVECTOR3(3, 1, 0),
                      D3DXVECTOR3(0, 0, 0),
                      1.0f);
    g_AnimMesh = new AnimMesh(g_D3DDevice,
                              "hoshiman.x",
                              D3DXVECTOR3(0, 0, 0),
                              D3DXVECTOR3(0, 0, 0),
                              0.5f);

    ShowWindow(hWnd, SW_SHOW);
}

void Finalize()
{
    SAFE_DELETE(g_Mesh);
    SAFE_DELETE(g_AnimMesh);
    SAFE_RELEASE(g_D3DDevice);
    SAFE_RELEASE(g_D3D);
    g_talk->Finalize();
    SAFE_DELETE(g_talk);
}

int MainLoop()
{
    MSG msg;

    do
    {
        Sleep(1);
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            DispatchMessage(&msg);
        }

        Update();

        if (g_talk != nullptr)
        {
            bool finish = g_talk->Update();
            if (finish)
            {
                g_talk->Finalize();
                SAFE_DELETE(g_talk);
            }
        }

        g_AnimMesh->Update();

        g_D3DDevice->Clear(0,
                           NULL,
                           D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
                           D3DCOLOR_XRGB(40, 40, 80),
                           1.0f,
                           0);
        g_D3DDevice->BeginScene();

        g_Mesh->Render(GetViewMatrix(), GetProjMatrix());
        g_AnimMesh->Render(GetViewMatrix(), GetProjMatrix());

        if (g_talk != nullptr)
        {
            g_talk->Render();
        }

        g_D3DDevice->EndScene();
        g_D3DDevice->Present(NULL, NULL, NULL, NULL);

    } while (msg.message != WM_QUIT);

    return 0;
}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE, _In_ LPSTR, _In_ int)
{
    Init(hInstance);
    MainLoop();
    Finalize();
    return 0;
}

