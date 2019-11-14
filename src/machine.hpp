#pragma once

#include <stack>

#include "types/types.hpp"
#include "opcode.hpp"

namespace svm {

class Machine {
public:
    iptr_t ip;
    instruction_t opcodes[OPCODE_COUNT];
    std::string program;
    stack_t data;

    Machine(std::string& program);
    ~Machine();

    void run();
};

} // svm