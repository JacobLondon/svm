#include <iostream>
#include <stack>

#include "machine.hpp"

static iptr_t op_nop(iptr_t ip, std::stack<Object>& stack)
{
    return ip + 1;
}

static iptr_t op_push_u8(iptr_t ip, std::stack<Object>& stack)
{
    Object obj('c');
    obj.u8 = *(ip + 1);
    stack.push(obj);
    return ip + 2;
}

static iptr_t op_emit_u8(iptr_t ip, std::stack<Object>& stack)
{
    Object obj = stack.top();
    stack.pop();
    std::cout << obj.u8 << std::endl;
    return ip + 1;
}

Machine::Machine(std::string& program)
: program(program)
{
    for (int i = 0; i < OPCODE_COUNT; i++)
        opcodes[i] = op_nop;
    opcodes['c'] = op_push_u8;
    opcodes['e'] = op_emit_u8;

    ip = (iptr_t)this->program.c_str();
}

Machine::~Machine()
{}

void Machine::run()
{
    while (*ip != 'h') {
        ip = opcodes[*ip](ip, data);
    }
}