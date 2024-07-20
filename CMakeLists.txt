cmake_minimum_required(VERSION 3.15)
project(Pong VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(ALLEGRO5 REQUIRED
	allegro-5
	allegro_main-5
	allegro_font-5
	allegro_primitives-5
	allegro_ttf-5
	allegro_audio-5
	allegro_acodec-5)

add_subdirectory(settings)
add_subdirectory(src)

add_executable(main main.c)

target_link_libraries(main ${ALLEGRO5_LIBRARIES} src settings)

target_include_directories(main PUBLIC ${ALLEGRO5_INCLUDE_DIRS})
target_compile_options(main PUBLIC ${ALLEGRO5_CFLAGS_OTHER})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
