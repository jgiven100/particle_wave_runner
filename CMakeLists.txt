cmake_minimum_required(VERSION 3.20)

project(particle_wave_runner LANGUAGES CXX)

# -----------------------------------------------------------------------------
# Global configuration
# -----------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(PWR_BUILD_TESTS "Build tests" ON)
option(PWR_BUILD_DOCS "Build documentation" ON)

# -----------------------------------------------------------------------------
# Dependencies
# -----------------------------------------------------------------------------

find_package(MPI REQUIRED)

# -----------------------------------------------------------------------------
# Core library
# -----------------------------------------------------------------------------

add_library(pwr_core
    src/mesh.cpp
)

target_include_directories(pwr_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(pwr_core
    PUBLIC
        MPI::MPI_CXX
)

target_compile_features(pwr_core PUBLIC cxx_std_20)

# -----------------------------------------------------------------------------
# Executable
# -----------------------------------------------------------------------------

add_executable(particle_wave_runner
    src/main.cpp
)

target_link_libraries(particle_wave_runner 
    PRIVATE
        pwr_core
)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------

if(PWR_BUILD_TESTS)
    # TODO
endif()

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------

if(PWR_BUILD_DOCS)
    # TODO
endif()

