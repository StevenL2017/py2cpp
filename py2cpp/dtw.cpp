#include "dtw.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

double dtw_distance(const std::vector<double>& x, const std::vector<double>& y) {
    // initialize constants
    const int nx = static_cast<int>(x.size());
    const int ny = static_cast<int>(y.size());

    // Initialize all dtw matrix elements to infinity
    std::vector<std::vector<double>> d(nx + 1, std::vector<double>(ny + 1, INFINITY));
    d[0][0] = 0;
    double dist;

    // Determine the optimal dtw path via dynamic programming,
    for (int i = 1; i <= nx; i++) {
        for (int j = 1; j <= ny; j++) {
            dist = std::abs(x[i - 1] - y[j - 1]);
            d[i][j] = dist + std::min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] });
        }
    }
    return d[nx][ny];
}