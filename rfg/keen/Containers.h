#pragma once

namespace keen
{
    template <class T>
    struct Array
    {
        T* m_pData;
        unsigned int m_size;
    };

    template <class T>
    class SizedArray
    {
        T* Data;
        unsigned int Size;
        unsigned int Capacity;
    };

    struct IndexArray
    {
        keen::SizedArray<unsigned int> m_indices;
    };

    template <class T>
    struct ListEntry
    {
        T* pNext;
        T* pPrev;
    };

    template <class T>
    struct TreeNode
    {
        T* pNextSibling;
        T* pPrevSibling;
        T* pParent;
        T* pFirstChild;
    };
}