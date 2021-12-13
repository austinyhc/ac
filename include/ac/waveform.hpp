#ifndef AC_WAVEFORM_HPP
#define AC_WAVEFORM_HPP

#include "Eigen/Dense"
#include "NumCpp.hpp"
#include <typeinfo>

namespace ac {
class Waveform {
public:
    Waveform(const std::string& path) : _path(path) {
        _signals = nc::fromfile<int16_t>(_path).astype<float>();
        int n_samples = (int)(_signals.shape().cols / 32 / 2);
        _signals = _signals.reshape(n_samples, -1);
        std::cout << _signals.shape() << std::endl;

        //std::cout << _signals << std::endl;
    }

    std::string path() { return _path; }
    nc::NdArray<float> signals() { return _signals; }

private:
    std::string _path{""};
    nc::NdArray<float> _signals;
};
} // ac

#endif
