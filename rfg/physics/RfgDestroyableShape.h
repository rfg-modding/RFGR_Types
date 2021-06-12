#pragma once
#include "rfg/Vector.h"
#include "rfg/Matrix.h"
#include "rfg/Timestamp.h"
#include "rfg/Containers.h"

struct rfg_destroyable_shape;
struct rfg_mover;

struct hkpBvTreeShape
{
    unsigned char data[20];
};

struct hkpShapeContainer
{
    unsigned char data[4];
};

struct hkpShape
{
    unsigned char data[16];
};

struct rfg_subpiece_base
{
    vector prel_bmin;
    vector prel_bmax;
    vector pos;
    vector center_of_mass;
    float mass;
    unsigned int dlod_key;
    et_ptr_offset<unsigned short, 0> links;
    char physical_material_index;
    char shape_type;
    char num_links;
    char flags;
};

struct rfg_subpiece_base_extra_data
{
    et_ptr_offset<hkpShape, 1> shape;
    unsigned __int16 collision_model;
    unsigned __int16 render_subpiece;
    unsigned int h;
};

struct rfg_subpiece
{
    int anchor_yield;
    et_ptr_offset<unsigned short, 0> links;
    et_ptr_offset<rfg_destroyable_shape, 1> my_owner_gm_handle;
    unsigned __int16 next;
    unsigned __int16 prev;
    unsigned __int16 shard_next;
    unsigned __int16 shard_prev;
    unsigned __int16 stress_next;
    unsigned __int16 stress_prev;
    unsigned int flags;
    unsigned __int16 dynamic_link_index;
    unsigned __int16 eval_info_index;
    unsigned __int16 impulse_info_index;
    char modified_framecount;
    char num_links;
};

struct rfg_link
{
    int yield_limit;
};

struct rfg_dlod
{
    et_ptr_offset<rfg_destroyable_shape, 1> owner;
    et_ptr_offset<rfg_subpiece, 0> subpieces;
    char active_pieces;
    char flags;
    char max_pieces;
    char padding[1];
};

struct fp_aabb
{
    __int16 min_x;
    __int16 min_y;
    __int16 min_z;
    __int16 max_x;
    __int16 max_y;
    __int16 max_z;
};

struct rfg_rbb_node
{
    int num_objects;
    fp_aabb aabb;
    et_ptr_offset<unsigned char, 0> node_data;
};

struct rfg_dlod_base
{
    unsigned int name_hash;
    vector pos;
    matrix orient;
    unsigned __int16 render_subpiece;
    unsigned __int16 first_piece;
    char max_pieces;
    char padding[3];
};

struct rfg_link_base
{
    int yield_max;
    float area;
    __int16 obj[2];
    char flags;
    char padding[3];
};

struct rfg_destroyable_instance_data
{
    unsigned int objects_offset;
    unsigned int links_offset;
    unsigned int dlods_offset;
    unsigned int data_size;
    et_ptr_offset<unsigned char, 0> buffer;
};

struct  rfg_base_destroyable_shape
{
    et_ptr_offset<rfg_rbb_node, 0> aabb_tree;
    et_ptr_offset<rfg_subpiece_base, 0> base_objects;
    et_ptr_offset<rfg_subpiece_base_extra_data, 0> base_extra_data;
    int num_objects;
    et_ptr_offset<rfg_link_base, 0> base_links;
    int num_links;
    et_ptr_offset<rfg_dlod_base, 0> base_dlods;
    int num_dlods;
    et_ptr_offset<rfg_destroyable_instance_data, 0> inst_data;
    et_ptr_offset<unsigned char, 0> transform_buffer;
    float base_structural_mass;
};

struct rfg_destroyable_shape : hkpBvTreeShape, hkpShapeContainer
{
    vector center_of_mass_accum;
    rfg_subpiece* objects;
    rfg_link* links;
    rfg_dlod* dlods;
    rfg_mover* mover_p;
    rfg_rbb_node* aabb_tree;
    rfg_rbb_node* override_tree;
    rfg_base_destroyable_shape* parent;
    unsigned __int16 child_obj_list;
    unsigned __int16 transfer_child_obj_list;
    unsigned __int16 shardify_q;
    unsigned __int16 anchor_depth;
    int num_existing_child_shapes;
    int calc_rbb_child_count;
    float structural_mass;
    float base_structural_mass;
    int flags;
    vector center_of_mass;
    vector local_bmin;
    vector local_bmax;
    float mass;
    unsigned int shape_uid;
    rfg_destroyable_shape* sib_next;
    rfg_destroyable_shape* sib_prev;
    timestamp destruction_mode_timer;
};