#pragma once

#include <stack>

#include "object.hpp"

namespace svm {

enum type {
    i8,
    u8,
    i32,
    u32,
    voidptr,
};

using iptr_t = char *;
using stack_t  = std::stack<Object>;
using instruction_t = iptr_t (*)(iptr_t, stack_t&);

} // svm