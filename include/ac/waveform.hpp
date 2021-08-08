#ifndef AC_WAVEFORM_HPP
#define AC_WAVEFORM_HPP

#include <tuple>
#include <Eigen/Dense>
#include <iostream>
#include <fstream>

namespace Eigen {

template<class Matrix>
void read_binary(const char* filename, Matrix& matrix) {
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    typename Matrix::Index rows=0, cols=0;
    in.read((char*) (&rows),sizeof(typename Matrix::Index));
    in.read((char*) (&cols),sizeof(typename Matrix::Index));
    matrix.resize(rows, cols);
    in.read( (char *) matrix.data() , rows*cols*sizeof(typename Matrix::Scalar) );
    in.close();
}
} // Eigen

#endif
