#pragma once
#include <vector>

std::vector<std::vector<int>> adjust_dpath(std::vector<std::vector<int>>& dpath, int& i, int& j, int& n);
std::vector<std::vector<double>> logcosh1(std::vector<std::vector<double>>& x, double& alpha);
std::vector<double> logcosh2(std::vector<std::vector<double>>& gx, double& alpha);