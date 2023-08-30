#pragma once
#include "ObjectMover.h"
#include "physics/RfgDestroyableShape.h"
#include "render_lib/Renderable.h"

//Formerly $002CCC9B1632BB5CD0DDD2EA2984EB06
union general_mover_interaction_type
{
    unsigned int collision_type;
    int move_type;
};

struct general_mover : object_mover
{
    struct resource_dependent_data
    {
        rfg_destroyable_shape* shape;
        rl_renderable_instance* model_instance_p;
    };

    unsigned int gm_flags;
    general_mover_interaction_type interaction_type;
    unsigned int subpiece_index;
    unsigned int name_checksum;
    int gobj_index;
    //Left out for now since Reconstructor is SP only
    void* mp_sim_state; //multi_sim_state<multi_mover_state>* mp_sim_state;
    unsigned int destruction_uid;
    object_stream_resource<general_mover::resource_dependent_data> rdd;
    general_mover* pre_stream_next;
    general_mover* pre_stream_prev;
    unsigned int original_object;
    timestamp last_damaged_timer;
};