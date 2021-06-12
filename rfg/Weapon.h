#pragma once
#include "Vector.h"
#include "String.h"
#include "Human.h"
#include "Explosion.h"

enum weapon_trigger_type
{
    WEAPON_TRIGGER_TYPE_SINGLE = 0x0,
    WEAPON_TRIGGER_TYPE_AUTOMATIC = 0x1,
    WEAPON_TRIGGER_TYPE_CHARGE = 0x2,
    NUM_WEAPON_TRIGGER_TYPES = 0x3,
};

enum weapon_ammo_type
{
    WEAPON_AMMO_TYPE_BULLET = 0x0,
    WEAPON_AMMO_TYPE_PROJECTILE = 0x1,
    WEAPON_AMMO_TYPE_THROWN = 0x2,
    WEAPON_AMMO_TYPE_MELEE = 0x3,
    WEAPON_AMMO_TYPE_ELECTRICITY = 0x4,
    WEAPON_AMMO_TYPE_REPAIR = 0x5,
    WEAPON_AMMO_TYPE_BLANKS = 0x6,
    WEAPON_AMMO_TYPE_FLAME = 0x7,
    NUM_WEAPON_AMMO_TYPES = 0x8,
};

enum weapon_class_type
{
    WEAPON_CLASS_NONE = 0xFFFFFFFF,
    WEAPON_CLASS_BULLET = 0x0,
    WEAPON_CLASS_LAUNCHER = 0x1,
    WEAPON_CLASS_THROWN = 0x2,
    WEAPON_CLASS_THROWN_CHARGE = 0x3,
    WEAPON_CLASS_THROWN_MINE = 0x4,
    WEAPON_CLASS_THROWN_GRENADE = 0x5,
    WEAPON_CLASS_MELEE = 0x6,
    WEAPON_CLASS_SLEDGEHAMMER = 0x7,
    WEAPON_CLASS_GUTTER = 0x8,
    WEAPON_CLASS_GRINDER = 0x9,
    WEAPON_CLASS_ARC_WELDER = 0xA,
    WEAPON_CLASS_NANO_RIFLE = 0xB,
    WEAPON_CLASS_MASS_DRIVER = 0xC,
    WEAPON_CLASS_HARPOON = 0xD,
    WEAPON_CLASS_SINGULARITY_BOMB = 0xE,
    WEAPON_CLASS_REPAIR = 0xF,
    WEAPON_CLASS_FLAME = 0x10,
    NUM_WEAPON_CLASSES = 0x11,
};

enum animation_group
{
    ANIMATION_GROUP_NONE = 0xFFFFFFFF,
    ANIMATION_GROUP_DEFAULT = 0x0,
    ANIMATION_GROUP_AK = 0x1,
    ANIMATION_GROUP_MELEE = 0x2,
    ANIMATION_GROUP_PISTOL = 0x3,
    ANIMATION_GROUP_REVOLVER = 0x4,
    ANIMATION_GROUP_RIFLE = 0x5,
    ANIMATION_GROUP_RPG = 0x6,
    ANIMATION_GROUP_MORTAR = 0x7,
    ANIMATION_GROUP_MINE = 0x8,
    ANIMATION_GROUP_HAMMER = 0x9,
    ANIMATION_GROUP_REMOTE_CHARGE = 0xA,
    ANIMATION_GROUP_TURRET_MACHINEGUN = 0xB,
    ANIMATION_GROUP_TURRET_ROCKET = 0xC,
    ANIMATION_GROUP_TURRET_RAILGUN = 0xD,
    ANIMATION_GROUP_2H_CARRY = 0xE,
    ANIMATION_GROUP_GUTTER = 0xF,
    ANIMATION_GROUP_SHOTGUN = 0x10,
    ANIMATION_GROUP_SNIPER = 0x11,
    ANIMATION_GROUP_ARC = 0x12,
    ANIMATION_GROUP_RAILGUN = 0x13,
    ANIMATION_GROUP_NANO = 0x14,
    ANIMATION_GROUP_THERMOBARIC_ROCKET_LAUNCHER = 0x15,
    ANIMATION_GROUP_PIPE = 0x16,
    ANIMATION_GROUP_SHIELD = 0x17,
    ANIMATION_GROUP_GRINDER = 0x18,
    ANIMATION_GROUP_ENFORCER = 0x19,
    NUM_ANIM_GROUPS = 0x1A,
};

