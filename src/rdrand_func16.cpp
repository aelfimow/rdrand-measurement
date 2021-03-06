#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cstring>

#include "rdrand_func.h"

int main(int argc, char *argv[])
try
{
    (void)argc;
    (void)argv;

    size_t values[16];
    std::memset(values, 0, sizeof(values));

    rdrand_func16(&values[0]);

    for (auto v: values)
    {
        std::cout << std::hex << v << std::endl;
    }

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error, exception" << std::endl;
    return EXIT_FAILURE;
}
