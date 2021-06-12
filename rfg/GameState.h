#pragma once

struct __declspec(align(4)) state_info
{
    void(__cdecl* enter)(game_state);
    void(__cdecl* exit)(game_state);
    bool(__cdecl* exit_notify)(game_state);
    void(__cdecl* process)();
    void(__cdecl* handshake)(rl_renderer*);
    void(__cdecl* render)(rl_renderer*);
    bool transparent;
    bool pause_beneath;
    int user_flags;
    bool hide_cursor;
    bool registered;
};