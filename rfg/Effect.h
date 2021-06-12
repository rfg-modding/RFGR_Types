#pragma once
#include "Timestamp.h"

struct explosion_info;

enum script_point_effect_state
{
    SPES_INVALID = 0xFFFFFFFF,
    SPES_NORMAL = 0x0,
    SPES_STOPPED = 0x1,
    SPES_PRE_DEATH = 0x2,
    SPES_DEAD = 0x3,
};

struct __declspec(align(4)) custom_effect_info
{
    unsigned int effect_handle;
    char* attachment_point_name;
    bool looping;
};

struct script_point_effect_info
{
    char script_point_name[32];
    int max_hitpoints;
    unsigned int* bullet_impact_override;
    unsigned int custom_effect;
    unsigned int prefix_effect;
    float prefix_effect_delay_min;
    float prefix_effect_delay_max;
    int prefix_hitpoints;
    unsigned int death_effect;
    explosion_info* death_explosion;
    unsigned int spe_flags;
};

struct object_mover;
struct script_point_effect_inst
{
    int script_point_idx;
    unsigned int shape_key;
    unsigned int current_effect;
    int hitpoints;
    timestamp death_timer;
    script_point_effect_state state;
    object_mover* host_obj;
    int host_idx;
};
