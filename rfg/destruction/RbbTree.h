#pragma once
#include "RFGR_Types/rfg/Vector.h"

struct rbb_tree_node
{
    int num_objects;
    vector mn;
    vector mx;
    char* node_data;
};

struct rbb_tree
{
    int obj_size;
    void(__cdecl* leaf_cb)(void*);
    rbb_tree_node* nodes;
};