#include <iostream>

#include "svm.hpp"

static Arguments argparse(std::vector<std::string> args)
{
    Arguments defaults;

    if (args.size() < 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::exit(-1);
    }

    for (size_t i = 1; i < args.size(); i++) {
        if (args[i] == SpecifierFin) {
            defaults.fin = args[++i];
        }
        else {
            std::cerr << "Error: Invalid argument specifier " << args[i] << std::endl;
            std::exit(-1);
        }
    }
    return defaults;
}

int main(int argc, char **argv)
{
    Arguments defaults = argparse(std::vector<std::string>(argv, argv + argc));

    svm(defaults);

    return 0;
}
