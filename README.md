<h1 align="center">
 💡 Ideal
</h1>

<div align="center">
<i>This is a header-only C++ implementation & Python bindings of the uniform minimum variance unbiased estimator (UMVUE) for a Poisson likelihood in the context of collider physics. </i>
</div>

## ✨ Install

### Through pip

This installs the module by compiling the C++ on the fly:

    pip install .
    
### Through cmake

    mkdir build
    cd build
    cmake ..
    make
    
## Test

Test the code by running

    pytest .
    
## Run

See `./examples` for C++ example. For Python, try e.g.,

    from ideal import umvue_poisson_like
    
    k = 1
    b = 5
    o = 5
    n_mc = 1000
    n_exp = 10000
    umvue_poisson_like(k, b, o, n_mc, n_exp)
