include(FetchContent)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)

# config gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

# add an executable with the above sources
add_executable(unit_tests
  circle_test.cc
  rectangle_test.cc
  triangle_test.cc
)

# necessary static libs
target_link_libraries(unit_tests
  PRIVATE
    sourcepack
    gtest_main
    gmock_main
)

# run unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT # crashing time-out
    240
)