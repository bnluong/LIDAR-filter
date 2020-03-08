/** 
 * Author: Bao Luong
 * Description: Abstract class filter represents a base filter
 */

#ifndef LIDAR_FILTER_HPP
#define LIDAR_FILTER_HPP

#include <vector>

namespace lidar_filter {
    class Filter {
    public:
       virtual std::vector<double>& update(std::vector<double> &currentScan) = 0;
    };
}

#endif /* !LIDAR_FILTER_HPP */