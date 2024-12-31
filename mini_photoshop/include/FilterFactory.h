#pragma once

#include "./Filter.h"

class FilterFactory
{
public:
    virtual Filter *createFilter() = 0;
};

class MedianFilterFactory : public FilterFactory
{
public:
    Filter *createFilter() override
    {
        return new MedianFilter();
    }
};