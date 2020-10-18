#pragma once
#include "Human.h"
#include "Vector2.h"

enum general_action_types
{
    GENERAL_ACTION_TYPE_INVALID = 0xFFFFFFFF,
    GENERAL_ACTION_MP_USE_DISARM = 0x0,
    GENERAL_ACTION_MP_SWAP_BACKPACK = 0x1,
    GENERAL_ACTION_MP_MODE_SPECIFIC = 0x2,
    GENERAL_ACTION_DIALOGUE = 0x3,
    GENERAL_ACTION_USE_TURRET = 0x4,
    GENERAL_ACTION_USE_EQUIPPED_ITEM = 0x5,
    GENERAL_ACTION_USE_NEAREST_OBJECT = 0x6,
    GENERAL_ACTION_USE_VEHICLE = 0x7,
    GENERAL_ACTION_USE_LADDER = 0x8,
    GENERAL_ACTION_USE_AMMO_BOX = 0x9,
    GENERAL_ACTION_RELEASE_HOSTAGE = 0xA,
    GENERAL_ACTION_USE_BASE = 0xB,
    GENERAL_ACTION_START_MISSION = 0xC,
    GENERAL_ACTION_START_DEMOLITIONS_MASTER = 0xD,
    GENERAL_ACTION_START_RIDING_SHOTGUN = 0xE,
    GENERAL_ACTION_START_HOUSE_ARREST = 0xF,
    GENERAL_ACTION_START_OFFENSIVE_RAID = 0x10,
    GENERAL_ACTION_UPGRADE = 0x11,
    GENERAL_ACTION_START_AREA_DEFENSE = 0x12,
    NUM_GENERAL_ACTION_TYPES = 0x13,
};

enum use_object_icon
{
    USE_OBJECT_ICON_INVALID = 0xFFFFFFFF,
    USE_OBJECT_ICON_SWAP = 0x0,
    USE_OBJECT_ICON_DEFAULT = 0x1,
    USE_OBJECT_ICON_HYDROGEN_TANK = 0x2,
    USE_OBJECT_ICON_LADDER = 0x3,
    USE_OBJECT_ICON_VEHICLE = 0x4,
    USE_OBJECT_ICON_MISSION = 0x5,
    USE_OBJECT_ICON_DEMOLITION_GUERRILLA = 0x6,
    USE_OBJECT_ICON_DEMOLITION_EDF = 0x7,
    USE_OBJECT_ICON_BAGMAN_GUERRILLA = 0x8,
    USE_OBJECT_ICON_BAGMAN_EDF = 0x9,
    USE_OBJECT_ICON_UPGRADE = 0xA,
    NUM_PAOI_TYPES = 0xB,
};

enum tagging_sequence
{
    TAGGING_SEQUENCE_NONE = 0xFFFFFFFF,
    TAGGING_SEQUENCE_START = 0x0,
    TAGGING_SEQUENCE_TAG = 0x1,
    TAGGING_SEQUENCE_DONE = 0x2,
    NUM_TAGGING_SEQUENCES = 0x3,
};

enum player_zoom_state
{
    PZS_OFF = 0x0,
    PZS_SPRINT = 0x1,
    PZS_FINE_AIM = 0x2,
    PZS_SCOPE = 0x3,
};

enum player_script_mode
{
    PSM_NONE = 0x0,
    PSM_VEHICLE_ENTER = 0x1,
    NUM_PLAYER_SCRIPT_MODES = 0x2,
};

struct player;
struct t_usable_object
{
    unsigned int handle;
    general_action_types action_type;
    use_object_icon action_icon;
    float dot_prod;
    float dist_squared;
    bool(__cdecl* action_callback)(player*, bool);
};

