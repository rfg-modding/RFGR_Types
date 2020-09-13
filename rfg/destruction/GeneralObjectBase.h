#pragma once
#include "RFGR_Types/rfg/render/RlCommon.h"
#include "RFGR_Types/rfg/render/RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Matrix.h"
#include "RFGR_Types/rfg/Containers.h"

struct __declspec(align(8)) general_object_base
{
    et_sized_native_pointer<char> name;
    vector bmin;
    vector bmax;
    vector initial_pos;
    matrix initial_orient;
    unsigned __int16 collision_models[2];
    unsigned __int16 flags;
    __int16 mesh_subpieces[2];
    char padding[2];
};