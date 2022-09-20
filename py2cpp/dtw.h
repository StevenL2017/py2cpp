#pragma once

#include <cmath>
#include <vector>
#include <algorithm>
#include <pybind11/stl.h>
#include <pybind11/embed.h>

namespace py = pybind11;

double dtw_distance(const std::vector<double>& x, const std::vector<double>& y);