/** 
 * Author: Bao Luong
 * Description: Range filter extends from the base class filter
 */

#ifndef RANGE_FILTER_HPP
#define RANGE_FILTER_HPP

#include "filter.hpp"

namespace lidar_filter {
    class RangeFilter : Filter {
        double rangeMin;
        double rangeMax;
    public:
        RangeFilter(double min, double max);
        virtual std::vector<double>& update(std::vector<double> &currentScan);
    };
}

#endif /* !RANGE_FILTER_HPP */