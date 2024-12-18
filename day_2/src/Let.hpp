#include "../include/Let.hpp"

Let::Let() = delete;
Let::Let(const Let &let) = delete;
/**
 * Assign a integer to a Let object
 */
Let::Let(int intVar) : m_type(DATATYPE::INT)
{
    m_intVar = intVar;
}

Let &Let::operator+(int intVar)
{
    m_intVar += intVar;
    return *this;
}

Let &Let::operator-(int intVar)
{
    m_intVar -= intVar;
    return *this;
}

/**
 * Assign a double to a Let object
 */
Let::Let(double doubleVar) : m_type(DATATYPE::DOUBLE)
{
    m_doubleVar = doubleVar;
}

Let &Let::operator+(double doubleVar)
{
    m_doubleVar += doubleVar;
    return *this;
}

Let &Let::operator-(double doubleVar)
{
    m_doubleVar -= doubleVar;
    return *this;
}

/**
 * Assign a string to a Let object
 */
Let::Let(const char *str) : m_type(DATATYPE::STRING)
{
    int len = strlen(str) + 1;
    try
    {
        m_pChar = new char[len];
        m_strLength = len;
        strcpy(m_pChar, str);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Allocation error\n";
        std::cerr << e.what() << '\n';
    }
}

Let &Let::operator+(const char *str)
{
    int currentStringLength = strlen(m_pChar);
    int passedStringLength = strlen(str);
    int newStringLength = currentStringLength + passedStringLength;
    try
    {
        char *temp = new char[currentStringLength];
        strcpy(temp, m_pChar);
        delete[] m_pChar;
        m_pChar = new char[newStringLength];
        strcpy(m_pChar, temp);
        strcat(m_pChar, str);
        delete[] temp;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return *this;
}

/**
 * Determine the lenght of string
 */

int Let::length() const
{
    if ((*this).m_type == DATATYPE::STRING && (*this).m_pChar != nullptr)
    {
        return strlen((*this).m_pChar);
    }
    return 0;
}

/**
 * Relational operator
 */

int Let::operator==(Let &let) { return !strcmp(m_pChar, let.m_pChar); }
int Let::operator!=(Let &let) { return strcmp(m_pChar, let.m_pChar); }
int Let::operator<(Let &let) { return strcmp(m_pChar, let.m_pChar) < 0; }
int Let::operator>(Let &let) { return strcmp(m_pChar, let.m_pChar) > 0; }
int Let::operator<=(Let &let) { return strcmp(m_pChar, let.m_pChar) <= 0; }
int Let::operator>=(Let &let) { return strcmp(m_pChar, let.m_pChar) >= 0; }

int Let::operator==(const char *s) { return !strcmp(m_pChar, s); }
int Let::operator!=(const char *s) { return strcmp(m_pChar, s); }
int Let::operator<(const char *s) { return strcmp(m_pChar, s) < 0; }
int Let::operator>(const char *s) { return strcmp(m_pChar, s) > 0; }
int Let::operator<=(const char *s) { return strcmp(m_pChar, s) <= 0; }
int Let::operator>=(const char *s) { return strcmp(m_pChar, s) >= 0; }

/**
 * Ostream overloading
 */
std::ostream &operator<<(std::ostream &stream, Let &let)
{
    switch (let.m_type)
    {
    case DATATYPE::INT:
        stream << let.m_intVar;
        break;
    case DATATYPE::DOUBLE:
        stream << let.m_doubleVar;
        break;
    case DATATYPE::STRING:
        stream << let.m_pChar;
        break;
    case DATATYPE::ARRAY:
        for (int i = 0; i < sizeof(let.m_intPtr) / sizeof(let.m_intPtr[0]); i++)
        {
            stream << let.m_intPtr[i] << ", ";
        }
        break;
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, Let &let)
{
    char *p;
    std::cout << "Enter string: ";
    stream >> p;
    return stream;
}

/**Equal (=) overloading */
Let &Let::operator=(Let &let)
{
    switch (let.m_type)
    {
    case DATATYPE::INT:
        m_intVar = let.m_intVar;
        break;
    case DATATYPE::DOUBLE:
        m_doubleVar = let.m_doubleVar;
        break;
    case DATATYPE::STRING:
        m_pChar = let.m_pChar;
        break;
    }
    return *this;
}
