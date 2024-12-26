#include <memory>
#include <iostream>
#include <string.h>

class Variant
{
public:
    Variant() = delete;
    Variant(int intVar) : m_intVar(intVar), m_type(DATATYPE::INTEGER) {}
    Variant(bool boolVar) : m_boolVar(boolVar), m_type(DATATYPE::BOOLEN) {}
    Variant(std::initializer_list<Variant> l) : m_v(l), m_type(DATATYPE::ARRAY) {};
    Variant(double doubleVar) : m_doubleVar(doubleVar), m_type(DATATYPE::DOUBLE) {}

    Variant(const char *str) : m_type(DATATYPE::STRING)
    {
        m_strPtr = new char[strlen(str) + 1];
        strcpy(m_strPtr, str);
    }

    Variant(const Variant &v)
    {
        m_type = v.m_type;
        m_intVar = v.m_intVar;
        m_boolVar = v.m_boolVar;
        m_doubleVar = v.m_doubleVar;
        if (v.m_type == DATATYPE::STRING && v.m_strPtr)
        {
            m_strPtr = new char[strlen(v.m_strPtr)];
            strcpy(m_strPtr, v.m_strPtr);
        }
    }

    ~Variant()
    {
        if (m_strPtr != nullptr)
        {
            delete[] m_strPtr;
        }
    }

    int getIntVar() const { return m_intVar; }
    DATATYPE getType() const { return m_type; }
    bool getBoolVar() const { return m_boolVar; }
    const char *getStrPtr() const { return m_strPtr; }
    double getDoubleVar() const { return m_doubleVar; }
    std::vector<Variant> getArray() const { return m_v; }

private:
    int m_intVar;
    bool m_boolVar;
    DATATYPE m_type;
    double m_doubleVar;
    std::vector<Variant> m_v;
    char *m_strPtr = nullptr;
};
