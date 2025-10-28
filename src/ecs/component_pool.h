//
// Created by krist on 28.10.2025.
//

#ifndef COMPONENT_POOL_H
#define COMPONENT_POOL_H
#pragma once
#include <vector>
#include <limits>
#include <cstdint>
#include <utility>

#include "ecs/entity.h" // assuming this defines using Entity = uint32_t;

// component_pool.h
#pragma once
#include <vector>
#include <limits>
#include "ecs/entity.h"

namespace gs {

template <typename T>
class ComponentPool {
public:
    static constexpr size_t npos = std::numeric_limits<size_t>::max();

    void ensure_sparse(Entity e) {
        if (sparse_.size() <= e)
            sparse_.resize(e + 1, npos);
    }

    bool has(Entity e) const {
        if (e >= sparse_.size()) return false;
        auto pos = sparse_[e];
        return pos != npos && pos < entities_.size() && entities_[pos] == e;
    }

    T* get(Entity e) {
        if (!has(e)) return nullptr;
        return &dense_[sparse_[e]];
    }

    const T* get(Entity e) const {
        if (!has(e)) return nullptr;
        return &dense_[sparse_[e]];
    }

private:
    std::vector<T> dense_;
    std::vector<Entity> entities_;
    std::vector<size_t> sparse_;
};

} // namespace gs


#endif //COMPONENT_POOL_H
