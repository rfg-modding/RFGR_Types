#pragma once

namespace keen
{
    struct Mutex
    {
        char m_name[32];
        unsigned int m_criticalSectionData[6];
    };

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

struct cs_wrapper
{
    keen::Mutex m_mutex;
    int debug_handle;
};

struct cs_spinlock
{
    unsigned __int64 lockValue;
};