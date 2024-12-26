#include <iostream>
#include "logger.h"
#include "let.h"

int main()
{

    Let a = "one";
    Let b = "three";

    ConsoleLogger logger;
    ErrorLogger errLogger;
    LoggingDecorator loggingLet1(a, errLogger);
    LoggingDecorator loggingLet2(b, logger);

    // LoggingDecorator result = loggingLet1 + loggingLet2;
    LoggingDecorator subResult = loggingLet1 - loggingLet2;
    // std::cout << result << std::endl;
    std::cout << subResult << std::endl;
    return 0;
}