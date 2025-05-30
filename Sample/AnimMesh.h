﻿#pragma once

#include "AnimMeshAlloc.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <tchar.h>

class AnimMesh
{

public:

    AnimMesh(const LPDIRECT3DDEVICE9 D3DDevice,
             const std::wstring&,
             const D3DXVECTOR3&,
             const D3DXVECTOR3&,
             const float&);

    ~AnimMesh();
    void Render(const D3DXMATRIX& view, const D3DXMATRIX& proj);
    void SetPos(const D3DXVECTOR3& pos);
    void SetRotate(const D3DXVECTOR3& rotate);

    void Update();
    void SetAnim(const std::wstring& animationSet);
    void SetDefaultAnim(const std::wstring& animationName);
    void SetAnimConfig(const std::wstring& animationName,
                       const bool loop,
                       const float startPos,
                       const float duration);
    bool isPlaying();
private:

    void UpdateFrameMatrix(const LPD3DXFRAME, const LPD3DXMATRIX);
    void RenderFrame(const LPD3DXFRAME);
    void RenderMeshContainer(const LPD3DXMESHCONTAINER, const LPD3DXFRAME);
    void ReleaseMeshAllocator(const LPD3DXFRAME);

    const std::wstring SHADER_FILENAME = _T("animMeshShader.fx");
    std::wstring m_meshName;

    LPD3DXEFFECT m_D3DEffect = nullptr;

    AnimMeshAllocator* m_allocator = nullptr;
    D3DXFRAME* m_frameRoot = nullptr;

    D3DXMATRIX m_viewMatrix { };
    D3DXMATRIX m_projMatrix { };

    D3DXVECTOR3 m_centerPos { 0.f, 0.f, 0.f };
    D3DXVECTOR3 m_position { 0.f, 0.f, 0.f };
    D3DXVECTOR3 m_rotation { 0.f, 0.f, 0.f };
    float m_scale = 1.0f;

    //-------------------------------------------------------
    // LPD3DXANIMATIONCONTROLLER関連
    //-------------------------------------------------------
    bool m_isPlaying = false;
    std::vector<LPD3DXANIMATIONSET> m_animSets;
    LPD3DXANIMATIONCONTROLLER m_D3DAnimController = nullptr;
    std::wstring m_defaultAnim;
    float m_animTime = 0.f;
    std::wstring m_currentAnim;

    struct AnimConfig
    {
        bool loop = true;
        float startPos = 0.0f;
        float duration = 1.0f;
    };
    std::unordered_map<std::wstring, AnimConfig> m_animConfigMap;
};