enum human_melee_combat_move_id
{
    INVALID_MELEE_COMBAT_MOVE_ID = 0xFFFFFFFF,
    HUMAN_MELEE_COMBAT_MOVE_ID_FORCE_TO_32_BITS = 0x7FFFFFFF,
};

enum air_bomb_handle
{
    INVALID_AIR_BOMB_HANDLE = 0xFFFFFFFF,
    AIR_BOMB_HANDLE_FORCE_TO_32_BIT = 0x7FFFFFFF,
};

//struct $4CC5F1CDA5212CF270796B525117DA23
struct weapon_projectile_info
{
    //Todo: Set type
    void* obj_item_info; //item_info* obj_item_info;
    float start_speed;
    float max_speed;
    float acceleration;
    unsigned __int16 fuse_time;
    float max_throw_dist;
    float gravity;
    int sound;
    unsigned int effect1;
    unsigned int effect2;
    unsigned int effect3;
    unsigned int effect4;
    unsigned int flags;
    float inaccurate_flight;
    float time_until_propelled;
    float time_until_prop_expire;
    float time_until_drop;
    unsigned int damage_effect;
    //Todo: Set type
    void* hit_camera_shake; //camera_shake* hit_camera_shake;
};

struct weapon_info_flags
{
    __int8 armor_piercing : 1;
    __int8 can_fine_aim : 1;
    __int8 can_scope : 1;
    __int8 shatter : 1;
    __int8 held_in_left_hand : 1;
    __int8 draw_proj_in_opposite_hand : 1;
    __int8 silent_bullets : 1;
    __int8 penetrating_bullets : 1;
    __int8 non_inventory : 1;
    __int8 use_even_spread : 1;
    __int8 disable_player_cover : 1;
    __int8 mp_selectable : 1;
    __int8 is_obvious_weapon : 1;
    __int8 auto_aim_curved_trail : 1;
    __int8 looping_effects : 1;
    __int8 never_in_cabinet : 1;
    __int8 use_secondary_weapon_heat : 1;
    __int8 dont_drop_on_death : 1;
};

struct damage_scaling_info
{
    float scale_value;
    float damage[4];
};

