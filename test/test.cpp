#include <string>
#include "catch_amalgamated.hpp"
#include "../include/aligned-storage.hpp"

TEST_CASE("test AlignedStorage class")
{
    const size_t size = 4;
    const size_t default_alignment = 1;
    
    SECTION("test AlignedStorage class for uint32_t type")
    {
        #pragma pack(1)
        struct TestType
        {
            char symbol;
            AlignedStorage<uint32_t, size> storage;
        };

        TestType test;

        REQUIRE(alignof(TestType) == default_alignment);
        for (size_t i = 0; i < size; i++)
            REQUIRE(uintptr_t((void *)(test.storage.get(i))) % alignof(uint32_t) == 0);
    }

    SECTION("test AlignedStorage class for uint64_t type")
    {
        #pragma pack(1)
        struct TestType
        {
            char symbol;
            AlignedStorage<uint64_t, size> storage;
        };
        
        TestType test;

        REQUIRE(alignof(TestType) == default_alignment);
        for (size_t i = 0; i < size; i++)
            REQUIRE(uintptr_t((void *)(test.storage.get(i))) % alignof(uint64_t) == 0);
    }

    SECTION("test AlignedStorage class for std::string type")
    {
        #pragma pack(1)
        struct TestType
        {
            char symbol;
            AlignedStorage<std::string, size> storage;
        };
        
        TestType test;

        REQUIRE(alignof(TestType) == default_alignment);
        for (size_t i = 0; i < size; i++)
            REQUIRE(uintptr_t((void *)(test.storage.get(i))) % alignof(std::string) == 0);
    }
}
