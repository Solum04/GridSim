//
// Created by krist on 28.10.2025.
//
#include "dummy_sim.h"
#include "../core/logger.h"

namespace gs {

void DummySim::update(float dt) {
    m_updates++;
    m_accum_log += dt;

    // Logg ca. hvert sekund, så vi ser at updates tikker jevnt
    if (m_accum_log >= 1.0) {
        logger()->info("[DummySim] ~1s passed, updates so far: {}", m_updates);
        m_accum_log = 0.0;
    }
}

void DummySim::render() {
    m_renders++;
    // Bevisst ingen logging her for å unngå spam
}

} // namespace gs
