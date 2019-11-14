#include <fstream>
#include <streambuf>
#include <string>

#include "svm.hpp"
#include "machine.hpp"

void svm(Arguments& defaults)
{
    std::ifstream fs(defaults.fin);
    std::string program((std::istreambuf_iterator<char>(fs)),
                         std::istreambuf_iterator<char>());
    Machine vm{program};
    vm.run();
}
