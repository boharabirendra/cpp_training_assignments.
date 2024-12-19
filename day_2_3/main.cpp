#include <string>

#include "./src/Let.hpp"

int main()
{
    Let intObj = 10;
    intObj = intObj + 10;

    Let doubleObj = 95.5;
    doubleObj = doubleObj - 40.5;

    // String
    Let stringObj = "Hello, ";
    stringObj = stringObj + "World";
    Let stringObj1 = "Apple";

    std::cout
        << "Integer: " << intObj << "\n";
    std::cout << "Double: " << doubleObj << "\n";
    std::cout << "String: " << stringObj << "\n";
    std::cout << "Length of string: " << stringObj.length() << "\n";

    if (stringObj > stringObj1)
    {
        std::cout << "stringObj is Greater " << "\n";
    }
    else
    {
        std::cout << "stringObj1 is Greater " << "\n";
    }

    if (stringObj1 > "aa")
    {
        std::cout << "stringObj1 is smaller" << "\n";
    }
    else
    {
        std::cout << "stringObj1 is greater" << "\n";
    }

    return 0;
}