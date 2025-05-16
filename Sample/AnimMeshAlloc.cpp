#include "AnimMeshAlloc.h"
#include "Common.h"
#include <tchar.h>

AnimMeshFrame::AnimMeshFrame(const std::string& name)
    : D3DXFRAME { }
{
    Name = new char[name.length() + 1];
    strcpy_s(Name, name.length() + 1, name.c_str());

    D3DXMatrixIdentity(&TransformationMatrix);
    D3DXMatrixIdentity(&m_combinedMatrix);
}

AnimMeshContainer::AnimMeshContainer(const std::string& xFilename,
                                     const std::string& meshName,
                                     LPD3DXMESH d3dMesh,
                                     const D3DXMATERIAL* materials,
                                     const DWORD materialsCount,
                                     const DWORD* adjacency)
    : D3DXMESHCONTAINER { }
{
    Name = new char[meshName.length() + 1];
    strcpy_s(Name, meshName.length() + 1, meshName.c_str());

    LPDIRECT3DDEVICE9 d3dDevice = nullptr;
    d3dMesh->GetDevice(&d3dDevice);

    if (!(d3dMesh->GetFVF() & D3DFVF_NORMAL))
    {
        MeshData.Type = D3DXMESHTYPE_MESH;
        HRESULT result = d3dMesh->CloneMeshFVF(d3dMesh->GetOptions(),
                                               d3dMesh->GetFVF() | D3DFVF_NORMAL,
                                               d3dDevice,
                                               &MeshData.pMesh);

        if (FAILED(result))
        {
            throw std::exception("Failed 'CloneMeshFVF' function.");
        }
        d3dMesh = MeshData.pMesh;
        D3DXComputeNormals(d3dMesh, nullptr);
    }
    else
    {
        MeshData.pMesh = d3dMesh;
        MeshData.Type = D3DXMESHTYPE_MESH;
        d3dMesh->AddRef();
    }

    NumMaterials = (std::max)(1UL, materialsCount);
    pMaterials = new D3DXMATERIAL[NumMaterials];

    DWORD adjacencyCount = d3dMesh->GetNumFaces() * 3;
    pAdjacency = new DWORD[adjacencyCount];

    for (DWORD i { 0 }; i < adjacencyCount; ++i)
    {
        pAdjacency[i] = adjacency[i];
    }

    if (materialsCount > 0)
    {
        for (DWORD i = 0; i < materialsCount; ++i)
        {
            pMaterials[i] = materials[i];
        }

        std::wstring xFileDir;
        {
			int len = MultiByteToWideChar(CP_ACP, 0, xFilename.c_str(), -1, NULL, 0);
			std::wstring texFilename(len, 0);
			MultiByteToWideChar(CP_ACP, 0, xFilename.c_str(), -1, &texFilename[0], len);
			xFileDir = texFilename;
        }

        std::size_t lastPos = xFileDir.find_last_of(_T("\\"));
        xFileDir = xFileDir.substr(0, lastPos + 1);

        for (DWORD i = 0; i < materialsCount; ++i)
        {
            if (pMaterials[i].pTextureFilename != nullptr)
            {
                int len = MultiByteToWideChar(CP_ACP, 0, materials[i].pTextureFilename, -1, NULL, 0);
                std::wstring texFilename(len, 0);
                MultiByteToWideChar(CP_ACP, 0, materials[i].pTextureFilename, -1, &texFilename[0], len);

                std::wstring texPath = xFileDir;
                texPath += texFilename;
                LPDIRECT3DTEXTURE9 tempTexture = nullptr;

                if (FAILED(D3DXCreateTextureFromFile(d3dDevice, texPath.c_str(), &tempTexture)))
                {
                    throw std::exception("texture file is not found.");
                }
                else
                {
                    m_vecTexture.push_back(tempTexture);
                }
            }
        }
    }
    else
    {
        pMaterials[0].MatD3D.Diffuse = D3DCOLORVALUE { 0.5f, 0.5f, 0.5f, 0.5f };
        pMaterials[0].MatD3D.Ambient = D3DCOLORVALUE { 0.5f, 0.5f, 0.5f, 0.5f };
        pMaterials[0].MatD3D.Specular = D3DCOLORVALUE { 0.5f, 0.5f, 0.5f, 0.5f };
    }
}

AnimMeshAllocator::AnimMeshAllocator(const std::wstring& xFilename)
    : ID3DXAllocateHierarchy { },
    m_xFilename()
{
    int size = WideCharToMultiByte(CP_UTF8, 0, xFilename.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string result(size - 1, 0);
    WideCharToMultiByte(CP_UTF8, 0, xFilename.c_str(), -1, &result[0], size, nullptr, nullptr);

    m_xFilename = result;
}

STDMETHODIMP AnimMeshAllocator::CreateFrame(LPCSTR name, LPD3DXFRAME* newFrame)
{
    *newFrame = new AnimMeshFrame(name);
    return S_OK;
}

STDMETHODIMP AnimMeshAllocator::CreateMeshContainer(LPCSTR meshName,
                                                    CONST D3DXMESHDATA* meshData,
                                                    CONST D3DXMATERIAL* materials,
                                                    CONST D3DXEFFECTINSTANCE*,
                                                    DWORD materialCount,
                                                    CONST DWORD* adjacency,
                                                    LPD3DXSKININFO,
                                                    LPD3DXMESHCONTAINER* meshContainer)
{
    try
    {
        *meshContainer = new AnimMeshContainer(m_xFilename,
                                               meshName,
                                               meshData->pMesh,
                                               materials,
                                               materialCount,
                                               adjacency);
    }
    catch (...)
    {
        return E_FAIL;
    }

    return S_OK;
}

STDMETHODIMP AnimMeshAllocator::DestroyFrame(LPD3DXFRAME frame)
{
    SAFE_DELETE_ARRAY(frame->Name);
    SAFE_DELETE(frame);
    return S_OK;
}

STDMETHODIMP AnimMeshAllocator::DestroyMeshContainer(LPD3DXMESHCONTAINER meshContainerBase)
{
    AnimMeshContainer* meshContainer = static_cast<AnimMeshContainer*>(meshContainerBase);

    SAFE_RELEASE(meshContainer->pSkinInfo);
    SAFE_DELETE_ARRAY(meshContainer->Name);
    SAFE_DELETE_ARRAY(meshContainer->pAdjacency);
    SAFE_DELETE_ARRAY(meshContainer->pMaterials);
    SAFE_RELEASE(meshContainer->MeshData.pMesh);
    SAFE_DELETE(meshContainer);

    return S_OK;
}

