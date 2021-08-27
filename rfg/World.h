#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "Containers.h"
#include "Timestamp.h"
#include "Object.h"
#include "rfg/stream2/cfile.h"

enum world_deserialize_state
{
    DS_IDLE = 0x0,
    DS_PENDING = 0x1,
    DS_COLLECT = 0x2,
    DS_COMPRESS = 0x3,
    DS_SAVE_FINALIZE = 0x4,
};

enum world_zone_state
{
    WZS_UNLOADED = 0x0,
    WZS_STREAMING = 0x1,
    WZS_LOADED = 0x2,
};

enum world_state_mode
{
    WSM_DEFAULT = 0x0,
    WSM_CHECKPOINT = 0x1,
    NUM_WORLD_STATE_MODES = 0x2,
};

enum layout_layer
{
    LAYER_LEVEL = 0x0,
    LAYER_TERRAIN = 0x1,
    NUM_LAYERS = 0x2,
};

struct grid_flags
{
    __int8 play_marauder_howl : 1;
    __int8 marauder_zone : 1;
};

struct __declspec(align(2)) grid_info
{
    unsigned __int16 gid;
    grid_flags flags;
};

struct district_flags
{
    __int8 allow_cough : 1;
    __int8 allow_amb_edf_civilian_dump : 1;
    __int8 play_capstone_unlocked_lines : 1;
    __int8 disable_morale_change : 1;
    __int8 disable_control_change : 1;
};

struct t_district
{
    const char* name;
    const char* liberated_radio_line;
    unsigned int localized_name_hash;
    unsigned int localized_name_hash_no_ar;
    float control;
    float control_max;
    float morale;
    float morale_max;
    float tech_level;
    int marauder_level;
    int edf_level;
    int edf_progression_level;
    bool liberated;
    district_flags flags;
    color col;
    color vfx_tint;
    int disc_layer;
    char index;
    const char* thumbnail;
    const char* load_screen_images[5];
    char num_load_screen_images;
    farray<grid_info, 21> list;
    t_district* next;
    t_district* prev;
};

struct territory
{
    const char* name;
    float tech_level_default;
    float tech_level_max;
    char index;
    t_district* districts;
    unsigned __int16* vertical_mask_zones;
    int num_v_mask_zones;
    unsigned __int16* horiz_mask_zones;
    int num_h_mask_zones;
};

struct stream_grid_cell
{
    unsigned int stream_mask;
    unsigned int srid[4];
    char grid_x;
    char grid_z;
    unsigned __int16 layer_index;
};

struct stream_layer
{
    struct masked_cell
    {
        stream_grid_cell* gc;
        void* n_region[4];//havok_bpo* n_region[4];
    };

    stream_grid_cell** cells;
    int num_cells;
    int dim_x;
    int dim_z;
    int cell_load_distance;
    float stream_radius;
    vector bmin;
    vector bmax;
    vector stream_bmin;
    vector stream_bmax;
    farray<stream_grid_cell*, 25> active_cells;
    farray<stream_layer::masked_cell, 50> masked_cells;
    vector cell_dim;
};

struct stream_grid
{
    stream_layer* layers;
    territory* terr;
    unsigned int ns_base;
    unsigned int ns_precache;
    unsigned int landmarks_srid;
    bool compact_super_emergency;
    timestamp_realtime compact_ts;
    timestamp_realtime compact_wait_ts;
    void* m_tmp_table;//str_data_hash_table<unsigned char, 255, 64, unsigned char>* m_tmp_table;
};

struct world_state_buf
{
    vector player_start_pos;
    matrix player_start_orient;
    vector player_start_pos_safehouse;
    matrix player_start_orient_safehouse;
    char* buf;
    int cur_size;
    int max_size;
};

struct save_load_info
{
    __int8 pending_new_game : 1;
    __int8 reset_destruction : 1;
    __int8 pending_save_game : 1;
    __int8 performing_save_game : 1;
    __int8 pending_save_state : 1;
    __int8 performing_save_state : 1;
    __int8 pending_single_zone : 1;
    __int8 save_game_warp : 1;
    __int8 game_save_checkpoint : 1;
    __int8 game_save_to_disk : 1;
    __int8 pending_load_game_from_memory : 1;
    __int8 auto_save_game : 1;
    __int8 saving_state_data : 1;
    __int8 player_start_at_safehouse : 1;
    vector player_start_pos;
    matrix player_start_orient;
};

struct zone_header
{
    unsigned int signature;
    unsigned int version;
    int num_objects;
    int num_handles;
    unsigned int district_hash;
    unsigned int flags;
};

//Todo: Turn this into a template
struct handle_manager_7280 //handle_manager<7280>
{
    char status[910];
    unsigned int last_bin;
    unsigned int last_slot;
    unsigned int upper_bits;
};

struct __declspec(align(4)) world_zone
{
    vector bmin;
    vector bmax;
    char name[64];
    world_zone_state state;
    zone_header* deserialize_header;
    cfile* deserialize_header_f;
    cfile* deserialize_f;
    world_state_buf stored_zone_state;
    void* zone_objp;//obj_zone* zone_objp;
    unsigned int srid;
    bool is_border_zone;
    handle_manager_7280 obj_handle_mgr;
    unsigned __int16 gid;
};

struct __declspec(align(8)) world
{
    bool mission_object_creation_mode;
    vector level_ambient;
    vector level_back_ambient;
    char last_loaded_territory[64];
    int max_world_objects;
    base_array<object*> all_objects;
    base_array<unsigned short> type_objects[53];
    base_array<unsigned short> subtype_objects[11];
    float tech_level;
    float tech_level_max;
    volatile unsigned int thread_id;
    char padding0[4];
    char object_handle_hash[72]; //dynamic_uint_hash_table<object *> object_handle_hash; //72
    char destroyed_object_table[8198]; //hash_table<unsigned int, &hash_uint, 1024, unsigned short> destroyed_object_table; //8198
    cfile* save_file;
    object* flagged_objects;
    object* current_flagged_object;
    char current_flagged_mode;
    world_deserialize_state deserialize_state;
    void* deserialize_pool; //virtual_mempool* deserialize_pool; //4
    farray<world_zone*, 32> deserialize_list;
    world_state_mode cur_world_state;
    world_state_buf stored_world_state[2];
    void* compress_stream; //zlib_stream* compress_stream;
    void* decompress_stream; //zlib_stream* decompress_stream;
    save_load_info sl_flags;
    void* pending_game_save_slot; //game_save_info* pending_game_save_slot;
    int dlc_bundle_id;
    char pending_filename[64];
    vector pending_game_load_warp_to_pos;
    matrix pending_game_load_warp_to_orient;
    volatile bool load_aborted;
    stream_grid* grid;
    vector stream_pos;
    int num_territory_zones;
    world_zone** all_zones;
    world_zone* global_zone_grid[257];
    bool is_territory;
    char territory_name[128];
    int num_streaming_objects;
    bool stub_serialization_in_progress;
};
static_assert(sizeof(world) == 11192, "sizeof(world) must equal 11192 to match game memory. Something broke if you're seeing this.");