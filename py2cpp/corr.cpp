#include "corr.h"
#include <iostream>
#include <cmath>
#include <vector>

double pearson_correlation(const std::vector<double>& x, const std::vector<double>& y) {
    const int n = static_cast<int>(x.size());

    if (n != y.size()) {
        std::cout << "Make sure the vectors have the same number of values for the correlation function!" << std::endl;
        return 0;
    }

    double sum_x = 0;
    double sum_y = 0;
    double sum_xy = 0;
    double sum_x_squared = 0;
    double sum_y_squared = 0;

    for (int i = 0; i < n; i++) {
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_xy = sum_xy + x[i] * y[i];
        sum_x_squared = sum_x_squared + x[i] * x[i];
        sum_y_squared = sum_y_squared + y[i] * y[i];
    }

    return (double)(n * sum_xy - sum_x * sum_y) / (sqrt(n * sum_x_squared - sum_x * sum_x) * sqrt(n * sum_y_squared - sum_y * sum_y));
}