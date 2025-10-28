//
// Created by krist on 28.10.2025.
//

#ifndef REGISTRY_H
#define REGISTRY_H
#pragma once
#include <vector>
#include <queue>
#include "entity.h"

namespace gs {

class Registry {
public:
    Registry() = default;

    Entity create();           // ny entity-id (gjenbruker fra freelist)
    void destroy(Entity e);    // marker som død
    bool alive(Entity e) const;

    // (kommer senere) hooks for komponent-pooler

private:
    // Generasjons-basert gyldighet kan komme senere; nå holder vi det enkelt
    std::vector<bool> m_alive;   // index = Entity id, true hvis aktiv
    std::queue<Entity> m_free;   // gjenbrukte id-er
    Entity m_next{1};            // 0 er reservert som kInvalid
};

} // namespace gs

#endif //REGISTRY_H
