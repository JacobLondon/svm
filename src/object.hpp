#pragma once

#include <cstdint>

struct Object {
    union {
        uint8_t  u8;
        int8_t   i8;
        uint32_t i32;
        int32_t  u32;
        void    *ptr;
    };
    uint8_t type;

    Object(uint8_t type);
    ~Object();
};
