#pragma once

#include <cmath>
#include <Eigen/Dense>
#include <pybind11/eigen.h>

void adjust_dpath(Eigen::Ref<Eigen::MatrixXi> dpath, int& i, int& j, int& n);
Eigen::VectorXd logcosh(Eigen::Ref<Eigen::MatrixXd> x, double& alpha);