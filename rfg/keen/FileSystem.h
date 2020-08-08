#pragma once
#include "Threading.h"
#include "Memory.h"
#include "Containers.h"
#include "RFGR_Types/rfg/Containers.h"

using _BYTE = unsigned char;

namespace keen
{
    enum IoError
    {
        IoError_Ok = 0x0,
        IoError_Generic = 0x1,
        IoError_CompressionError = 0x2,
        IoError_DecompressionError = 0x3,
        IoError_ReadError = 0x4,
        IoError_WriteError = 0x5,
        IoError_NotImplemented = 0x6,
        IoError_EofReached = 0x7,
        IoError_InvalidState = 0x8,
        IoError_FileNotFound = 0x9,
        IoError_InvalidPosition = 0xA,
        IoError_NoPermission = 0xB,
        IoError_NoConnection = 0xC,
        IoError_TimeOut = 0xD,
        IoError_InvalidArgument = 0xE,
        IoError_OutOfMemory = 0xF,
        IoError_AlreadyExists = 0x10,
        IoError_NotSupported = 0x11,
        IoError_Count = 0x12,
    };

    enum Endianness
    {
        Endianness_Little = 0x0,
        Endianness_Big = 0x1,
        Endianness_Count = 0x2,
    };

    enum FileAccessMode
    {
        FileAccessMode_Read = 0x0,
        FileAccessMode_Write = 0x1,
        FileAccessMode_Append = 0x2,
        FileAccessMode_ReadWrite = 0x3,
        FileAccessMode_Count = 0x4,
    };

    template <class T>
    struct IoResult
    {
        T result;
        IoError error;
    };

    struct FileDeviceInterfaceVtbl;
    struct FileDeviceInterface
    {
        keen::FileDeviceInterfaceVtbl* vfptr;
    };

    const struct FileDeviceMountData
    {

    };

    struct __declspec(align(4)) FileStatus
    {
        int lastModificationTime;
        unsigned __int64 size;
        char nativeFileName[260];
        bool isWriteable;
        bool isDirectory;
    };

    struct FileDeviceInterfaceVtbl
    {
        void* (__thiscall* __vecDelDtor)(keen::FileDeviceInterface* thisPtr, unsigned int);
        _BYTE gap4[4];
        keen::IoError(__thiscall* closeFile)(keen::FileDeviceInterface* thisPtr, unsigned __int16);
        keen::IoError(__thiscall* freeMountData)(keen::FileDeviceInterface* thisPtr, keen::MemoryAllocator*, keen::FileDeviceMountData*);
        keen::IoResult<unsigned int>(__thiscall* read)(keen::FileDeviceInterface* thisPtr, unsigned __int16, void*, unsigned int);
        keen::IoResult<unsigned int>(__thiscall* write)(keen::FileDeviceInterface* thisPtr, unsigned __int16, const void*, unsigned int);
        keen::IoError(__thiscall* flushWriteBuffer)(keen::FileDeviceInterface* thisPtr, unsigned __int16);
        keen::IoResult<unsigned __int64>* (__thiscall* getSize)(keen::FileDeviceInterface* thisPtr, keen::IoResult<unsigned __int64>* result, unsigned __int16);
        keen::IoError(__thiscall* setPosition)(keen::FileDeviceInterface* thisPtr, unsigned __int16, unsigned __int64);
        keen::IoResult<unsigned __int64>* (__thiscall* getPosition)(keen::FileDeviceInterface* thisPtr, keen::IoResult<unsigned __int64>* result, unsigned __int16);
        keen::IoError(__thiscall* setFilePermissionByName)(keen::FileDeviceInterface* thisPtr, keen::FileDeviceMountData*, const char*, bool);
        keen::IoError(__thiscall* getFileStatusByName)(keen::FileDeviceInterface* thisPtr, keen::FileStatus*, keen::FileDeviceMountData*, const char*, unsigned int);
        bool(__thiscall* getNativeFilePath)(keen::FileDeviceInterface* thisPtr, char*, unsigned int, keen::FileDeviceMountData*, const char*);
    };

    struct __declspec(align(4)) NativeFileDevice : keen::FileDeviceInterface
    {
        struct __declspec(align(8)) ReadBuffer
        {
            keen::MemoryBlock data;
            unsigned __int64 filePosition;
            unsigned int size;
            unsigned int readOffset;
            keen::IoError result;
        };
        struct __declspec(align(4)) FileStreamData
        {
            void* fileHandle;
            unsigned __int64 filePosition;
            unsigned __int64 fileSize;
            keen::IoError result;
            bool isInReadMode;
        };
        struct ReadThreadContext
        {
            keen::Thread thread;
            keen::NativeFileDevice::ReadBuffer buffers[2];
            keen::Event bufferEmpty;
            keen::Event bufferFilled;
            unsigned int bufferReadIndex;
            unsigned int bufferWriteIndex;
            bool hasBuffer;
            void* fileHandle;
            unsigned __int64 filePosition;
            unsigned __int64 fileSize;
        };

