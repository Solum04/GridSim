//
// Created by krist on 28.10.2025.
//

#ifndef ISIMULATION_H
#define ISIMULATION_H
#pragma once

namespace gs {

class ISimulation {
public:
    virtual ~ISimulation() = default;
    virtual void update(float dt) = 0; // fast dt (sekunder)
    virtual void render() = 0;         // 1x per frame
};

} // namespace gs

#endif //ISIMULATION_H
