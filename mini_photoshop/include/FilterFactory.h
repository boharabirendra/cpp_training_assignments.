#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

#include "./Filter.h"
#include "../types/enums.h"

class FilterFactory
{
public:
    FilterFactory() = delete;
    FilterFactory(const FilterFactory &) = delete;
    static Filter *getFilter(int);
};

#endif