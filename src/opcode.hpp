#pragma once

#include "types/types.hpp"

namespace svm {

enum op {
    nop     = '\0',
    halt    = 'h',
    emit    = 'e',
    newline = 'n',
    push    = 'p',
};

iptr_t op_nop(iptr_t ip, stack_t& stack);

iptr_t op_push_u8(iptr_t ip, stack_t& stack);

iptr_t op_emit(iptr_t ip, stack_t& stack);

iptr_t op_newline(iptr_t ip, stack_t& stack);

} // svm