        keen::FileStreamAllocator<keen::NativeFileDevice::FileStreamData> m_streams;
        keen::Array<keen::NativeFileDevice::ReadThreadContext> m_readThreadContexts;
        keen::Mutex m_mutex;
        bool m_useReadThread;
    };

    struct MemoryFileDeviceMountData : keen::FileDeviceMountData
    {
        keen::MemoryAllocator* pAllocator;
        unsigned int fileHandle;
    };

    struct MemoryFileDevice : keen::FileDeviceInterface
    {
        struct __declspec(align(4)) FileEntry
        {
            keen::MemoryFileDeviceMountData* pMountData;
            keen::MemoryBlock memoryBlock;
            unsigned int fileSize;
            unsigned int openCount;
            unsigned int fileNameCrc;
            bool isWritten;
            bool isWriteable;
        };
        struct StreamEntry
        {
            keen::MemoryFileDevice::FileEntry* pFile;
            unsigned int position;
            keen::FileAccessMode accessMode;
        };

        keen::FileStreamAllocator<keen::MemoryFileDevice::StreamEntry> m_streams;
        keen::Array<MemoryFileDevice::FileEntry> m_files;
        keen::IndexArray m_fileIndices;
    };

    struct PakfileEntry
    {
        unsigned int crc;
        unsigned int size;
        unsigned __int64 position;
    };

    struct FileSystem;
    struct PakFileDeviceMountData : keen::FileDeviceMountData
    {
        keen::FileSystem* pFileSystem;
        unsigned int pakFileHandle;
        keen::Array<keen::PakfileEntry> fileEntries;
        keen::Endianness endianness;
        bool isPakfileCompressed;
        unsigned int alignment;
        unsigned int chunkSize;
    };

    struct PakFileDevice : keen::FileDeviceInterface
    {
        struct PakFileStream
        {
            char compressedChunkData[8192];
            char uncompressedChunkData[4096];
            unsigned int uncompressedChunkDataSize;
            unsigned int uncompressedChunkDataPosition;
            keen::Array<unsigned int> chunkSizes;
            unsigned int chunkCount;
            unsigned int chunkIndex;
            unsigned __int64 firstChunkPosition;
            unsigned __int64 nextChunkPosition;
            unsigned __int64 uncompressedDataBegin;
            unsigned __int64 uncompressedDataPosition;
            bool isFileCompressed;
            keen::PakFileDeviceMountData* pMountData;
            unsigned int fileNameCrc;
            unsigned __int64 fileSize;
        };

        keen::FileStreamAllocator<keen::PakFileDevice::PakFileStream> m_streams;
        keen::TlsfMemoryAllocator m_chunkAllocator;
    };

    struct AliasPathFileDeviceMountData : keen::FileDeviceMountData
    {
        keen::FileSystem* pFileSystem;
        char targetPath[260];
    };

    struct AliasPathFileDevice : keen::FileDeviceInterface
    {
        struct StreamEntry
        {
            keen::AliasPathFileDeviceMountData* pMountData;
            unsigned int fileHandle;
        };

        keen::FileStreamAllocator<keen::AliasPathFileDevice::StreamEntry> m_streams;
    };

    struct __declspec(align(4)) FileSystemDeviceEntry : keen::ListEntry<keen::FileSystemDeviceEntry>
    {
        keen::FileDeviceMountData* pMountData;
        keen::FileDeviceInterface* pDevice;
        bool isInternalDevice;
    };

    struct FileSystemMountPoint : keen::TreeNode<keen::FileSystemMountPoint>
    {
        char path[128];
        keen::FileSystemDeviceEntry* pFirstDevice;
    };

    struct __declspec(align(4)) FileSystem
    {
        keen::PoolAllocator<int> devices; //keen::PoolAllocator<keen::FileSystemDeviceEntry> devices;
        keen::PoolAllocator<int> mountPoints; //keen::PoolAllocator<keen::FileSystemMountPoint> mountPoints;
        keen::NativeFileDevice nativeFileDevice;
        keen::MemoryFileDevice memoryFileDevice;
        keen::PakFileDevice pakFileDevice;
        keen::AliasPathFileDevice aliasPathFileDevice;
        keen::FileSystemMountPoint* pRootPoint;
        unsigned int nativeMountHandle;
        keen::Mutex mutex;
        unsigned int openFileStack;
        keen::MemoryAllocator* pAllocator;
        volatile unsigned int useIo;
        bool ignoreFirstChild;
    };
}

struct cf_keen_open_file
{
    unsigned int m_handle;
    keen::FileSystem* m_pFileSystem;
    unsigned int m_flags;
    unsigned int m_async_num_bytes_to_transfer;
    unsigned int m_async_pad_bytes;
    unsigned int m_async_num_pad_bytes_to_transfer;
    unsigned int m_async_num_bytes_read;
};