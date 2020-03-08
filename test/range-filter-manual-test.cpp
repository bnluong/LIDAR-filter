#include "../include/range-filter.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>

int main() {
    srand((unsigned)time(0));

    int n = 5;
    int max = 50;
    int min = 0.03;

    lidar_filter::RangeFilter filter(min, max);
    std::vector<double> scan;

    for (int i = 0; i < n; i++) {
        double num = ((double)rand() * ((max + 2) - (min - 2)) / (double)RAND_MAX - min);
        scan.push_back(num);
    }

    std::cout << "\nScan before filtering with range filter: \t";
    for (auto num : scan)
        std::cout << std::left << std::setw(5) << std::setprecision(2) << num << " ";
    std::cout << std::endl;

    scan = filter.update(scan);

    std::cout << "Scan after filtering with range filter: \t";
    for (auto num : scan)
        std::cout << std::left << std::setw(5) << std::setprecision(2) << num << " ";
    std::cout << std::endl
              << std::endl;

    return 0;
}