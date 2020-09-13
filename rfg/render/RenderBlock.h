#pragma once

struct rl_render_block
{
    unsigned __int16 material_map_idx;
    unsigned int start_index;
    unsigned int num_indices;
    unsigned int minimum_index;
    unsigned int maximum_index;
};