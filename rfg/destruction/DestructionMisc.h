#pragma once
#include "RFGR_Types/rfg/Matrix43.h"

struct c_script_point
{
    matrix43 transform;
    char name[32];
    char sub_piece_name[32];
    unsigned int destroyable_idx;
};

struct c_object_identifier
{
    unsigned int unique_id;
    char name[24];
    int object_index;
    unsigned int is_destroyable;
    unsigned int num_snap_points;
    matrix43 snap_points[10];
};

struct c_object_skirt_edge
{
    vector point[2];
    vector norm[2];
};

struct c_object_skirt
{
    unsigned __int16 rl_submesh_idx;
    int num_weld_edges;
    et_sized_native_pointer<c_object_skirt_edge> weld_edges;
};

struct __declspec(align(8)) c_light_clip_object
{
    et_sized_native_pointer<char> name;
    vector bmin;
    vector bmax;
    vector pos;
    matrix orient;
    unsigned __int16 submesh_idx;
    unsigned __int16 object_identifier_index;
};

struct rl_fp_kdtree_node
{
    __int16 plane_offset;
    unsigned __int16 plane_axis;
    unsigned __int16 left_offset;
    unsigned __int16 right_offset;
    unsigned __int16 leaf_offset;
    unsigned __int16 num_leaves;
    unsigned int pad;
};

struct rl_fp_aabb
{
    __int16 min_x;
    __int16 min_y;
    __int16 min_z;
    __int16 max_x;
    __int16 max_y;
    __int16 max_z;
};

struct rl_fp_kdtree_leaf
{
    rl_fp_aabb aabb;
    unsigned int data;
};

struct rl_fp_kdtree_base_data
{
    int num_nodes;
    et_ptr_offset<rl_fp_kdtree_node, 0> nodes;
    int num_leaves;
    et_ptr_offset<rl_fp_kdtree_leaf, 0> leaves;
    et_ptr_offset<unsigned short, 0> leaf_map;
};