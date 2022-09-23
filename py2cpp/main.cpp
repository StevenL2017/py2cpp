#include "corr.h"
#include "dtw.h"
#include "mic.h"
#include "causal.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(py2cpp, m) {
    m.doc() = "py2cpp module";
    m.def("pearson", &pearson_correlation);
    m.def("dtw", &dtw_distance);
    m.def("spearman", &spearman_correlation);
    m.def("mic", &mic_correlation);
    m.def("adjust_dpath", &adjust_dpath);
    m.def("logcosh", &logcosh);
}