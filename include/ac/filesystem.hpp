#pragma once

#include <fstream>
#include <string>

namespace ac {
namespace filesystem {

class File {
public:
    explicit File(const std::string& fullname) : _fullname(fullname)
    {
        const size_t found = fullname.find_last_of('.');
        _filename = fullname.substr(0, found);

        if (found != std::string::npos) {
            _suffix   = fullname.substr(found+1, std::string::npos);
        }

        std::ifstream f(fullname.c_str());
        _exists = f.good();
    }

    bool exists() const noexcept { return _exists; }
    const std::string suffix() const noexcept { return _suffix; }
    std::string name() const { return _filename + "." + _suffix; }
    const std::string stem() const noexcept { return _filename; }

private:
    std::string _fullname{""};
    std::string _filename{""};
    std::string _suffix{""};
    bool _exists{false};
};
} // namespace filesystem
} // namespace ac
