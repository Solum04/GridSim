add_library(gridsim
    core/logger.cpp
    core/config.cpp
    core/clock.cpp
    core/application.cpp
    sims/dummy_sim.cpp
)

target_include_directories(gridsim PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gridsim PUBLIC spdlog::spdlog_header_only nlohmann_json::nlohmann_json)


add_executable(gridsim_app main.cpp)
target_link_libraries(gridsim_app PRIVATE gridsim)


# Copy assets folder for runtime and tests
add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/assets
)
add_dependencies(gridsim_app copy_assets)