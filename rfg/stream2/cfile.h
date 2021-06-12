#pragma once

enum cf_search_types
{
    CF_SEARCH_NONE = 0xFFFFFFFF,
    CF_SEARCH_STANDARD = 0x0,
    CF_SEARCH_PACKFILE = 0x1,
    CF_SEARCH_VDIR = 0x2,
    CF_SEARCH_NUM_TYPES = 0x3,
};

enum cf_io_media_types
{
    CF_IO_MEDIA_NONE = 0xFFFFFFFF,
    CF_IO_MEDIA_HDD = 0x0,
    CF_IO_MEDIA_DVD = 0x1,
    CF_IO_MEDIA_HOST = 0x2,
    CF_IO_MEDIA_MEMORY = 0x5,
    CF_IO_MEDIA_NUM_TYPES = 0x6,
};

enum cf_io_access_types
{
    CF_IO_ACCESS_NONE = 0xFFFFFFFF,
    CF_IO_ACCESS_STANDARD = 0x0,
    CF_IO_ACCESS_PACKFILE = 0x1,
    CF_IO_ACCESS_MEMORY = 0x2,
    CF_IO_ACCESS_UNKNOWN = 0x3,
    CF_IO_ACCESS_NUM_TYPES = 0x4,
};

enum cfmode_type
{
    CF_MODE_NONE = 0x0,
    CF_MODE_READ = 0x1,
    CF_MODE_WRITE = 0x2,
};

enum cf_error_codes
{
    CF_ERROR_NONE = 0x0,
    CF_ERROR_READ = 0x1,
    CF_ERROR_WRITE = 0x2,
    CF_ERROR_ABORT = 0x3,
    CF_ERROR_NUM_CODES = 0x4,
};

enum vlib_platform
{
    PLATFORM_NONE = 0xFFFFFFFF,
    PLATFORM_PC = 0x0,
    PLATFORM_PS2 = 0x1,
    PLATFORM_PS3 = 0x2,
    PLATFORM_XBOX = 0x3,
    PLATFORM_XBOX2 = 0x4,
    PLATFORM_XBONE = 0x5,
    PLATFORM_PS4 = 0x6,
    PLATFORM_SWITCH = 0x7,
    NUM_VLIB_PLATFORMS = 0x8,
};

//union cfile_handle //$E6E582DEAE142D71F38CAABECEAEA2E0
//{
//    cf_keen_open_file* m_standard_fp;
//    keen_cf_packfile_handle* m_packfile_fp;
//    cf_memory_handle* _m_memory_fp;
//};

struct cfile
{
    char name[65];
    char full_pathname[257];
    cf_search_types m_searched_system;
    cf_io_access_types m_access_type;
    void* handle;//cfile_handle handle;
    cf_io_media_types m_media_type;
    cfmode_type mode;
    cf_error_codes m_error_code;
    unsigned int pos;
    unsigned int size;
    unsigned int max_write_size;
    unsigned int m_flags;
};

static string to_string(cf_search_types value)
{
    switch (value)
    {
    case CF_SEARCH_NONE:
        return "CF_SEARCH_NONE";
    case CF_SEARCH_STANDARD:
        return "CF_SEARCH_STANDARD";
    case CF_SEARCH_PACKFILE:
        return "CF_SEARCH_PACKFILE";
    case CF_SEARCH_VDIR:
        return "CF_SEARCH_VDIR";
    case CF_SEARCH_NUM_TYPES:
        return "CF_SEARCH_NUM_TYPES";
    default:
        return "INVALID_ENUM";
    }
}

static string to_string(cf_io_media_types value)
{
    switch (value)
    {
    case CF_IO_MEDIA_NONE:
        return "CF_IO_MEDIA_NONE";
    case CF_IO_MEDIA_HDD:
        return "CF_IO_MEDIA_HDD";
    case CF_IO_MEDIA_DVD:
        return "CF_IO_MEDIA_DVD";
    case CF_IO_MEDIA_HOST:
        return "CF_IO_MEDIA_HOST";
    case CF_IO_MEDIA_MEMORY:
        return "CF_IO_MEDIA_MEMORY";
    case CF_IO_MEDIA_NUM_TYPES:
        return "CF_IO_MEDIA_NUM_TYPES";
    default:
        return "INVALID_ENUM";
    }
}