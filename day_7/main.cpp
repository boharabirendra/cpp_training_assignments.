#include <iostream>
#include "./src/Let.hpp"

int main()
{
    Let let = {1, 2, 3, 4, "hello"};

    std::cout
        << let;
    return 0;
}