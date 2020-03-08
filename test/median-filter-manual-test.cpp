#include "../include/median-filter.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>

std::string printVector(const std::vector<double> &v) {
    std::ostringstream output;
    for(const auto &num : v)
        output << std::left << std::setw(6) << std::setprecision(2) << num;
    return output.str();
}

int main() {
    int N = 5;
    int D = 3;
    int T = 5;

    lidar_filter::MedianFilter filter(D);
    std::vector<std::vector<double>> scan(T);

    scan[0] = {0.0, 1.0, 2.0, 1.0, 3.0};
    scan[1] = {1.0, 5.0, 7.0, 1.0, 3.0};
    scan[2] = {2.0, 3.0, 4.0, 1.0, 0.0};
    scan[3] = {3.0, 3.0, 3.0, 1.0, 3.0};
    scan[4] = {10.0, 2.0, 4.0, 0.0, 0.0};

    const int WIDTH = 30;
    const int NUM_FIELDS = 3;
    const std::string SEPARATOR = " |";
    const int TOTAL_WIDTH = (WIDTH + SEPARATOR.size()) * NUM_FIELDS;
    const std::string LINE = SEPARATOR + std::string(TOTAL_WIDTH - 1, '-') + '|';

    std::cout << std::left
              << LINE << '\n'
              << SEPARATOR
              << std::setw(WIDTH) << "T (time)" << SEPARATOR
              << std::setw(WIDTH) << "X (current scan)" << SEPARATOR
              << std::setw(WIDTH) << "Y (updated scan)" << SEPARATOR
              << '\n'
              << LINE << '\n';

    for (int t = 0; t < T; t++) {
        std::cout << std::left
                  << SEPARATOR
                  << std::setw(WIDTH) << t << SEPARATOR
                  << std::setw(WIDTH) << printVector(scan[t]) << SEPARATOR
                  << std::setw(WIDTH) << printVector(filter.update(scan[t])) << SEPARATOR
                  << '\n';
    }
    std::cout << LINE << '\n';

    return 0;
}