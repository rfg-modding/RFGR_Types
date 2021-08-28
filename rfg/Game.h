#pragma once

enum game_state : unsigned int
{
    GS_NONE = 0xFFFFFFFF,
    GS_MAINMENU = 0x0,
    GS_GAMEPLAY = 0x1,
    GS_LOAD = 0x2,
    GS_BOOT = 0x3,
    GS_MULTI_INIT = 0x4,
    GS_MULTI_SHUTDOWN = 0x5,
    GS_CONNECTING_TO_INVITE = 0x6,
    GS_MAINMENU_OPTIONS = 0x7,
    GS_MAINMENU_OPTIONS_DISPLAY = 0x8,
    GS_MAINMENU_OPTIONS_AUDIO = 0x9,
    GS_MAINMENU_OPTIONS_LIVE = 0xA,
    GS_MAINMENU_OPTIONS_LIVE_QUICKMATCH = 0xB,
    GS_MAINMENU_OPTIONS_GAME_OPTIONS = 0xC,
    GS_MAINMENU_OPTIONS_EXTRAS = 0xD,
    GS_CHEATS = 0xE,
    GS_INGAME_OPTIONS = 0xF,
    GS_PLAYER_DEATH_OPTIONS = 0x10,
    GS_SONY_OPTIONS = 0x11,
    GS_CONTROLLER_OPTIONS = 0x12,
    GS_WRECKING_CREW_MAIN_MENU = 0x13,
    GS_WRECKING_CREW_CHARACTER_SELECT = 0x14,
    GS_WRECKING_CREW_SCOREBOARD = 0x15,
    GS_MULTIPLAYER_LIVE = 0x16,
    GS_MULTIPLAYER_CHANGE_MATCHMAKING = 0x17,
    GS_MULTIPLAYER_SEARCH_MATCHMAKING = 0x18,
    GS_MULTIPLAYER_GAME_LOBBY = 0x19,
    GS_MULTIPLAYER_PARTY_LOBBY = 0x1A,
    GS_MULTIPLAYER_PARTY_OPTIONS = 0x1B,
    GS_MULTIPLAYER_SYSLINK = 0x1C,
    GS_MULTIPLAYER_SYSLINK_FIND_SERVERS = 0x1D,
    GS_MULTIPLAYER_CHANGE_GAME_OPTIONS = 0x1E,
    GS_MULTIPLAYER_PLAYER_SELECT = 0x1F,
    GS_MULTIPLAYER_XP_TALLY = 0x20,
    GS_MULTIPLAYER_RESULTS = 0x21,
    GS_MULTIPLAYER_SCOREBOARD = 0x22,
    GS_MULTIPLAYER_STATS = 0x23,
    GS_MULTIPLAYER_TUTORIALS = 0x24,
    GS_INGAME_FULLSCREEN_MAP = 0x25,
    GS_INGAME_MISSION_BRIEFING = 0x26,
    GS_INGAME_ACTIVITY_BRIEFING = 0x27,
    GS_INGAME_MISSION_COMPLETE = 0x28,
    GS_INGAME_ACTIVITY_COMPLETE = 0x29,
    GS_INGAME_UPGRADES_HUD = 0x2A,
    GS_INGAME_HANDBOOK_HUD = 0x2B,
    GS_INGAME_RAIL_DRIVER_HUD = 0x2C,
    GS_INGAME_DISTRICT_LIVERATION = 0x2D,
    GS_INGAME_WEAPON_CABINET = 0x2E,
    GS_LOAD_CUTSCENE = 0x2F,
    GS_MAINMENU_IDLE = 0x30,
    GS_VIDEO_CUTSCENE_PLAY = 0x31,
    GS_SAVE_LOAD_SCREEN = 0x32,
    GS_PS3_DLC = 0x33,
    GS_VIEW_DLC_SCREEN = 0x34,
    GS_STATS_SCREEN = 0x35,
    GS_CREDITS = 0x36,
    GS_VERIFY_SAVEGAME = 0x37,
    GS_SHUTDOWN = 0x38,
    GS_DLC_INIT = 0x39,
    GS_DLC_SHUTDOWN = 0x3A,
    GS_WC_INIT = 0x3B,
    GS_WC_SHUTDOWN = 0x3C,
    GS_RESOLUTION_CHANGE = 0x3D,
    GS_QUICK_PAUSE = 0x3E,
    GS_MULTIPLAYER_LIVE_FIND_SERVERS = 0x3F,
    GS_NUM_STATES = 0x40,
};

struct __declspec(align(4)) state_info
{
    void(__cdecl* enter)(game_state state);
    void(__cdecl* exit)(game_state state);
    bool(__cdecl* exit_notify)(game_state state);
    void(__cdecl* process)();
    void(__cdecl* handshake)(void* renderer);//void(__cdecl* handshake)(rl_renderer* renderer);
    void(__cdecl* render)(void* renderer);//void(__cdecl* render)(rl_renderer* renderer);
    bool transparent;
    bool pause_beneath;
    int user_flags;
    bool hide_cursor;
    bool registered;
};