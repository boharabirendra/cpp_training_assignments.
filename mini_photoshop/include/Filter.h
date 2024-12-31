#pragma once

class Filter
{
public:
    virtual void apply(unsigned char *img) = 0;
};

class MedianFilter : public Filter
{
public:
    void apply(unsigned char *img) override
    {
    }
};
