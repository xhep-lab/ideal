#include <iostream>
#include "ideal.hpp"

int main(int, char**) {
    std::cout << ideal::umvue_poisson_like(1000, 10, 20, 10000, 100) << std::endl;
    std::cout << ideal::umvue_draw_n_mc(1000) << std::endl;
}
