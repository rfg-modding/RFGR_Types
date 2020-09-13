#pragma once
#include <d3d11_1.h>
#include <DXGI.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

namespace keen
{
    struct GraphicsStateObject
    {
        unsigned int hash;
        unsigned int refCount;
    };

    struct VertexAttributeDescription
    {
        char id;
        char format;
        char inputStreamIndex;
        char instanceStepRate;
    };

    const struct VertexFormat : keen::GraphicsStateObject
    {
        keen::VertexAttributeDescription attributes[17];
        unsigned int attributeOffsets[17];
        unsigned int attributeCount;
        unsigned int attributeIndices[17];
        unsigned int streamStride[6];
        unsigned int instanceDataStreamIndex;
    };

    const struct RenderGeometry
    {
        keen::VertexFormat* pVertexFormat;
        ID3D11Buffer* pVertexBuffer;
        unsigned int vertexCount;
        ID3D11Buffer* pIndexBuffer;
        unsigned int indexCount;
        void* pSkinGeometry; //keen::SoftwareSkinGeometry* pSkinGeometry;
        unsigned int skinningBufferOffset;
        const char* pDebugName;
        unsigned int indexFormat;
        unsigned int primitiveTopology;
        void* pMorphData; //keen::SoftwareMorphData* pMorphData;
    };
}