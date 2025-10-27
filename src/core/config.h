#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace gs {
nlohmann::json load_config(const std::string& path);
}
