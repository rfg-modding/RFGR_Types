#pragma once
#include "rfg/Vector.h"
#include "rfg/Matrix.h"

struct rl_base_object;
struct rl_base_objectVtbl
{
    void* (__fastcall* __vecDelDtor)(rl_base_object*, void*, unsigned int);
    void(__fastcall* release)(rl_base_object*, void*);
};

struct rl_base_object
{
    rl_base_objectVtbl* vfptr;
    unsigned int m_leaf_class_id;
};

struct rl_3d_entity : rl_base_object
{
    matrix43 m_world_matrix;
};

struct rl_sphere
{
    vector m_position;
    float m_radius;
};

struct rl_bvolume
{
    rl_sphere m_sphere;
    vector m_half_vec;
    float m_pad;
};

struct rl_named_object : rl_base_object
{

};

struct rl_renderable : rl_named_object
{
    rl_renderable* prev;
    rl_renderable* next;
    rl_bvolume m_local_bvolume;
};

struct __declspec(align(16)) rl_scene_entity : rl_3d_entity
{
    rl_scene_entity* prev;
    rl_scene_entity* next;
    unsigned __int16 m_flags;
    unsigned __int16 m_pass_flags;
    float m_lod_off_distance;
    int m_gpu_vis_index;
    __declspec(align(8)) rl_bvolume m_world_bvolume;
    rl_bvolume m_local_bvolume;
    unsigned int m_vis_pass_flags;
    float m_camera_distance_squared;
    unsigned __int16 m_visibility_list_index;
    char m_category_id;
    char m_last_visibility_pass;
    //Todo: Add these types
    void* m_partition_system_p; //rl_partition_system* m_partition_system_p;
    void* m_partition_sector_entry;//rl_partition_sector_entry m_partition_sector_entry;
    void* m_scene_p; //rl_scene* m_scene_p;
};

struct rl_renderable_instance : rl_scene_entity
{
    enum sort_method
    {
        SORT_METHOD_NONE = 0x0,
        SORT_METHOD_BACK_TO_FRONT = 0x1,
        SORT_METHOD_FRONT_TO_BACK = 0x2,
        SORT_METHOD_FIRST = 0x3,
        SORT_METHOD_LAST = 0x4,
    };

    enum pass_flags
    {
        PASS_FLAGS_DISTORTION = 0x1,
        PASS_FLAGS_GLOW = 0x2,
        PASS_FLAGS_HALF_RES = 0x4,
        PASS_FLAGS_QUARTER_RES = 0x8,
        PASS_FLAGS_OUTLINE_0 = 0x10,
        PASS_FLAGS_OUTLINE_1 = 0x20,
        PASS_FLAGS_OUTLINE_2 = 0x40,
        PASS_FLAGS_OUTLINE_3 = 0x80,
        PASS_FLAGS_XRAY_EFFECT = 0x100,
        PASS_FLAGS_ADDITIVE = 0x200,
        PASS_FLAGS_DISTORTION_ONLY = 0x400,
        PASS_FLAGS_FORCE_SIZEOF_ENUM = 0xFFFFFFFF,
    };

    enum flags
    {
        FLAGS_IS_TRANSPARENT = 0x20,
        FLAGS_CASTS_SHADOWS = 0x40,
        FLAGS_IS_BATCHABLE = 0x80,
        FLAGS_CASTS_DROP_SHADOWS = 0x100,
        FLAGS_CAST_TRANSPARENT_SHADOWS = 0x200,
        FLAGS_CASTS_TERRAIN_SHADOWS = 0x400,
        NUM_FLAGS = 0xB,
    };

    rl_renderable_instance* prev;
    rl_renderable_instance* next;
    __declspec(align(16)) vector4 m_instance_parameters;
    vector m_tint;
    rl_renderable* m_renderable_p;
    float m_opacity;
    __int16 m_batching_complexity;
    __int16 m_lod_level;
    //Todo: Add these types
    void* m_decal_list; //rl_decal* m_decal_list;
    void* m_on_death; //rl_callback_widget_list m_on_death;
    rl_renderable_instance::sort_method m_sort_method;
    int m_conditional_index;
    unsigned __int16 m_sort_priority;
    char m_xray_opacity;
    char m_xray_material_handle;
};