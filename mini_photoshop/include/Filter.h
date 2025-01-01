#ifndef FILTER_H
#define FILTER_H

#include <vector>

#include "../types/structs.h"

class Filter
{
public:
    virtual std::vector<std::vector<RGB>> apply(std::vector<std::vector<RGB>> &) = 0;
};

#endif