#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <Eigen/Dense>
#include "ac/waveform.hpp"

TEST_CASE ("Load waveform", "[single-file]") {
    typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor> Matrix_MxN;
    Matrix_MxN notouch;
    Eigen::read_binary("matrix.dat", notouch);
    std::cout << "\n copy \n" << notouch << std::endl;
    std::cout.flush();
    //REQUIRE( m(0,0) == 3 );
}

