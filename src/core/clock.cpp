//
// Created by krist on 28.10.2025.
//

#include "clock.h"
#include <thread>

namespace {
// Starttiden ved programstart (første gang denne fila lastes)
const auto START_TIME = std::chrono::steady_clock::now();
}

namespace gs {
double now_seconds() {
    using namespace std::chrono;
    const auto now = steady_clock::now();
    duration<double> d = now - START_TIME;
    return d.count(); // sekunder
}

void sleep_ms(int ms) {
    if (ms <= 0) return;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
}

