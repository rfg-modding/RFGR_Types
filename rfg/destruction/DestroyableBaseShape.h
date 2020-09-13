#pragma once
#include "DlodBase.h"
#include "GeneralObjectBase.h"
#include "LinkBase.h"
#include "RbbNode.h"
#include "SubpieceBase.h"
#include "RFGR_Types/rfg/render/RlCommon.h"
#include "RFGR_Types/rfg/render/RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Matrix.h"
#include "RFGR_Types/rfg/Containers.h"

struct rfg_destroyable_instance_data
{
    unsigned int objects_offset;
    unsigned int links_offset;
    unsigned int dlods_offset;
    unsigned int data_size;
    et_ptr_offset<unsigned char, 0> buffer;
};

struct rfg_base_destroyable_shape
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