#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <map>
#include <functional>
#include <sstream>
#include <vector>

#include "rdrand_func.h"

int main(int argc, char *argv[])
try
{
    if (argc != 2)
    {
        std::cerr << "Error: number of random numbers missing" << std::endl;
        throw std::invalid_argument("Missing argument");
    }

    size_t n_rand_numbers = 0;
    {
        std::stringstream ss { argv[1] };
        ss >> n_rand_numbers;
    }

    static std::map<size_t, std::function<void (size_t *p)>> const factory
    {
        { 1,    [](size_t *p) { rdrand_func1(p);    } },
        { 4,    [](size_t *p) { rdrand_func4(p);    } },
        { 8,    [](size_t *p) { rdrand_func8(p);    } },
        { 16,   [](size_t *p) { rdrand_func16(p);   } },
        { 32,   [](size_t *p) { rdrand_func32(p);   } },
        { 64,   [](size_t *p) { rdrand_func64(p);   } },
        { 128,  [](size_t *p) { rdrand_func128(p);  } },
        { 256,  [](size_t *p) { rdrand_func256(p);  } },
        { 512,  [](size_t *p) { rdrand_func512(p);  } },
        { 1024, [](size_t *p) { rdrand_func1024(p); } },
    };

    auto it = factory.find(n_rand_numbers);

    if (it == factory.end())
    {
        std::cerr << "Error: Number of random numbers not supported" << std::endl;
        std::cerr << "Supported numbers:" << std::endl;
        for (auto &f: factory)
        {
            std::cerr << f.first << std::endl;
        }
        throw std::invalid_argument("Wrong number of random numbers");
    }

    std::vector<size_t> buffer(n_rand_numbers);

    auto func = it->second;

    func(buffer.data());

    for (auto value: buffer)
    {
        std::cout << std::hex << value << std::endl;
    }

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error, exception" << std::endl;
    return EXIT_FAILURE;
}
