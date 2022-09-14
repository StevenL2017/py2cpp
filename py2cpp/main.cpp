#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "corr.h"
#include "dtw.h"

namespace py = pybind11;

PYBIND11_MODULE(py2cpp, m) {
    m.doc() = "py2cpp module";
    m.def("corrcoef", &pearson_correlation);
    m.def("dtw", &dtw_distance);
}

//int main() {
//    int num_features = 20001;
//    int num_samples = 200;
//    std::vector<std::vector<double>> data(num_features, std::vector<double>(num_samples));
//    srand(time(0));
//    for (int i = 0; i < num_features; i++) {
//        for (int j = 0; j < num_samples; j++) {
//            data[i][j] = (double)rand() / 1e9;
//        }
//    }
//
//    time_t start, end;
//    start = clock();
//
//    std::vector<double> ans;
//    for (int i = 0; i < num_features - 1; i++) {
//        ans.push_back(pearson_correlation(data[i], data.back()));
//    }
//
//    end = clock();
//    std::cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
//    return 0;
//}