struct player_flags
{
    unsigned __int32 action_node_anim_started : 1;
    unsigned __int32 custom_mesh : 1;
    unsigned __int32 is_loaded : 1;
    unsigned __int32 script_controlled : 1;
    unsigned __int32 never_die : 1;
    unsigned __int32 mission_never_die : 1;
    unsigned __int32 do_sprint : 1;
    unsigned __int32 disable_controls : 1;
    unsigned __int32 jetpack_started : 1;
    unsigned __int32 jetpack_ready : 1;
    unsigned __int32 moving_to_a_stop : 1;
    unsigned __int32 quick_turn : 1;
    unsigned __int32 crouching_state : 1;
    unsigned __int32 weapon_hidden : 1;
    unsigned __int32 is_stuck : 1;
    unsigned __int32 cover_firing : 1;
    unsigned __int32 cover_leanup : 1;
    unsigned __int32 use_cover : 1;
    unsigned __int32 no_reticule : 1;
    unsigned __int32 no_fineaim : 1;
    unsigned __int32 cover_search_for_edge : 1;
    unsigned __int32 cover_against_vehicle : 1;
    unsigned __int32 in_comm_tower_range : 1;
    unsigned __int32 comm_range_checked : 1;
    unsigned __int32 passenger_brake : 1;
    unsigned __int32 local_player_hit_someone_this_frame : 1;
    unsigned __int32 weapon_swap_lock : 1;
    unsigned __int32 unlimited_ammo : 1;
    unsigned __int32 in_radiation : 1;
    unsigned __int32 ragdoll_on_next_explosion : 1;
    unsigned __int32 leaving_squad_member_behind : 1;
    unsigned __int32 is_waiting_for_hostage_vehicle_exit : 1;
    unsigned __int32 backpack_fade_out : 1;
    unsigned __int32 backpack_fade_in : 1;
    unsigned __int32 mp_display_respawn_msg : 1;
    unsigned __int32 mp_remote_player_fired_this_frame : 1;
    unsigned __int32 mp_ignore_player_for_respawn_collisions : 1;
    unsigned __int32 mp_lost_hp : 1;
    unsigned __int32 mp_hit_someone_this_network_frame : 1;
    unsigned __int32 mp_remote_player_charged_this_frame : 1;
    unsigned __int32 mp_local_player_can_see_me : 1;
    unsigned __int32 mp_has_reloaded : 1;
    unsigned __int32 mp_removing_player : 1;
    unsigned __int32 waiting_for_locker_exit : 1;
};

struct custom_vehicle
{
    struct flags
    {
        unsigned __int32 is_totaled : 1;
        unsigned __int32 is_in_garage : 1;
    };

    custom_vehicle* prev;
    custom_vehicle* next;
    int m_type_index;
    custom_vehicle::flags m_flags;
};

struct __declspec(align(4)) vehicle_enter_struct
{
    unsigned int vehicle_handle;
    bool run;
};

union script_specific_data
{
    vehicle_enter_struct vehicle_enter_data;
};

