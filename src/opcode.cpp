#include <iostream>

#include "opcode.hpp"

namespace svm {

iptr_t op_nop(iptr_t ip, stack_t& stack)
{
    return ip + 1;
}

iptr_t op_push_u8(iptr_t ip, stack_t& stack)
{
    Object obj(type::u8);
    obj.u8 = *(ip + 1);
    stack.push(obj);
    return ip + 2;
}

iptr_t op_push_u32(iptr_t ip, stack_t& stack)
{
    Object obj(type::u32);
    obj.u32 = *(ip + 1);
    stack.push(obj);
    return ip + 5;
}

iptr_t op_emit(iptr_t ip, stack_t& stack)
{
    Object obj = stack.top();
    stack.pop();
    std::cout << obj.u8;
    return ip + 1;
}

} // svm