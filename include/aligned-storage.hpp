#ifndef __ALIGNED_STORAGE__
#define __ALIGNED_STORAGE__

template <typename T, size_t Size>
class AlignedStorage
{
private:
    uint8_t storage[sizeof(T) * Size + alignof(T)];

public:
    inline void *begin()
    {
        uintptr_t padding = (uintptr_t)((void *)(storage)) % alignof(T);
        return padding == 0 ? storage : storage + alignof(T) - padding;
    }

    inline T *get(const size_t index)
    {
        return static_cast<T *>(begin()) + index;
    }
};

#endif