struct weapon_info
{
    char* name;
    checksum_stri name_crc;
    int unique_id;
    weapon_info_flags flags;
    weapon_class_type weapon_class;
    //Todo: Set type
    void* weapon_obj_item_info; //item_info* weapon_obj_item_info;
    //Todo: Set type
    void* weapon_inv_item_info; //inv_item_info* weapon_inv_item_info;
    human_teams default_team;
    char* icon_name;
    char* small_icon_name;
    char* reticule_name;
    char* fine_aim_reticule_name;
    char* mp_kill_phrase;
    animation_group weapon_anim_group;
    unsigned int muzzle_flash_effect;
    unsigned int muzzle_smoke_effect;
    unsigned int special_hit_effect;
    unsigned int special_effect;
    unsigned int secondary_special_effect;
    unsigned int overheated_effect;
    unsigned int tracer_effect;
    //Todo: Set type
    void* fire_camera_shake; //camera_shake* fire_camera_shake;
    bool fire_camera_shake_ignore_disabled;
    //Todo: Set type
    void* secondary_camera_shake; //camera_shake* secondary_camera_shake;
    void* player_hit_camera_shake; //camera_shake* player_hit_camera_shake;
    char attachment_point[32];
    int fire_sound;
    int secondary_sound;
    int upgrade_sound;
    int reload_sound;
    int reload_sound_delay;
    int no_ammo_sound;
    int special_sound;
    int flyby_sound;
    int num_weapon_personas;
    int npc_fire_sounds[16];
    float max_range;
    float red_range;
    float max_engagement_dist;
    float min_engagement_dist;
    float max_ai_penetrating_dist;
    //Todo: Set type
    void* npc_firing_pattern; //weapon_firing_pattern* npc_firing_pattern;
    //Todo: Set type
    void* npc_aim_drift_profile; //aim_drift_profile* npc_aim_drift_profile;
    weapon_trigger_type trigger_type;
    weapon_ammo_type ammo_type;
    unsigned __int16 magazine_size;
    unsigned __int16 magazine_start_num;
    unsigned __int16 max_rounds;
    unsigned __int16 max_rounds_upgrade;
    unsigned __int16 ammo_box_restock;
    unsigned __int16 to_min_spread;
    unsigned __int16 to_max_spread;
    char melee_group_index;
    char bullet_group_index;
    char tracer_frequency;
    char shots_per_round;
    float firing_sound_radius;
    float npc_refire_delay;
    float default_refire_delay;
    float prefire_delay;
    int default_reload_delay;
    damage_scaling_info low_scale_damage;
    damage_scaling_info high_scale_damage;
    explosion_info* m_explosion_info;
    explosion_info* m_ai_explosion_info;
    float fire_cone_dot;
    float even_spread_accuracy_dot;
    float max_spread;
    float min_spread;
    float fine_aim_max_spread;
    float fine_aim_min_spread;
    float npc_max_spread;
    float npc_min_spread;
    float spread_multiplier_run;
    float ragdoll_force_shoot;
    float ragdoll_chance;
    float recoil_camera_kick;
    float recoil_impulse;
    int out_of_ammo_reload_delay;
    float overheat_cool_down_time;
    float overheat_percent_per_shot;
    float dropped_ammo_scale;
    float bullet_hole_scale;
    float headshot_multiplier;
    float zoom_magnification;
    float autoaim_override;
    float npc_autoaim;
    float aim_assist;
    float player_move_speed_multiplier;
    float npc_move_speed_multiplier;
    float alert_multiplier;
    weapon_projectile_info projectile_info;
    human_melee_combat_move_id standing_primary_melee_attack;
    human_melee_combat_move_id standing_secondary_melee_attack;
    human_melee_combat_move_id standing_tertiary_melee_attack;
    human_melee_combat_move_id crouching_primary_melee_attack;
    human_melee_combat_move_id crouching_secondary_melee_attack;
    human_melee_combat_move_id crouching_tertiary_melee_attack;
};

struct air_bomb_info
{
    air_bomb_info& operator=(const air_bomb_info& other)
    {
        name = other.name;
        w_info = other.w_info;
        num_projectiles = other.num_projectiles;
        min_spread = other.min_spread;
        max_spread = other.max_spread;
        min_projectile_delay = other.min_projectile_delay;
        max_projectile_delay = other.max_projectile_delay;
        height = other.height;
        radius = other.radius;
        veh_radius = other.veh_radius;
        rate_min = other.rate_min;
        rate_max = other.rate_max;
        projectile_travel_time = other.projectile_travel_time;
        angle_min = other.angle_min;
        angle_max = other.angle_max;
        min_player_fvec_dot_prod = other.min_player_fvec_dot_prod;
        return *this;
    }

    char* name;
    weapon_info* w_info;
    int num_projectiles;
    float min_spread;
    float max_spread;
    float min_projectile_delay;
    float max_projectile_delay;
    float height;
    float radius;
    float veh_radius;
    float rate_min;
    float rate_max;
    float projectile_travel_time;
    float angle_min;
    float angle_max;
    float min_player_fvec_dot_prod;
};

struct projectile_info
{
    vector launch_direction;
    float launch_velocity;
    unsigned int seek_target;
};

struct air_bomb
{
    air_bomb_info* info;
    unsigned int focus;
    vector position;
    vector launch_position;
    projectile_info projectiles[5];
    int next_projectile;
    vector origin_position;
    float left_over_time;
    bool attacking;
    unsigned int force_attack_handle;
};