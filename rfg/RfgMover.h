#pragma once
#include "ObjectMover.h"
#include "physics/RfgDestroyableShape.h"

enum rfg_move_type
{
    RFGM_INVALID = 0xFFFFFFFF,
    RFGM_FIXED = 0x0,
    RFGM_NORMAL = 0x1,
    RFGM_LITE = 0x2,
    RFGM_ULTRA_LITE = 0x3,
    RFGM_WORLD_ONLY = 0x4,
    RFGM_NO_COLLISION = 0x5,
};

struct rfg_mover_temporary_data
{
    enum data_type
    {
        INVALID_DATA_TYPE = 0xFFFFFFFF,
        WORLD_ANCHOR = 0x0,
        DYNAMIC_LINK = 0x1,
        SHAPE_STATE = 0x2,
        DECAL_LIST = 0x3,
        NUM_STATE_DATA_TYPES = 0x4,
    };

    char* data_buf[4];
    unsigned __int16 data_size[4];
};

struct rfg_mover_flags
{
    unsigned __int32 under_stress : 1;
    unsigned __int32 run_stress_on_stream : 1;
    unsigned __int32 collapse_effect : 1;
    unsigned __int32 invulnerable : 1;
    unsigned __int32 game_destroyed : 1;
    unsigned __int32 fully_destroyed : 1;
    unsigned __int32 large_explosion : 1;
    unsigned __int32 pristine : 1;
    unsigned __int32 mp_no_fade_destroy : 1;
    unsigned __int32 render_xform_dirty : 1;
    unsigned __int32 is_ai_structure : 1;
    unsigned __int32 is_ai_building : 1;
    unsigned __int32 is_ai_subpiece : 1;
    unsigned __int32 is_ai_composite : 1;
    unsigned __int32 updating_anchors : 1;
    unsigned __int32 plume_on_death : 1;
    unsigned __int32 one_of_many : 1;
    unsigned __int32 mining : 1;
    unsigned __int32 supply_crate : 1;
    unsigned __int32 regrow_on_stream_begin : 1;
    unsigned __int32 regrow_on_stream_finish : 1;
    unsigned __int32 inherit_damage_pct : 1;
    unsigned __int32 rebuild : 1;
    unsigned __int32 propaganda : 1;
    unsigned __int32 building : 1;
};

struct rfg_mover : object_mover
{
    struct resource_dependent_data
    {
        rfg_destroyable_shape* shape;
        //Todo: Add type
        void* model_instance_p; //rl_destroyable_model_instance* model_instance_p;
    };

    rfg_move_type move_type;
    float damage_pct;
    float current_structural_mass;
    rfg_mover_temporary_data* state_data;
    float game_destroyed_pct;
    rfg_mover_flags flags;
    //Not included since RSL is SP only currently
    void* mp_info; //multi_rfg_mover_info* mp_info;
    unsigned __int16 explosion_event_index;
    unsigned __int16 damaged_subpiece_event_first_index;
    unsigned __int16 repair_event_list;
    __int16 stress_test_count;
    timestamp stress_test_delay;
    timestamp slice_delay;
    rfg_mover* stress_next;
    rfg_mover* stress_prev;
    unsigned int restricted_area;
    int salvage_num_pieces;
    unsigned int destruction_uid;
    int damage_report_handle;
    int stream_out_time;
    timestamp stress_sound_propagate_timer;
    float accumulated_load_amount;
    unsigned int process_shardify_candidate_index;
    object_stream_resource<rfg_mover::resource_dependent_data> rdd;
    unsigned int dead_smoke_plume_effect;
    rfg_mover* pre_stream_next;
    rfg_mover* pre_stream_prev;
    //Todo: Add type
    void* m_glass_obj_list; //glass_obj* m_glass_obj_list;
    timestamp damage_sound_propagate_timer;
};