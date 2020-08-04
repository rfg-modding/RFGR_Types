#pragma once
#include "cfile.h"

enum stream2_container_mode
{
    SCM_NONE = 0x0,
    SCM_CONTAINER = 0x1,
    SCM_PRIM = 0x2,
};

enum stream2_priority
{
    STREAM_PRIORITY_INVALID = 0x0,
    STREAM_PRIORITY_AUDIO_PRECACHE_LOAD = 0x7F,
    STREAM_PRIORITY_NORMAL = 0x80,
    STREAM_PRIORITY_AUDIO_STREAM_LOAD = 0x80,
    STREAM_PRIORITY_AUDIO_CACHE_LOAD = 0x80,
    STREAM_PRIORITY_HIGH = 0xC8,
    STREAM_PRIORITY_OBJECT = 0xC8,
    STREAM_PRIORITY_HUMAN = 0xC9,
    STREAM_PRIORITY_AUDIO_FETCH_STREAMING_SOUND = 0xFA,
    STREAM_PRIORITY_UI_DOC = 0xFD,
    STREAM_PRIORITY_TERRAIN = 0xFE,
    STREAM_PRIORITY_MAX = 0xFF,
};

enum stream2_category
{
    STREAM_CAT_GENERAL = 0x0,
    STREAM_CAT_LEVEL = 0x1,
    STREAM_CAT_AUDIO = 0x2,
    STREAM_CAT_VEHICLES = 0x3,
    STREAM_CAT_HUMANS = 0x4,
    NUM_STREAM_CATEGORIES = 0x5,
};

struct __declspec(align(4)) stream2_prim_def
{
    struct s2pf_flags
    {
        __int8 debug_skippable : 1;
        __int8 alloc_split : 1;
        __int8 load_threaded : 1;
    };

    bool(__cdecl* load_cb)(const char*, unsigned int, char*, int, char*, int);
    void(__cdecl* unload_cb)(const char*, unsigned int);
    int cpu_align;
    int gpu_align;
    stream2_prim_def::s2pf_flags flags;
    char* name;
    const char* cpu_ext[2];
    const char* gpu_ext[2];
    int total_allocated;
    char prim_type;
};

struct stream2_prim
{
    char* name;
    stream2_prim_def* pdef;
    int cpu_size;
    int gpu_size;
    char* cpu_data;
    char* gpu_data;
    stream2_prim* next;
    stream2_prim* prev;
    char split_ext_index;
    char flags;
    __int16 allocator_idx;
    __int16 ref_count;
    __int16 container_ref_count;
};

struct stream2_container_type_reg
{
    char container_type;
    char name[64];
    void(__cdecl* load_cb)(unsigned int);
    void(__cdecl* unload_cb)(unsigned int);
    char allocator_type;
    stream2_container_mode mode;
};

struct stream2_container
{
    struct last_error_c
    {
        char error_str[512];
    };
    struct entry
    {
        __int8 enable : 1;
        __int8 user0 : 1;
        __int8 user1 : 1;
        char flags;
        stream2_prim* prim;
    };

    char* cpu_allocated;
    char* gpu_allocated;
    __int16 ref_count;
    __int16 pf_chain_size;
    unsigned int pf_base_offset;
    int pf_total_compressed_read_size;
    unsigned int* pf_chain_read_size;
    void** pf_chain_read_dest;
    stream2_container::entry* entries;
    __int16 num_entries;
    __int16 flags;
    __int16 cur_priority;
    __int16 cur_category;
    stream2_container_def* cdef;
    char* name;
    stream2_container::last_error_c* last_error;
    stream2_container* q_next;
    stream2_container* q_prev;
    stream2_container* next;
    stream2_container* prev;
};

struct stream2_os_file
{
    char filename[64];
    unsigned int offset;
    unsigned int size;
    char* dest;
    __int8 chain_read : 1;
    __int8 encrypted : 1;
    int chain_num_reads;
    unsigned int* chain_size;
    char** chain_dest;
    unsigned __int16 priority;
    unsigned __int16 category;
    cfile* preopened;
};

struct stream2_prim_record
{
    char name[64];
    char type;
    char allocator;
    char flags;
    char split_ext_index;
    int cpu_size;
    int gpu_size;
};

struct stream2_container_header
{
    unsigned int signature;
    unsigned __int16 version;
    unsigned __int16 num_containers;
};