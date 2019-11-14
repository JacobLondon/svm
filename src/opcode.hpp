#pragma once

#include "types/types.hpp"

namespace svm {

#define OPCODE_COUNT 256

enum op {
    nop     = '\0',
    halt    = 'h',
    emit    = 'e',
    push    = 'p',
};

iptr_t op_nop(iptr_t ip, stack_t& stack);

iptr_t op_push_u8(iptr_t ip, stack_t& stack);
iptr_t op_push_u32(iptr_t ip, stack_t& stack);

iptr_t op_emit(iptr_t ip, stack_t& stack);


} // svm