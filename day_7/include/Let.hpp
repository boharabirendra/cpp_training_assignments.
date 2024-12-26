#ifndef LET_H
#define LET_H

#include <vector>
#include <string.h>
#include <iostream>

#include "../constants/Let.hpp"
#include "./LinkedList_With_Variation.hpp"

class Let : public Variant
{
public:
    Let() = delete;
    Let(const char *str) : Variant(str) {};
    Let(const Let &let) : Variant(let) {};
    Let(std::initializer_list<Variant> l) : Variant(l) {}

    Let(int intVar);
    Let(double doubleVar);

    ~Let()
    {
        delete[] m_pChar;
    }

    Let &operator+(int intVar);
    Let &operator-(Let &let);
    Let &operator-(int intVar);
    Let &operator=(int intVar);

    Let operator+(std::initializer_list<Variant> &&l);

    Let &operator+(double doubleVar);
    Let &operator-(double doubleVar);
    Let &operator=(double doubleVar);

    Let &operator=(Let &let);
    Let operator=(char *str);
    Let operator+(Let &let);
    Let &operator+(const char *s);

    int length() const;

    int operator==(Let &let);
    int operator!=(Let &let);
    int operator<(Let &let);
    int operator>(Let &let);
    int operator<=(Let &let);
    int operator>=(Let &let);

    int operator==(const char *s);
    int operator!=(const char *s);
    int operator<(const char *s);
    int operator>(const char *s);
    int operator<=(const char *s);
    int operator>=(const char *s);

    int strsize() { return strlen(m_pChar); }

    friend std::ostream &operator<<(std::ostream &stream, Let &let);
    friend std::istream &operator>>(std::istream &stream, Let &let);

private:
    int m_intVar = 0;
    int *m_intPtr = nullptr;
    int m_size = 0;
    int m_strLength = 0;
    double m_doubleVar = 0.0;
    char *m_pChar = nullptr;
    DATATYPE m_type;
    std::vector<Variant> vl;
};

#endif
