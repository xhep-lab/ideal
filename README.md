# Ideal

This is a C++ implementation of the minimum variance unbiased estimator for a Poisson likelihood with Python bindings.

# Install

## Through pip

    pip install .
    
## Through cmake

    mkdir build
    cd build
    cmake ..
    make
    
# Tests

Run

    pytest .
    
# Usage

See `./examples` for C++ example. For Python, try e.g.,

    from ideal import umvue_poisson_like
    
    k = 1
    b = 5
    o = 5
    n_mc = 1000
    n_exp = 10000
    umvue_poisson_like(k, b, o, n_mc, n_exp)