#pragma once
#include "RFGR_Types/rfg/Vector.h"

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

struct  rl_base_object
{
    void* vfptr;//rl_base_objectVtbl* vfptr;
    unsigned int m_leaf_class_id;
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