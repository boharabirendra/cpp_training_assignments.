#include <thread>
#include <iostream>

void sayHello()
{
    while (true)
    {
        std::cout << "Hello, World" << std::endl;
    }
}

void sayHi()
{
    while (true)
    {
        std::cout << "Hi, " << std::endl;
    }
}

int main()
{
    std::thread t1(sayHello);
    std::thread t2(sayHi);

    t1.join();

    std::cout << "Hi from Main thread " << std::endl;
    while (true)
    {
        std::cout << "";
    }
    return 0;
}