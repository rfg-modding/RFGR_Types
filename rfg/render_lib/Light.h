#pragma once
#include "Renderable.h"
#include "RlBase.h"

struct  __declspec(align(16)) rl_light : rl_scene_entity
{
    enum light_type
    {
        LIGHT_TYPE_DIRECTIONAL = 0x0,
        LIGHT_TYPE_POINT = 0x1,
        LIGHT_TYPE_SPOT_LIGHT = 0x2,
        LIGHT_TYPE_FORCE_SIZEOF_INT = 0xFFFFFFFF,
    };

    rl_light* prev;
    rl_light* next;
    rl_light::light_type m_light_type;
    rl_color_float m_color;
    float m_attenuation_start;
    float m_attenuation_end;
    float m_hotspot_falloff_size;
    float m_hotspot_size;
    vector m_clip_min;
    vector m_clip_max;
    vector m_light_direction;
    rl_renderable_instance* m_clip_mesh;
    unsigned __int16 m_vis_pass_index;
    unsigned __int16 m_shadow_vis_pass_index;
};