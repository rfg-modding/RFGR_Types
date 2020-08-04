#pragma once
#include "Human.h"
#include "Navpoint.h"
#include "Timestamp.h"
#include "Vector2.h"

enum npc_manager_systems
{
    NPC_MANAGER_INVALID = 0xFFFFFFFF,
    NPC_MANAGER_SQUAD = 0x0,
    NPC_MANAGER_AMBIENT = 0x1,
    NPC_MANAGER_SPAWN_NODE = 0x2,
    NPC_MANAGER_CUT_SCENE = 0x3,
    NPC_MANAGER_ACTIVITY_ASSASSIN = 0x4,
    NPC_MANAGER_ACTIVITY_HOUSE_ARREST = 0x5,
    NPC_MANAGER_DESPAWN = 0x6,
    NPC_MANAGER_DEBUG = 0x7,
    NUM_NPC_MANAGERS = 0x8,
};

struct npc_flags_struct
{
    unsigned __int32 had_squad : 1;
    unsigned __int32 always_show_on_minimap : 1;
    unsigned __int32 deaf : 1;
    unsigned __int32 force_targetable : 1;
    unsigned __int32 in_cutscene : 1;
    unsigned __int32 not_recruitable : 1;
    unsigned __int32 recruitable_escort : 1;
    unsigned __int32 turning_around : 1;
    unsigned __int32 use_default_team : 1;
    unsigned __int32 reequipping_weapon : 1;
    unsigned __int32 going_left : 1;
    unsigned __int32 going_left_last_time : 1;
    unsigned __int32 passenger_wait : 1;
    unsigned __int32 player_exit_wait : 1;
    unsigned __int32 chase_teleport_disable : 1;
    unsigned __int32 honked_at : 1;
    unsigned __int32 honked_at_friendly : 1;
    unsigned __int32 honked_at_hostile : 1;
    unsigned __int32 activity_related : 1;
    unsigned __int32 mission_related : 1;
    unsigned __int32 ambush_related : 1;
    unsigned __int32 convoy_squad : 1;
    unsigned __int32 civilian_has_been_oppressed : 1;
    unsigned __int32 entered_raid : 1;
    unsigned __int32 raid_cheer : 1;
    unsigned __int32 raid_watch : 1;
    unsigned __int32 return_fire_aim_bonus : 1;
    unsigned __int32 reduced_npc_damage : 1;
    unsigned __int32 maneuver_required : 1;
    unsigned __int32 activity_driver_vr : 1;
    unsigned __int32 activity_pursuit_vr : 1;
    unsigned __int32 activity_pursuit_ca : 1;
    unsigned __int32 activity_ha : 1;
    unsigned __int32 prevent_weapon_draw : 1;
    unsigned __int32 tied_up : 1;
    unsigned __int32 freed_from_bonds : 1;
    unsigned __int32 run_to_safehouse : 1;
    unsigned __int32 bureaucrat : 1;
    unsigned __int32 ambient_spawn : 1;
    unsigned __int32 ambient_flee : 1;
    unsigned __int32 ambient_near_player : 1;
    unsigned __int32 ambient_vehicle_spawn : 1;
    unsigned __int32 ambient_edf_flyer : 1;
    unsigned __int32 roadblock_guard : 1;
    unsigned __int32 thanked_player : 1;
    unsigned __int32 converted_guerrilla : 1;
    unsigned __int32 attempted_spontaneous_conversion : 1;
    unsigned __int32 dont_collide_with_humans : 1;
    unsigned __int32 disable_grenades : 1;
    unsigned __int32 no_turret_attacks : 1;
    unsigned __int32 force_out_of_vehicle : 1;
    unsigned __int32 scripted_move : 1;
    unsigned __int32 scripted_drive : 1;
    unsigned __int32 only_ride_with_player : 1;
    unsigned __int32 played_added_message : 1;
    unsigned __int32 has_reached_player : 1;
    unsigned __int32 too_far_from_player : 1;
    unsigned __int32 spawned_as_corpse : 1;
    unsigned __int32 use_corpse_vehicle_exit : 1;
    unsigned __int32 man_flyer : 1;
    unsigned __int32 ignore_player : 1;
    unsigned __int32 squad_leader_ignore_player : 1;
    unsigned __int32 fire_on_vehicles : 1;
    unsigned __int32 ignore_vehicles : 1;
    unsigned __int32 orders_active : 1;
    unsigned __int32 fodder_on_object : 1;
    unsigned __int32 remove_icon_on_death : 1;
    unsigned __int32 courier_run_to_destination : 1;
    unsigned __int32 can_use_special_roads : 1;
    unsigned __int32 bomb : 1;
    unsigned __int32 drive_disabled : 1;
    unsigned __int32 used_action_node : 1;
    unsigned __int32 immediate_spawn : 1;
    unsigned __int32 console_created : 1;
    unsigned __int32 amb_watch_player : 1;
    unsigned __int32 despawn_after_fade : 1;
    unsigned __int32 allow_idle_despawn : 1;
    unsigned __int32 disallow_idle_despawn : 1;
    unsigned __int32 despawn_npc : 1;
    unsigned __int32 disallow_despawn_engagement : 1;
    unsigned __int32 high_priority_despawn : 1;
    unsigned __int32 despawn_on_green_alert : 1;
};

struct $39A5CD0A01CBACDCC8ACC9FFCAC3EB9B
{
    __int8 run : 1;
    __int8 fire_at_target : 1;
    __int8 use_vehicle : 1;
    __int8 drive_directly : 1;
};

struct __declspec(align(4)) npc_script_info
{
    unsigned int location_object;
    $39A5CD0A01CBACDCC8ACC9FFCAC3EB9B flags;
};

struct npc_weapon_drift_info
{
    float desired_error_mag;
    float actual_error_mag;
    timestamp_percent acquire_time;
    timestamp_percent change_time;
    vector2 next_error_pos;
    vector2 prev_error_pos;
    vector2 cur_error_pos;
};

struct __declspec(align(16)) npc : human
{
    char name[32];
    npc_flags_struct npc_flags;
    navpoint* start_navpoint;
    object_spawn_priority spawn_priority;
    float m_stream_load_squared_dist;
    float m_stream_unload_squared_dist;
    vector dest_point;
    unsigned __int64 dest_cell_hint_handle;
    npc_script_info scripting_info;
    unsigned int spawn_node_handle;
    npc_manager_systems management_system;
    npc_manager_systems creation_system;
    timestamp time_offscreen;
    unsigned int despawn_obj_handle;
    timestamp final_despawn_timer;
    npc_weapon_drift_info drift_info;
    void* ai_system; //ai_system* ai;
};