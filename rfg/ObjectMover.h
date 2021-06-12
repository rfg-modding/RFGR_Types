#pragma once
#include "Object.h"
#include "Human.h"
#include "LevelObject.h"
#include "Event.h"
#include "Salvage.h"

struct LOD_properties
{
    char* m_name;
    float m_lod_off_dist;
};

struct gameplay_properties
{
    char* name;
    int chunk_flags;
    object_importance_level importance;
    human_teams team;
    float game_destroyed_pct;
    float fully_destroyed_pct;
    salvage_material_type salvage_material;
    int salvage_num_pieces;
    float control;
    float monetary_value;
    LOD_properties* lod_properties;
};

struct object_mover_error_info
{
    timestamp hold_time;
    int hold_count;
};

struct object_mover : object
{
    int mover_type_bit_flags;
    unsigned __int16 m_render_opacity;
    unsigned __int16 reference_position_index;
    unsigned int chunk_uid;
    unsigned int shape_uid;
    unsigned int chunk_obj_uid;
    unsigned int destruction_checksum;
    level_object_inst_properties* m_level_obj_properties;
    event_result(__cdecl* on_stream_in_callback)(event_data*, notify_info*);
    event_result(__cdecl* on_damaged_callback)(event_data*, notify_info*);
    event_result(__cdecl* on_destroyed_callback)(event_data*, notify_info*);
    event_result(__cdecl* on_use_action_callback)(event_data*, notify_info*);
    gameplay_properties* gameplay_props;
    human_teams team;
    float control;
    unsigned int nav_cell_detour_request_handle;
    unsigned int creator_handle;
    unsigned int final_attacker;
    unsigned int mover_flags;
    int fade_start_time;
    timestamp fade_out_timer;
    timestamp melee_damage_delay;
    timestamp inactive_fade_time;
    object_mover_error_info* m_mp_error_info;
};