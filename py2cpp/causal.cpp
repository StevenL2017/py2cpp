#include "causal.h"
#include <cmath>
#include <vector>

void adjust_dpath(std::vector<std::vector<int>>& dpath, int& i, int& j, int& n) {
	dpath[j][i] = 1;
	for (int k = 0; k < n; k++) {
		if (dpath[i][k] == 1) {
			dpath[j][k] = 1;
		}
		if (dpath[k][j] == 1) {
			dpath[k][i] = 1;
		}
	}
	return;
}

std::vector<std::vector<double>> logcosh1(std::vector<std::vector<double>>& x, double& alpha) {
	const int m = static_cast<int>(x.size());
	const int n = static_cast<int>(x[0].size());

	std::vector<std::vector<double>> gx(m, std::vector<double>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			gx[i][j] = std::tanh(x[i][j] * alpha);
		}
	}
	return gx;
}

std::vector<double> logcosh2(std::vector<std::vector<double>>& gx, double& alpha) {
	const int m = static_cast<int>(gx.size());
	const int n = static_cast<int>(gx[0].size());

	std::vector<double> g_x(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			g_x[i] = g_x[i] + alpha * (1 - gx[i][j] * gx[i][j]);
		}
		g_x[i] = (double)g_x[i] / n;
	}
	return g_x;
}