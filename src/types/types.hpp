#pragma once

#include <stack>

#include "object.hpp"

namespace svm {

enum type {
    u8 = 'c',
};

using iptr_t = char *;
using stack_t  = std::stack<Object>;
using instruction = iptr_t (*)(iptr_t, stack_t&);

} // svm