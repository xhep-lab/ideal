#ifndef IDEAL_HPP_
#define IDEAL_HPP_

/**
Unbiased likelihood estimator
*/

#include <algorithm>
#include <cmath>
#include <random>


namespace ideal {

double log_factorial(double k) {
    return std::lgamma(k + 1);
}

double beta(double x, double y) {
    return std::tgamma(x) * std::tgamma(y) / std::tgamma(x + y);
}

double binom(double n, double k) {
    if (n < k) {
        return 0.;
    }
    return 1. / ((n + 1.) * beta(n - k + 1., k + 1.));
}

template <typename engine_type>
int umvue_draw_n_mc(double n_mc, engine_type engine) {
    std::poisson_distribution<> poisson(n_mc);
    return poisson(engine);
}

int umvue_draw_n_mc(double n_mc) {
    std::random_device rd;
    std::mt19937 engine(rd());
    return umvue_draw_n_mc(n_mc, engine);
}

double umvue_poisson_like(int k, double b, int o, int n_mc, double n_exp) {
    if ((n_mc <= 0) || (n_exp <= 0)) {
        throw std::runtime_error("n_mc <= 0 || n_exp <= 0");
    }

    const double f = n_exp / n_mc;

    // special case b = 0 and maybe f = 1

    if (b == 0) {
        if (f == 1.) {
            return 1. ? k == o : 0.;
        }
        return binom(k, o) * std::pow(f, k) * std::pow(1. - f, k - o);
    }

    // special case b !=0 but f = 1

     if (f == 1.) {
        if (k > o) {
             return 0.;
        }

        const double ln_like = -b + (o - k) * std::log(b) -log_factorial(o - k);
        return std::exp(ln_like);
    }

    // general cases

    double sum = 0.;
    double term = 1.;
    const double r = f / (1. - f) / b;

    for (int i = 0; i <= std::min(k, o); i++) {
        sum += term;
        term *= r * (k - i) * (o - i) / (i + 1);
    }

    const double ln_norm = o * std::log(b) - b - log_factorial(o);
    const double norm = std::exp(ln_norm);

    return norm * std::pow(1. - f, k) * sum;
}

}  // end namespace ideal

#endif  // IDEAL_HPP_
