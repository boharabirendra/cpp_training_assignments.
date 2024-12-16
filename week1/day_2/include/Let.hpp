#ifndef LET_H
#define LET_H

#include <string.h>
#include <iostream>

#include "../constants/Let.hpp"

class Let
{
public:
    Let();
    Let(const char *str);
    Let(const Let &let);

    Let(int intVar);
    Let(double doubleVar);

    ~Let() { delete[] m_pChar; }

    Let &operator+(int intVar);
    Let &operator-(Let &let);
    Let &operator-(int intVar);
    Let &operator=(int intVar);

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
};

#endif
