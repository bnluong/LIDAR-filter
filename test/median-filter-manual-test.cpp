#include "../include/median-filter.hpp"
#include <vector>
#include <iostream>

int main() {
    int n = 5;
    int d = 3;

    lidar_filter::MedianFilter filter(d);
    std::vector<double> scan {0.0, 1.0, 2.0, 1.0, 3.0};

    std::cout << "\nScan before filtering with range filter: \t";
    for(auto num : scan)
        std::cout << num << " ";
    std::cout << std::endl;

    scan = filter.update(scan);
    
    std::cout << "Scan after filtering with range filter: \t";
    for(auto num : scan)
        std::cout << num << " ";
    std::cout << std::endl << std::endl;

    std::vector<double> scan1 {0.1, 1.2, 2.3, 1.4, 3.5};
    scan = filter.update(scan);

    return 0;
}