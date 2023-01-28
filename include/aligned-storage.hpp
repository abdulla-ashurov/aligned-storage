#ifndef __ALIGNED_STORAGE__
#define __ALIGNED_STORAGE__

template <typename T, size_t Size>
class AlignedStorage
{
private:
    uint8_t storage[sizeof(T) * Size + alignof(T)];
    void *begin = storage;

public:
    AlignedStorage()
    {
        uintptr_t padding = (uintptr_t)((void *)(storage)) % alignof(T);
        if (padding != 0)
            begin = storage + alignof(T) - padding;
    }

    T *get(const size_t index)
    {
        return static_cast<T*>(begin) + index;
    }
};

#endif
