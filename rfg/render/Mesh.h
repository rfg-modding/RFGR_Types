#pragma once
#include "RlCommon.h"
#include "RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Containers.h"
#include "RFGR_Types/rfg/keen/render/RenderGeometry.h"

struct rl_vertex_buffer_data_runtime
{
    int num_verts;
    char vert_stride_0;
    char vertex_format;
    char num_uv_channels;
    char vert_stride_1;
    char* verts;
};

struct rl_index_buffer_data_runtime
{
    unsigned int num_indices;
    char* indices;
    char index_size;
    char prim_type;
    unsigned __int16 num_blocks;
};

struct rl_submesh_data
{
    int num_render_blocks;
    vector offset_transform;
    vector bmin;
    vector bmax;
    et_ptr_offset<rl_render_block, 0> render_blocks;
};

struct rl_mesh_data_runtime
{
    int num_sub_meshes;
    rl_submesh_data* sub_meshes;
    rl_vertex_buffer_data_runtime vertex_buffer;
    rl_index_buffer_data_runtime index_buffer;
};

const struct __declspec(align(8)) rl_mesh : rl_renderable
{
    bool m_data_set;
    rl_mesh_data_runtime m_data;
    rl_render_block* m_base_render_block;
    unsigned int m_max_material_index;
    unsigned int m_uid;
    keen::RenderGeometry m_geometry;
};