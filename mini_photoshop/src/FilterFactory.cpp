#include "../types/enums.h"
#include "../include/GrayScale.h"
#include "../include/MedianFilter.h"
#include "../include/FilterFactory.h"

Filter *FilterFactory::getFilter(int opt)
{
    Filter *filter;

    switch (static_cast<FILTERTYPES>(opt))
    {
    case FILTERTYPES::MEDIAN:
        filter = new MedianFilter();
        break;
    case FILTERTYPES::GrayScale:
        filter = new GrayScale();
        break;
    default:
        std::cout << "fuck you";
        break;
    }

    return filter;
}