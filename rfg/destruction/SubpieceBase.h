#pragma once
#include "RFGR_Types/rfg/render/RlCommon.h"
#include "RFGR_Types/rfg/render/RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Matrix.h"
#include "RFGR_Types/rfg/Containers.h"

struct rfg_subpiece_base_extra_data
{
    int shape;//et_ptr_offset<hkpShape, 1> shape;
    unsigned __int16 collision_model;
    unsigned __int16 render_subpiece;
    unsigned int h;
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