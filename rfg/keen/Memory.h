#pragma once
#include "Threading.h"

namespace keen
{
    struct MemoryBlock
    {
        char* pStart;
        unsigned int size;
    };

    struct BasePoolAllocator
    {
        keen::MemoryBlock m_memoryBlock;
        unsigned int m_capacity;
        unsigned int m_size;
        unsigned int m_elementSize;
        unsigned int m_firstFreeIndex;
    };

    template <class T>
    struct PoolAllocator
    {
        BasePoolAllocator m_pool;
    };

    template <class T>
    struct FileStreamAllocator
    {
        keen::PoolAllocator<T> m_streamAllocator;
        keen::Mutex m_streamMutex;
    };

    struct MemoryAllocator;
    struct MemoryAllocatorVtbl
    {
        void* (__thiscall* __vecDelDtor)(keen::MemoryAllocator* thisPtr, unsigned int);
        void* (__thiscall* allocate)(keen::MemoryAllocator* thisPtr, unsigned int, unsigned int, unsigned int, const char*);
        void (__thiscall* free)(keen::MemoryAllocator* thisPtr, void*);
        const char* (__thiscall* getName)(keen::MemoryAllocator* thisPtr);
    };

    struct MemoryAllocator
    {
        keen::MemoryAllocatorVtbl* vfptr;
    };

    template <class T>
    struct BaseMemoryAllocator
    {
        keen::Mutex m_mutex;
        char m_name[128];
        T m_allocator;
        keen::MemoryBlock m_memoryBlock;
        unsigned int m_allocatedSize;
        unsigned int m_maxAllocatedSize;
        unsigned int m_allocationCount;
        unsigned int m_flags;
    };

    struct TlsfAllocator
    {
        keen::MemoryBlock m_memoryBlock;
        void* m_pPool;
    };

    struct TlsfMemoryAllocator : keen::BaseMemoryAllocator<keen::TlsfAllocator>
    {

    };
}