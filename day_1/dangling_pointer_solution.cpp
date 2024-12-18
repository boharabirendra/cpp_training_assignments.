#include <iostream>

/**
 *  Case I
 *  After de-allocating memory, set null_ptr to pointer variable which is pointing to that memory location if any.
 *
 */
class CaseI
{
public:
    CaseI()
    {
        std::cout << "Value = " << *m_p << std::endl;
        delete m_p;
        m_p = nullptr;
    }

private:
    int *m_p = new int(10);
};

/**
 * Returing a local variable address
 * Make it static (it make variable avaiable through out the whole program execution in stack section)
 */

int *caseII()
{
    static int a = 10;
    return &a;
}

/**
 * Case III
 * Delete allocated memory after using it
 */

void caseIII()
{
    int *p = new int[10];
    delete[] p;
}

int main()
{
    system("clear");
    std::cout << "Dangline Pointer" << std::endl;
    std::cout << "----------------" << std::endl;

    CaseI caseI;

    int *p = caseII();
    std::cout << "Case II " << *p << std::endl;

    int random;
    while (true)
    {
        std::cout << std::endl
                  << "Choose any random number between 1 - 10: ";
        std::cin >> random;
        if (random == 7)
            break;
    }

    std::cout
        << std::endl
        << std::endl;
    return 0;
}