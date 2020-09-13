#pragma once
#include "RlCommon.h"
#include "RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Containers.h"
#include "RFGR_Types/rfg/keen/render/RenderGeometry.h"

struct rl_material_map_data_runtime
{
    unsigned int* materials;
    unsigned int num_materials;
};

struct __declspec(align(4)) rl_material_map : rl_base_object
{
    rl_material_map_data_runtime m_data;
    bool m_isSet;
};
