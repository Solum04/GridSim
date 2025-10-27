# GridSim (M0)

Scaffold med CMake, clang-format, CI, spdlog, nlohmann/json og Catch2.
Kjør:

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build -j
ctest --test-dir build --output-on-failure
./build/gridsim_app
