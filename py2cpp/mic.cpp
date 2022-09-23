#include "mic.h"

double mic_correlation(const std::vector<double>& x, const std::vector<double>& y) {
    py::gil_scoped_release release; // 释放GIL锁

    const int n = static_cast<int>(x.size());

    if (n != y.size()) {
        std::cout << "Make sure the vectors have the same number of values for the correlation function!" << std::endl;
        return 0;
    }

    double* xa = new double[n];
    double* ya = new double[n];
    memcpy(xa, &x[0], n * sizeof(x[0]));
    memcpy(ya, &y[0], n * sizeof(y[0]));

    MINE* mine = new MINE(0.6, 15, EST_MIC_APPROX);
    mine->compute_score(xa, ya, n);

    py::gil_scoped_acquire acquire; // C++执行结束前恢复GIL锁
    return mine->mic();
}