#include "config.h"
#include <fstream>
#include <stdexcept>

namespace gs {
nlohmann::json load_config(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        throw std::runtime_error("Could not open config file: " + path);
    }
    nlohmann::json j;
    in >> j;
    return j;
}
}
