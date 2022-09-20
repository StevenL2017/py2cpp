#include "corr.h"

double pearson_correlation(const std::vector<double>& x, const std::vector<double>& y) {
    py::gil_scoped_release release; // 释放GIL锁

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
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
        sum_y_squared += y[i] * y[i];
    }

    double ans = (double)(n * sum_xy - sum_x * sum_y) / (sqrt(n * sum_x_squared - sum_x * sum_x) * sqrt(n * sum_y_squared - sum_y * sum_y));

    py::gil_scoped_acquire acquire; // C++执行结束前恢复GIL锁
    return ans;
}