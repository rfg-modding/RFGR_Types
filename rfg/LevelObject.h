#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "Timestamp.h"
#include "Explosion.h"
#include "Effect.h"

struct level_object_properties_flags
{
    __int8 m_damaged_by_cars : 1;
    __int8 m_damaged_by_explosions : 1;
    __int8 m_damaged_by_bullets : 1;
    __int8 m_damaged_by_level_objects : 1;
    __int8 m_damaged_by_melee : 1;
    __int8 m_dislodged_by_cars : 1;
    __int8 m_dislodged_by_explosions : 1;
    __int8 m_dislodged_by_bullets : 1;
    __int8 m_dislodged_by_level_objects : 1;
    __int8 m_dislodged_by_melee : 1;
    __int8 m_allow_dynamic_link : 1;
    __int8 m_link_affects_effects : 1;
    __int8 m_death_explosion : 1;
    __int8 m_dislodge_on_death : 1;
    __int8 m_movable_by_humans : 1;
    __int8 m_generate_human_collision_event : 1;
};

struct level_object_base_properties
{
    char* m_name;
    unsigned int m_collision_impact_override;
    float m_collision_min_impact_energy;
    unsigned int* m_melee_impact_override;
    unsigned int* m_bullet_impact_override;
    script_point_effect_info* m_script_point_effect_infos[4];
    level_object_properties_flags m_flags;
    custom_effect_info m_custom_effect_infos[3];
    int m_max_hitpoints;
    int m_max_dislodge_hitpoints;
    float m_mass;
    float m_corpse_mass;
    float m_friction;
    float m_restitution;
    float m_linear_dampening;
    float m_angular_dampening;
    char m_physical_material;
    char m_effect_material;
    unsigned int m_death_effect;
    unsigned int m_release_effect;
    int m_release_delay_ms;
    int m_release_looping_ms;
    explosion_container m_death_explosions[1];
    int m_explosion_prefix_min_duration;
    int m_explosion_prefix_max_duration;
    int m_prefix_hitpoints;
    custom_effect_info m_prefix_effect_infos[2];
};

struct level_object_inst_properties
{
    level_object_properties_flags m_flags;
    level_object_base_properties* m_base_properties;
    unsigned int m_custom_effects[3];
    script_point_effect_inst* m_script_point_effect_insts[4];
    int m_hitpoints;
    int m_dislodge_hitpoints;
    unsigned int m_prefix_effects[2];
    timestamp m_death_timer;
    unsigned int m_release_effect_instance;
};