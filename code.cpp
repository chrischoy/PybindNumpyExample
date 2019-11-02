#include <pybind11/eigen.h>
#include <pybind11/numpy.h>

#include <Eigen/LU>

namespace py = pybind11;

using RowMatrixXd =
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

// Passing in an array of doubles
void twice(py::array_t<double> xs) {
  py::buffer_info info = xs.request();
  auto ptr = static_cast<double *>(info.ptr);

  int n = 1;
  for (auto r : info.shape) {
    n *= r;
  }

  for (int i = 0; i < n; i++) {
    *ptr++ *= 2;
  }
}

// Passing in a generic array
double sum(py::array xs) {
  py::buffer_info info = xs.request();
  auto ptr = static_cast<double *>(info.ptr);

  int n = 1;
  for (auto r : info.shape) {
    n *= r;
  }

  double s = 0.0;
  for (int i = 0; i < n; i++) {
    s += *ptr++;
  }

  return s;
}

// takes numpy array as input and returns double
double det(Eigen::MatrixXd xs) { return xs.determinant(); }

void scale_inplace(Eigen::Ref<RowMatrixXd> xs, double c) { xs *= c; }
RowMatrixXd scale(RowMatrixXd xs, double c) { return xs * c; }

PYBIND11_MODULE(wrap, m) {
  m.def("sum", &sum);
  m.def("twice", &twice);
  m.def("det", &det);
  m.def("scale", &scale);
  m.def("scale_inplace", &scale_inplace);
}
