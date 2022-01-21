#include "common/Typedefs.h"
#include "rfg/Vector.h"
#include "rfg/Matrix.h"

struct prop_name
{
    const char* str;
    unsigned int crc;
};

struct obj_prop
{
    unsigned __int16 type;
    unsigned __int16 size;
    unsigned int name_crc;
    char data[0]; //Note: This field is 0 bytes. It denotes the data at the end of the struct instance.
};
static_assert(sizeof(obj_prop) == 8, "sizeof(obj_prop) must be 8 bytes");

struct rfg_prop_block
{
    unsigned __int16 num_props;
    unsigned __int16 owner;
    unsigned __int16 buf_pos;
    unsigned __int16 buf_size;
    char* prop_list;
};

struct obj_prop_block : rfg_prop_block
{

};

struct obj_mover_props : obj_prop_block
{

};

struct obj_rfgm_props : obj_mover_props
{

};

struct gm_prop_block : obj_mover_props
{

};