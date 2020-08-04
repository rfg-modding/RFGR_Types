#pragma once
#include "Object.h"
#include "Containers.h"

struct nav_cell
{
    et_ptr_offset<nav_cell, 1> adjacent_cells[3];
    unsigned int navp;
    unsigned int heap_session_id;
    unsigned __int16 vertices[3];
    unsigned __int16 compound_hull_reference;
    unsigned __int16 heap_data_index;
    char zone_id;
    char flags;
};

struct $59270AE2AEC9209D4EF019B9D8BC04A0
{
    __int8 is_open : 1;
    __int8 on_path : 1;
};

struct navpoint_heap_data
{
    float arrival_cost;
    float est_cost_to_goal;
    unsigned int session_id;
    unsigned __int16 heap_index;
    $59270AE2AEC9209D4EF019B9D8BC04A0 flags;
    char disabled_by;
};


struct nav_point_flags
{
    __int8 single_node_link : 1;
    __int8 dont_follow_road : 1;
    __int8 ignore_lanes : 1;
    __int8 door : 1;
    __int8 start_branch : 1;
    __int8 end_branch : 1;
    __int8 bridge : 1;
};

struct navpoint : object
{
    nav_cell* nav_cell_ptr;
    navpoint* links[10];
    float radius;
    float speed_limit;
    navpoint* prev_path_navpoint;
    navpoint* next_path_navpoint;
    navpoint_heap_data heap_data;
    unsigned __int16 set;
    __int16 num_links;
    char link_disabled_by[10];
    char type;
    nav_point_flags nav_flags;
    unsigned int next_navpoint_internal;
};
