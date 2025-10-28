[![Build](https://github.com/Solum04/GridSim/actions/workflows/ci.yml/badge.svg)](https://github.com/Solum04/GridSim/actions/workflows/ci.yml)

# GridSim

Modulær 2D-sim-engine i C++17 for læring og gjenbruk (Snake, boids, trafikk, platformer).

## Status
- **M0 – Scaffold & hygiene**: CMake, clang-format, CI, spdlog, nlohmann/json, Catch2 ✅
- **M1 – Fixed timestep loop**: Clock, ISimulation, Application-loop, DummySim + tester ✅

## Kjøring
```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build -j
ctest --test-dir build --output-on-failure
./build/gridsim_app   # .exe på Windows
```
## Struktur
```
src/
  core/          # logger, config, clock, application (fixed timestep)
  sims/          # ISimulation + DummySim (demo)
  ecs/           # (M2) entity, components, systems
tests/
  test_clock.cpp
  test_app_loop.cpp
assets/
  config.json

