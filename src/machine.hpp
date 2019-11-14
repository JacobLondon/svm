#pragma once

#include <stack>

#include "types/types.hpp"

namespace svm {

#define OPCODE_COUNT 256

class Machine {
public:
    iptr_t ip;
    instruction opcodes[OPCODE_COUNT];
    std::string program;
    stack_t data;

    Machine(std::string& program);
    ~Machine();

    void run();
};

} // svm