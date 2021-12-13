#include <catch2/catch_test_macros.hpp>
#include "ac/waveform.hpp"

typedef Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> EigenIntMatrix;
typedef Eigen::Map<EigenIntMatrix> EigenIntMatrixMap;

TEST_CASE ("Test everything.", "[single-file]") {
    ac::Waveform nth("frame_notouch.bin");

    REQUIRE(nth.path() == "frame_notouch.bin");
    REQUIRE(nth.signals().shape() == nc::Shape(128, 64));


    //nc::NdArray<int16_t> notouch = nc::fromfile<int16_t>("notouch.bin");
    //std::cout << nth._path << std::endl;
    //std::cout << nth._signals << std::endl;
    //std::cout << nth._signals.shape() << std::endl;
}

