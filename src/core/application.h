//
// Created by krist on 28.10.2025.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once
#include <memory>
#include <nlohmann/json.hpp>

namespace gs {

class ISimulation;

class Application {
public:
    // tick_rate: oppdateringer per sekund (f.eks. 60)
    explicit Application(int tick_rate);

    // Kjør i 'seconds' sekunder (M1 slutter automatisk her)
    void run_for_seconds(double seconds, ISimulation& sim);

private:
    int m_tick_rate;
};

} // namespace gs

#endif //APPLICATION_H
