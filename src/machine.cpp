#include <iostream>
#include <stack>

#include "machine.hpp"

namespace svm {

Machine::Machine(std::string& program)
: program(program), opcodes{0}
{
    // initialize opcodes
    for (int i = 0; i < OPCODE_COUNT; i++)
        opcodes[i] = op_nop;
    opcodes[op::push] = op_push_u8;
    opcodes[op::emit] = op_emit;

    // starting instruction
    ip = (iptr_t)this->program.c_str();
}

Machine::~Machine()
{}

void Machine::run()
{
    while (*ip != op::halt) {
        ip = opcodes[*ip](ip, data);
    }
}

} // svm