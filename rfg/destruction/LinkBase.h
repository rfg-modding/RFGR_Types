#pragma once
#include "RFGR_Types/rfg/render/RlCommon.h"
#include "RFGR_Types/rfg/render/RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Matrix.h"
#include "RFGR_Types/rfg/Containers.h"

struct rfg_link_base
{
    int yield_max;
    float area;
    __int16 obj[2];
    char flags;
    char padding[3];
};