cmake_minimum_required(VERSION 3.15)
project(FlappyBird VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SFML REQUIRED sfml-graphics sfml-audio sfml-window
                  sfml-system)

add_subdirectory(settings)
add_subdirectory(src)

add_executable(main main.cpp)

target_compile_features(main PRIVATE cxx_std_17)

target_link_libraries(main ${SFML_LIBRARIES} src settings)

target_include_directories(main PUBLIC ${SFML_INCLUDE_DIRS})
target_compile_options(main PUBLIC ${SFML_CFLAGS_OTHER})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
