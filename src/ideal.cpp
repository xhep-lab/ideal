#include <pybind11/pybind11.h>
#include "ideal.hpp"


// specify overload for pybind
inline int this_umvue_draw_n_mc(double lambda_mc) {
    return ideal::umvue_draw_n_mc(lambda_mc);
}

PYBIND11_MODULE(ideal, m) {
    m.def("umvue_poisson_like", &ideal::umvue_poisson_like, "UMVUE estimator of Poisson likelihood");
    m.def("umvue_draw_n_mc", &this_umvue_draw_n_mc, "UMVUE draw number of events to simulate");
}
