#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <pybind11/stl.h>
#include <pybind11/embed.h>

namespace py = pybind11;

double pearson_correlation(const std::vector<double>& x, const std::vector<double>& y);
double spearman_correlation(const std::vector<double>& x, const std::vector<double>& y);