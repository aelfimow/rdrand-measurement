#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "rdrand_func.h"

int main(int argc, char *argv[])
try
{
    size_t value = 0;

    rdrand_func1(&value);

    std::cout << value << std::endl;

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error, exception" << std::endl;
    return EXIT_FAILURE;
}
