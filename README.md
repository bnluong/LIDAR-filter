# LIDAR Filter

Various LIDAR filters that can be used on data collected by LIDAR sensors.

## Getting Started

### Prerequisites & Dependencies

```
1. Environment: Linux
2. Language: C++
3. Tools and libraries: CMake, c++11 stl
```

### Getting the Source Code

This project is [hosted on GitHub](https://github.com/bnluong/LIDAR-filters). You can clone this project directly using this command:

```
git clone git@github.com:bnluong/LIDAR-filters.git
```

### Building the Project

```
1. Go to root directory of the project i.e LIDAR-filter/
2. Open terminal and type the command: cmake .
3. CMake will create a Makefile to compile the tests. 
4. Compile by typing the command: make
5. There are two tests that test each filter object
```

## Running Tests

These are manual tests to see if the filters work on sample data and specs
```
In the root directory of the project type: 
1. ./bin/range-filter-manual-test.out - This tests the range filter
2. ./bin/median-filter-manual-test.out - This tests the median filter
```

## Usage

The filters can be included to operate on your data. To do so, copy the "include" folder and "src" folder to your project and include it in your code.

For example: How to use range filter

```
#include "../include/range-filter.hpp"

int main() {
	lidar_filter::RangeFilter filter(min, max);
	
	/* do some work with range filter */
	
	return 0;
}
```

My current plan is to make more filters and make a stand-alone API

## Built With

* [CMake](https://cmake.org/) - CMake to generate a Makefile to compile and run the tests

## Authors

* **Bao Luong** - *Owner* - [bnluong](https://github.com/bnluong)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
