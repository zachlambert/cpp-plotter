#include "cpp_plotter.h"

using namespace cpp_plotter;

int main()
{
    Plot plot;
    plot.x = {0, 1, 2, 3};
    plot.y = {1, 2, 2, 1};
    return plot.show();
}
