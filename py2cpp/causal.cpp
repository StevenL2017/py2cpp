#include "causal.h"
#include <vector>

std::vector<std::vector<int>> adjust_dpath(std::vector<std::vector<int>> &dpath, int &i, int &j, int &n) {
	dpath[j][i] = 1;
	for (int k = 0; k < n; k++) {
		if (dpath[i][k] == 1) {
			dpath[j][k] = 1;
		}
		if (dpath[k][j] == 1) {
			dpath[k][i] = 1;
		}
	}
	return dpath;
}