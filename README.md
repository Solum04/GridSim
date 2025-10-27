[![Build](https://github.com/Solum04/GridSim/actions/workflows/ci.yml/badge.svg)](https://github.com/Solum04/GridSim/actions/workflows/ci.yml)
# GridSim (M0)

Scaffold med CMake, clang-format, CI, spdlog, nlohmann/json og Catch2.
Kjør:

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build -j
ctest --test-dir build --output-on-failure
./build/gridsim_app
