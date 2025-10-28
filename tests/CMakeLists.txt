if(NOT BUILD_TESTING)
  return()
endif()

# Ensure assets are available for tests
add_custom_target(copy_test_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/tests/assets
)

add_executable(gridsim_tests
        test_sanity.cpp
        test_config.cpp
        test_clock.cpp
        test_app_loop.cpp
        test_registry.cpp
)
target_link_libraries(gridsim_tests PRIVATE gridsim Catch2::Catch2WithMain)
add_dependencies(gridsim_tests copy_test_assets)

include(Catch)
catch_discover_tests(gridsim_tests)

