#ifndef CPP_PLOTTER_H
#define CPP_PLOTTER_H

#include <vector>
#include <string>

namespace cpp_plotter {

struct Plot {
    std::vector<double> x;
    std::vector<double> y;
    int show(const std::string &title="Plot")const;
};

} // namespace cpp_plotter

#endif
