#pragma once
#include "RFGR_Types/rfg/render/RlCommon.h"
#include "RFGR_Types/rfg/render/RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Matrix.h"
#include "RFGR_Types/rfg/Containers.h"

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