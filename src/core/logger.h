#pragma once
#include <memory>
#include <spdlog/spdlog.h>

namespace gs {
void init_logger();
std::shared_ptr<spdlog::logger> logger();
}
