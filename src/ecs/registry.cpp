//
// Created by krist on 28.10.2025.
//
#include "registry.h"
#include <stdexcept>

namespace gs {

Entity Registry::create() {
    Entity id;
    if (!m_free.empty()) {
        id = m_free.front();
        m_free.pop();
    } else {
        id = m_next++;
        if (m_alive.size() <= id) {
            m_alive.resize(id + 1, false);
        }
    }
    m_alive[id] = true;
    return id;
}

void Registry::destroy(Entity e) {
    if (e == kInvalidEntity || e >= m_alive.size() || !m_alive[e]) return;
    m_alive[e] = false;
    m_free.push(e);
    // (senere: fjerne komponenter for e)
}

bool Registry::alive(Entity e) const {
    return (e != kInvalidEntity) && (e < m_alive.size()) && m_alive[e];
}

} // namespace gs
