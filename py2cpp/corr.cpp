#include "corr.h"

double pearson_correlation(const std::vector<double>& x, const std::vector<double>& y) {
    py::gil_scoped_release release; // ÊÍ·ÅGILËø

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

    py::gil_scoped_acquire acquire; // C++Ö´ÐÐ½áÊøÇ°»Ö¸´GILËø
    return ans;
}

std::vector<int> rank(const std::vector<double>& x) {
    const int n = static_cast<int>(x.size());

    std::vector<int> index(n);
    std::iota(index.begin(), index.end(), 0);
    std::sort(index.begin(), index.end(), [&x](int i, int j) {return (x[i] > x[j]);});

    std::vector<int> rank(n);
    std::iota(rank.begin(), rank.end(), 0);
    std::sort(rank.begin(), rank.end(), [&index](int i, int j) {return (index[i] < index[j]);});
    return rank;
}

double spearman_correlation(const std::vector<double>& x, const std::vector<double>& y) {
    py::gil_scoped_release release; // ÊÍ·ÅGILËø

    const int n = static_cast<int>(x.size());

    if (n != y.size()) {
        std::cout << "Make sure the vectors have the same number of values for the correlation function!" << std::endl;
        return 0;
    }

    std::vector<int> rx = rank(x);
    std::vector<int> ry = rank(y);

    long long d = 0LL;

    for (int i = 0; i < n; i++) {
        d += (rx[i] - ry[i]) * (rx[i] - ry[i]);
    }

    double ans = 1.0 - (double)6 * d / (n * (n * n - 1));

    py::gil_scoped_acquire acquire; // C++Ö´ÐÐ½áÊøÇ°»Ö¸´GILËø
    return ans;
}