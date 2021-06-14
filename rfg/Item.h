#pragma once
#include "Vector.h"
#include "Explosion.h"
#include "render_lib/Material.h"
#include "render_lib/Renderable.h"
#include "render_lib/Mesh.h"

struct weapon_info;
struct human;
struct character_instance;

enum prop_type
{
    PROP_TYPE_NONE = 0xFFFFFFFF,
    PROP_TYPE_AMMO = 0x0,
    PROP_TYPE_CLIP = 0x1,
    PROP_TYPE_ACCESSORY1 = 0x2,
    PROP_TYPE_SCOPE = 0x3,
    PROP_TYPE_SILENCER = 0x4,
    PROP_TYPE_CODE_DESIGNATED = 0x5,
    PROP_TYPE_HEAD_PROP = 0x6,
    PROP_TYPE_GRENADE_1 = 0x7,
    PROP_TYPE_GRENADE_2 = 0x8,
    PROP_TYPE_GRENADE_3 = 0x9,
    PROP_TYPE_ACCESSORY_MISC = 0xA,
    PROP_TYPE_SATCHEL_CHARGE = 0xB,
    PROP_TYPE_EYE_WEAR = 0xC,
    PROP_TYPE_TORSO = 0xD,
    PROP_TYPE_EARRING1 = 0xE,
    PROP_TYPE_EARRING2 = 0xF,
    PROP_TYPE_WAIST = 0x10,
    PROP_TYPE_JETPACK = 0x11,
    PROP_TYPE_MP_FLAG = 0x12,
    PROP_TYPE_BACK = 0x13,
    NUM_PROP_TYPES = 0x14,
};

struct inv_item_info
{
    char* name;
    checksum_stri name_checksum;
    char* display_name;
    int cost;
    int default_count;
    int max_item;
    char* description;
    weapon_info* w_info;
    char item_order;
    bool(__cdecl* use)();
};

struct item_info
{
    struct item_prop
    {
        struct flags//$71CEC94321954E1EE07AD4E683FB18F0
        {
            unsigned __int32 offhand : 1;
        };

        char* prop_name;
        char* prop_tag;
        prop_type type;
        item_info::item_prop::flags flags;
    };

    struct special_flags //$5366E9642BD3DD59EF50DFB8CFD3E258
    {
        __int8 high_res_texture_requested : 1;
        __int8 high_res_texture_loaded : 1;
        __int8 high_res_texture_request_unload : 1;
    };

    char* name;
    char* smesh_name;
    char* cmesh_name;
    char* rig_name;
    char* anim_set_name;
    char* pickup_smesh_name;
    unsigned int srid;
    unsigned int high_res_srid;
    bool multiplayer_only;
    bool shared_backpack;
    int flags;
    bool no_peg_load;
    unsigned int material_effect_id;
    int num_props;
    item_info::item_prop props[6];
    item_info::special_flags special_flags;
    material* high_res_material;
    float mass;
    float linear_damping;
    float angular_damping;
    float restitution;
    float friction;
    vector angular_velocity;
    int respawn_delay;
    float touch_arg1;
    float touch_arg2;
    //Todo: Add 'item' type and fix this
    bool(__cdecl* touch)(human*, void*, bool*, bool*);//bool(__cdecl* touch)(human*, item*, bool*, bool*);
    int damage_flags;
    int hitpoints;
    int pickup_snd;
    int pickup_snd_2;
    int spin_time;
    int m_foley_collision;
    int cloth_foley;
    inv_item_info* safehouse_weapon;
    explosion_info* m_explosion_info;
};

struct obj_item_flags
{
    unsigned __int32 respawn : 1;
    unsigned __int32 no_physics : 1;
    unsigned __int32 simulate : 1;
    unsigned __int32 props_created : 1;
    unsigned __int32 item_held : 1;
    unsigned __int32 no_save : 1;
    unsigned __int32 preplaced : 1;
    unsigned __int32 update_attach_point : 1;
    unsigned __int32 dropped_by_player : 1;
    unsigned __int32 touched_last_frame : 1;
    unsigned __int32 character_prop : 1;
    unsigned __int32 attached_cloth_sim : 1;
    unsigned __int32 doing_errode : 1;
    unsigned __int32 cast_shadows : 1;
    unsigned __int32 cast_drop_shadows : 1;
    unsigned __int32 xray_visible : 1;
    unsigned __int32 dont_dampen_impulse : 1;
    unsigned __int32 shield_initialized : 1;
};

struct special_purpose_flags
{
    unsigned __int32 is_ammo_box : 1;
    unsigned __int32 use_enabled : 1;
    unsigned __int32 arc_welder_is_arcing : 1;
    unsigned __int32 fading_from_nano : 1;
    unsigned __int32 using_high_res_texture : 1;
};

struct item_damage_info
{
    struct flags//$9EB7C499D053FB1827280F3CE5C38DFD
    {
        unsigned __int32 can_explode : 1;
        unsigned __int32 damaged_by_bullets : 1;
        unsigned __int32 damaged_by_collisions : 1;
        unsigned __int32 damaged_by_explosions : 1;
        unsigned __int32 damaged_by_melee : 1;
        unsigned __int32 damaged_by_vehicles : 1;
    };

    int hitpoints;
    item_damage_info::flags flags;
};

struct  item : object
{
    struct resource_dependent_data
    {
        static_mesh* smesh;
        rl_mesh_instance* smesh_instance_p;
        static_mesh* pickup_smesh;
        rl_mesh_instance* pickup_smesh_instance_p;
    };

    item* prev;
    item* next;
    item_info* info;
    object_stream_resource<item::resource_dependent_data> rdd;
    character_instance* char_inst;
    float render_alpha;
    float m_stealth_percent;
    bool casts_transparent_shadows;
    object_render_distance render_distance;
    float touch_arg1_override;
    float touch_arg2_override;
    float mass_override;
    unsigned int collision_type;
    prop_type m_prop_type;
    timestamp deletion_timer;
    timestamp respawn_timer;
    timestamp touch_delay_timer;
    timestamp cloth_deletion_timer;
    timestamp dropped_timer;
    unsigned int m_nav_cell_detour_request_handle;
    obj_item_flags item_flags;
    vector last_pos;
    unsigned int srid;
    //Todo: Add type
    void* cloth_sim; //cloth_simulation* cloth_sim;
    salvage_material_type salvage_material;
    unsigned int salvage_effect;
    int m_foley_collision_instance;
    void* mp_sim_state; //multi_sim_state<multi_item_state>* mp_sim_state;
    float pickup_value;
    special_purpose_flags special_flags;
    item_damage_info damage_info;
    bool default_batchable_setting;
    char xray_material;
    char xray_render_alpha;
    unsigned int owner_handle;
};