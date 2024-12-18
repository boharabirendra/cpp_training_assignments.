#include <iostream>

/**
 *  Case I
 *  When pointer variable points to the memory location that no longer allocated i.e. de-allocated memory address
 *
 *  memory location pointed by m_p pointer variable is deleted from heap section
 *  but m_p pointer variable still points to deleted memory location in the heap section, it is called dangling pointer
 */
class CaseI
{
public:
    CaseI()
    {
        delete m_p;
        std::cout << "Value = " << *m_p << std::endl;
    }

private:
    int *m_p = new int(10);
};

/**
 * Returing a local variable address
 * When this function executed, it is removed from stack but the address return from this function is hold by *p pointer variable in main section.
 */

int *caseII()
{
    int a = 10;
    return &a;
}

/**
 * Case III
 * Each allocating new memory locations in heap section without clearing previous one
 */

void caseIII()
{
    int *p = new int[10]; // allocation memory locations for 10 integer in heap section
}

int main()
{
    system("clear");
    std::cout << "Dangline Pointer" << std::endl;
    std::cout << "----------------" << std::endl;

    CaseI caseI;

    // int *p = caseII();
    // std::cout << "Case II " << *p << std::endl;

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