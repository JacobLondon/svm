#pragma once

#include <stack>

#include "object.hpp"

using iptr_t = char *;
using instruction = iptr_t (*)(iptr_t, std::stack<Object>&);

#define OPCODE_COUNT 256

class Machine {
public:
    iptr_t ip;
    instruction opcodes[OPCODE_COUNT];
    std::string program;
    std::stack<Object> data;

    Machine(std::string& program);
    ~Machine();

    void run();
};