struct player : human
{
    float frametime_multiplier;
    t_usable_object action_object;
    timestamp action_object_timestamp;
    timestamp last_fire_time;
    unsigned int mp_action_object_handle;
    int radio_id;
    int tag_trigger;
    tagging_sequence tag_seq;
    timestamp tag_timer;
    int tag_effect;
    hud_message_handle hud_message;
    unsigned int havok_filter_group;
    unsigned int aim_target;
    unsigned int penetrating_aim_target;
    vector penetrating_aim_pos;
    timestamp aim_target_duration;
    unsigned int heat_seeking_target;
    vector aim_pos;
    timestamp combat_target_update_time;
    float remote_charge_time;
    bool doing_remote_charge;
    player_zoom_state zoom_state;
    player_zoom_state previous_zoom_state;
    vector cover_vector;
    vector cover_vector_right;
    timestamp entering_cover;
    timestamp exiting_cover;
    float cover_move_vel;
    bool cover_approaching_edge;
    timestamp cover_approaching_edge_ts;
    vector cover_edge_hit_pos;
    vector cover_edge_miss_pos;
    vector thrown_weapon_check_pos;
    int combat_move_queue;
    timestamp_percent previous_bullet_hit;
    float jetpack_fuel_percent;
    int jetpack_foley;
    unsigned int jetpack_effect;
    bool allow_ragdoll;
    player_flags pflags;
    bool hold_object_available;
    unsigned int hold_object_handle;
    unsigned int abandoned_vehicles[3];
    int num_abandoned_vehicles;
    custom_vehicle custom_vehicles[50];
    custom_vehicle* custom_vehicle_list;
    custom_vehicle* custom_vehicle_free_list;
    int num_custom_vehicles;
    timestamp_percent dead_timestamp;
    unsigned int mat_fx_handle[16];
    unsigned int current_mat_fx;
    player_script_mode script_mode;
    script_specific_data script_data;
    //Todo: Set type
    void* backpack; //multi_object_backpack* backpack;
    int mp_respawn_backpack_type;
    //Todo: Fill out remainder of player class
    //c_command mp_current_command;
    //bool mp_remote_player_fired_this_frame;
    //vector mp_camera_pos;
    //matrix mp_camera_orient;
    //vector2 mp_camera_angular_velocity;
    //int mp_desired_weapon_slot;
    //unsigned int mp_last_respawn_time;
    //unsigned int mp_data;
    //unsigned int mp_disarm_bomb_handle;
    //multi_sim_state<multi_player_state> mp_sim_state;
    //unsigned int mp_last_spawn_point_handle;
    //multi_timestamp mp_time_until_player_can_respawn;
    //multi_timestamp_percent mp_time_until_player_leaves_invulnerable;
    //multi_object_backpack* mp_swap_backpack;
    //float mp_player_damage_history[16];
    //player_ladder_state mp_ladder_state;
    //vector mp_ragdoll_force;
    //vector mp_ragdoll_pos;
    //timestamp mp_ragdoll_force_timeout;
    //multi_player_edge_correction_info mp_edge_correction_info;
    //multi_player_blocked_info mp_blocked_info;
    //vector mp_ragdoll_linear_velocity_aggregate;
    //vector mp_ragdoll_angular_velocity_aggregate;
    //float mp_simulation_time_used;
    //float mp_simulation_time_accumulated;
    //float mp_simulation_time_extrapolated;
    //int jetpack_use_log_handle;
    //int backpack_equip_log_handle;
    //int district_log_handle;
    //matrix43 camera_bone_transform;
    //vector movement_velocity;
    //vector2 direct_control_dir;
    //vector direct_control_vel;
    //vector cover_collision_normal;
    //vector last_frame_cover_collision_normal;
    //player_cover_test cover_test_queue;
    //timestamp cover_delay_ts;
    //timestamp cover_enter_ts;
    //timestamp cover_exit_delay_ts;
    //timestamp cover_dive_capsule;
    //timestamp cover_lean_delay;
    //float cover_root_offset;
    //float spinebend_root_offset;
    //timestamp facial_idle;
    //timestamp footstep_propagate_time;
    //timestamp bump_into_propagate_time;
    //unsigned int ammo_box_handle;
    //timestamp pathfind_time_out;
    //interface_modes current_interface_mode;
    //unsigned int common_controls_allowed;
    //unsigned int controls_general_allowed;
    //unsigned int controls_on_foot_allowed;
    //unsigned int controls_driving_allowed;
    //unsigned int general_actions_allowed;
    //timestamp weapon_swap_timestamp;
    //timestamp sprint_delay_timestamp;
    //timestamp sprint_start_timestamp;
    //timestamp jump_refresh_timestamp;
    //unsigned int ally_squad_handle;
    //unsigned int escort_squad_handle;
    //timestamp check_squads_timer;
    //$E56F3E7058659FC393208A12545B3786 pathfind_info;
    //decal_circ_array_queue<10> blood_decals;
    //int blood_decals_fade_index;
    //cfile* activity_inventory_save_file;
    //char activity_inventory_buffer[1024];
    //timestamp zoom_cancel_timestamp;
    //unsigned int non_inventory_item_handle;
    //unsigned int last_vehicle_driven;
    //matrix quick_turn_orient;
    //float quick_turn_speed;
    //player_meta_data meta_data;
    //timestamp radiation_timestamp;
    //float radiation_damage;
    //int radiation_foley;
    //timestamp is_stuck_timer;
    //vector last_stuck_pos;
    //int ragdoll_override_get_up_time;
    //timestamp_percent fade_backpack_time;
    //timestamp comm_tower_check_period;
    //int next_record;
    //player_positional_record positional_records[8];
    //timestamp tracking_period;
};