#include "causal.h"

void adjust_dpath(Eigen::Ref<Eigen::MatrixXi> dpath, int& i, int& j, int& n) {
	dpath(j, i) = 1;
	for (int k = 0; k < n; k++) {
		if (dpath(i, k) == 1) {
			dpath(j, k) = 1;
		}
		if (dpath(k, j) == 1) {
			dpath(k, i) = 1;
		}
	}
	return;
}

Eigen::VectorXd logcosh(Eigen::Ref<Eigen::MatrixXd> x, double& alpha) {
	const int m = static_cast<int>(x.rows());
	const int n = static_cast<int>(x.cols());

	x *= alpha;
	Eigen::VectorXd g_x(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			x(i, j) = std::tanh(x(i, j));
			g_x(i) += alpha * (1 - x(i, j) * x(i, j));
		}
		g_x(i) = (double)g_x(i) / n;
	}
	return g_x;
}