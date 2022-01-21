#pragma once
#include "Renderable.h"
#include "Material.h"
#include "rfg/Containers.h"
#include "rfg/Vector.h"
#include "rfg/keen/GraphicsSystem.h"

struct LoadedMeshInfo
{
    char name[64];
    const void* pVertexBuffer;
    const void* pIndexBuffer;
};

struct rl_render_block
{
    unsigned __int16 material_map_idx;
    unsigned int start_index;
    unsigned int num_indices;
    unsigned int minimum_index;
    unsigned int maximum_index;
};

struct rl_submesh_data
{
    int num_render_blocks;
    vector offset_transform;
    vector bmin;
    vector bmax;
    et_ptr_offset<rl_render_block, 0> render_blocks;
};

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

struct rl_mesh_data_runtime
{
    int num_sub_meshes;
    rl_submesh_data* sub_meshes;
    rl_vertex_buffer_data_runtime vertex_buffer;
    rl_index_buffer_data_runtime index_buffer;
};

struct __declspec(align(8)) rl_mesh : rl_renderable
{
    bool m_data_set;
    rl_mesh_data_runtime m_data;
    rl_render_block* m_base_render_block;
    unsigned int m_max_material_index;
    unsigned int m_uid;
    keen::RenderGeometry m_geometry;
};

struct mesh_tag
{
    unsigned int m_name_crc;
    matrix43 m_transform;
};

struct mesh_tags
{
    int m_num_tags;
    et_sized_native_pointer<mesh_tag> m_tags;
};

struct mesh_header_shared
{
    unsigned int m_signature;
    unsigned int m_version;
    et_sized_native_pointer<rl_mesh> m_mesh;
    et_sized_native_pointer<rl_material_map> m_material_map;
    et_sized_native_pointer<et_sized_native_pointer<rl_material>> m_materials;
    unsigned int m_num_materials;
    char padding0[4];
    et_sized_native_pointer<char const> m_texture_names;
};

struct static_mesh
{
    mesh_header_shared m_shared_header;
    unsigned int m_num_lods;
    char padding0[4];
    et_sized_native_pointer<int> m_lod_submesh_id;
    et_sized_native_pointer<mesh_tags> m_tags_offset;
    mesh_tags m_tags;
    unsigned int m_cm_index;
    char padding1[4];
};

struct __declspec(align(8)) rl_mesh_instance : rl_renderable_instance
{
    rl_material_map* m_mat_map;
    unsigned int m_submesh_index;
    int m_render_instance_index;

    void release()
    {
        vfptr->release(this, nullptr);
    }
};