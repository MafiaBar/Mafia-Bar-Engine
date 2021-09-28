#pragma once
#include "pch.h"
using namespace DirectX;
struct DirectXSetup
{
public:
    // Direct3D device and swap chain.
    ID3D11Device* g_d3dDevice = nullptr;
    ID3D11DeviceContext* g_d3dDeviceContext = nullptr;
    IDXGISwapChain* g_d3dSwapChain = nullptr;

    // Render target view for the back buffer of the swap chain.
    ID3D11RenderTargetView* g_d3dRenderTargetView = nullptr;

    // Depth/stencil view for use as a depth buffer.
    ID3D11DepthStencilView* g_d3dDepthStencilView = nullptr;

    // A texture to associate to the depth stencil view.
    ID3D11Texture2D* g_d3dDepthStencilBuffer = nullptr;

    // Define the functionality of the depth/stencil stages.
    ID3D11DepthStencilState* g_d3dDepthStencilState = nullptr;

    // Define the functionality of the rasterizer stage.
    ID3D11RasterizerState* g_d3dRasterizerState = nullptr;

    //Viewport
    D3D11_VIEWPORT g_Viewport = { 0 };

    // Vertex buffer data
    ID3D11InputLayout* g_d3dInputLayout = nullptr;
    ID3D11Buffer* g_d3dVertexBuffer = nullptr;
    ID3D11Buffer* g_d3dIndexBuffer = nullptr;

    // Shader data
    ID3D11VertexShader* g_d3dVertexShader = nullptr;
    ID3D11PixelShader* g_d3dPixelShader = nullptr;

    // Shader resources
    enum ConstantBuffer
    {
        CB_Application,
        CB_Frame,
        CB_Object,
        NumConstantBuffers
    };

    ID3D11Buffer* g_d3dConstantBuffers[NumConstantBuffers];


    // Demo parameters
    DirectX::XMMATRIX g_WorldMatrix;
    DirectX::XMMATRIX g_ViewMatrix;
    DirectX::XMMATRIX g_ProjectionMatrix;

    // Vertex data for a colored cube.
    struct VertexPosColor
    {
        XMFLOAT3 Position;
        XMFLOAT3 Color;
    };

    VertexPosColor g_Vertices[8] =
    {
        { XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT3(0.0f, 0.0f, 0.0f) }, // 0
        { XMFLOAT3(-1.0f,  1.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) }, // 1
        { XMFLOAT3(1.0f,  1.0f, -1.0f), XMFLOAT3(1.0f, 1.0f, 0.0f) }, // 2
        { XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f) }, // 3
        { XMFLOAT3(-1.0f, -1.0f,  1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) }, // 4
        { XMFLOAT3(-1.0f,  1.0f,  1.0f), XMFLOAT3(0.0f, 1.0f, 1.0f) }, // 5
        { XMFLOAT3(1.0f,  1.0f,  1.0f), XMFLOAT3(1.0f, 1.0f, 1.0f) }, // 6
        { XMFLOAT3(1.0f, -1.0f,  1.0f), XMFLOAT3(1.0f, 0.0f, 1.0f) }  // 7

    };

    WORD g_Indicies[36] =
    {
        0, 1, 2, 0, 2, 3,
        4, 6, 5, 4, 7, 6,
        4, 5, 1, 4, 1, 0,
        3, 2, 6, 3, 6, 7,
        1, 5, 6, 1, 6, 2,
        4, 0, 3, 4, 3, 7
    };

    bool Vsync = true;
};


