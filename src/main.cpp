#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include <vector>

#include "svm.hpp"

static svm::Arguments argparse(std::vector<std::string> args)
{
    svm::Arguments defaults;

    if (args.size() < 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::exit(-1);
    }

    for (size_t i = 1; i < args.size(); i++) {
        if (args[i] == svm::SpecifierFin) {
            defaults.fin = args[++i];
        }
        else {
            std::cerr << "Error: Invalid argument specifier " << args[i] << std::endl;
            std::exit(-1);
        }
    }
    return defaults;
}

static void run(svm::Arguments& defaults)
{
    std::ifstream fs(defaults.fin);
    std::string program((std::istreambuf_iterator<char>(fs)),
                         std::istreambuf_iterator<char>());
    svm::Machine vm{program};
    vm.run();
}

int main(int argc, char **argv)
{
    svm::Arguments defaults = argparse(std::vector<std::string>(argv, argv + argc));

    run(defaults);

    return 0;
}
