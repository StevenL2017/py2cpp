#pragma once

#include <iostream>
#include <vector>
#include "cppmine.h"
#include <pybind11/stl.h>
#include <pybind11/embed.h>

namespace py = pybind11;

double mic_correlation(const std::vector<double>& x, const std::vector<double>& y);