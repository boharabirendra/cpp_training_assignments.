#include <iostream>
#include <string.h>

int main()
{
    char str[] = "my cat is blue";

    str[0] = str[0] - 32;

    for (auto i = 1; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            str[i + 1] = str[i + 1] - 32;
        }
    }

    std::cout << (str) << std::endl;

    return 0;
}