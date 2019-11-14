#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <stack>
#include <streambuf>
#include <string>

struct Object {
    union {
        uint8_t  u8;
        int8_t   i8;
        uint32_t i32;
        int32_t  u32;
        void    *ptr;
    };
    uint8_t type;

    Object(uint8_t type);
    ~Object();
};

Object::Object(uint8_t type)
: type(type)
{}

Object::~Object()
{}

using instruction = char *(*)(char *, std::stack<Object>&);

char *op_nop(char *ip, std::stack<Object>& stack)
{
    return ip + 1;
}

char *op_push_u8(char *ip, std::stack<Object>& stack)
{
    Object obj('c');
    obj.u8 = *(ip + 1);
    stack.push(obj);
    return ip + 2;
}

char *op_emit_u8(char *ip, std::stack<Object>& stack)
{
    Object obj = stack.top();
    stack.pop();
    std::cout << obj.u8 << std::endl;
    return ip + 1;
}

int main(int argc, char **argv)
{
    const char *code;
    char *ip;
    std::stack<Object> data;
    instruction opcodes[256];

    if (argc != 2) {
        std::cerr << "Invalid usage" << std::endl;
        std::exit(-1);
    }

    for (int i = 0; i < 256; i++) {
        opcodes[i] = op_nop;
    }

    opcodes['c'] = op_push_u8;
    opcodes['e'] = op_emit_u8;
    std::ifstream fp(argv[1]);
    std::string input((std::istreambuf_iterator<char>(fp)),
                       std::istreambuf_iterator<char>());
    code = input.c_str();
    ip   = (char *)code;

    while (*ip != 'h') {
        ip = opcodes[*ip](ip, data);
    }

    return 0;
}
