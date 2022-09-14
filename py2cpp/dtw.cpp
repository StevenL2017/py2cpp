#include "dtw.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

double dtw_distance(const std::vector<double> &x, const std::vector<double> &y, int w) {
    // initialize constants
    const double inf_ = std::numeric_limits<double>::infinity();
    const int x_length_ = static_cast<int>(x.size());
    const int y_length_ = static_cast<int>(y.size());

    std::vector<std::vector<double>> d(x_length_, std::vector<double>(y_length_));
    double dist;

    // Initialize all dtw matrix elements to infnty
    for (int i = 0; i < x_length_; ++i) {
        d[i][0] = inf_;
    }
    for (int i = 0; i < y_length_; ++i) {
        d[0][i] = inf_;
    }
    d[0][0] = 0;

    // add locality constraint
    w = std::max(w, std::abs(x_length_ - y_length_));

    // Determine the optimal dtw path via dynamic programming,
    // specifically the recursive function outlined on wiki:
    // https://en.wikipedia.org/wiki/Dynamic_time_warping
    for (int i = 1; i < x_length_; ++i) {
        // adapt inner loop to window size
        for (int j = std::max(1, i - w); j < std::min(y_length_, i + w); ++j) {
            dist = std::pow(x[i] - y[j], 2);
            d[i][j] = dist + std::min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]});
        }
    }

    // compute distance metric
    return std::sqrt(d[x_length_ - 1][y_length_ - 1]);
}