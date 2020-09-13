#pragma once
#include "RFGR_Types/rfg/render/RlCommon.h"
#include "RFGR_Types/rfg/render/RenderBlock.h"
#include "RFGR_Types/rfg/Vector.h"
#include "RFGR_Types/rfg/Matrix.h"
#include "RFGR_Types/rfg/Containers.h"

struct rfg_dlod_base
{
    unsigned int name_hash;
    vector pos;
    matrix orient;
    unsigned __int16 render_subpiece;
    unsigned __int16 first_piece;
    char max_pieces;
    char padding[3];
};