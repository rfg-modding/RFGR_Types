#pragma once

namespace keen
{
    struct Mutex
    {
        char m_name[32];
        unsigned int m_criticalSectionData[6];
    };
    static_assert(sizeof(keen::Mutex) == 56);

    struct Thread
    {
        void* m_threadHandle;
        unsigned int m_threadId;
        volatile void* m_pArgument;
        char m_identifier[64];
        bool m_quitRequested;
        int(__cdecl* m_pFunction)(keen::Thread*);
    };

    struct Event
    {
        void* m_eventHandle;
    };
}

struct sync_event
{
    keen::Event keen_event;
};

struct cs_wrapper
{
    keen::Mutex m_mutex;
    int debug_handle;
};
static_assert(sizeof(cs_wrapper) == 60);

struct cs_spinlock
{
    unsigned __int64 lockValue;
};