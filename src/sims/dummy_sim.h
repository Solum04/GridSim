//
// Created by krist on 28.10.2025.
//

#ifndef DUMMY_SIM_H
#define DUMMY_SIM_H
#pragma once
#include "isimulation.h"
#include <cstddef>

namespace gs {

// Veldig enkel demo: teller oppdateringer og renders.
// Logger hvert ~1 sekund for å ikke spamme.
class DummySim : public ISimulation {
public:
    void update(float dt) override;
    void render() override;

    // For logging i main etterpå
    std::size_t updates() const { return m_updates; }
    std::size_t renders() const { return m_renders; }

private:
    std::size_t m_updates{0};
    std::size_t m_renders{0};
    double m_accum_log{0.0}; // akkumulert tid for sjeldnere logging
};

} // namespace gs

#endif //DUMMY_SIM_H
