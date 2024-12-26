#include "../include/Let.hpp"

Let operator+(std::initializer_list<Variant> &&l)
{
    std::cout << "Fuck you";
}

/**
 * Ostream overloading
 */

void display(std::ostream &stream, Variant &let)
{
    switch (let.getType())
    {
    case DATATYPE::INTEGER:
        stream << let.getIntVar();
        break;
    case DATATYPE::DOUBLE:
        stream << let.getDoubleVar();
        break;
    case DATATYPE::STRING:
        stream << let.getStrPtr();
        break;
    case DATATYPE::BOOLEN:
        stream << let.getBoolVar();
        break;
    }
}

std::ostream &operator<<(std::ostream &stream, Let &let)
{
    switch (let.getType())
    {
    case DATATYPE::ARRAY:
        stream << "{";
        {
            auto array = let.getArray();
            for (size_t i = 0; i < array.size(); ++i)
            {
                display(stream, array[i]);
                if (i < array.size() - 1)
                {
                    stream << ", ";
                }
            }
        }
        stream << "} \n";
        break;
    default:
        display(stream, let);
        break;
    }
    return stream;
}

// std::istream &operator>>(std::istream &stream, Let &let)
// {
//     char *p;
//     std::cout << "Enter string: ";
//     stream >> p;
//     return stream;
// }

// /**Equal (=) overloading */
Let &Let::operator=(Let &let)
{
    switch (let.m_type)
    {
    case DATATYPE::INTEGER:
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
