add_library(settings "")

target_sources(
  settings
  PRIVATE Settings.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Settings.hpp)

target_include_directories(settings PUBLIC . ${SFML_INCLUDE_DIRS})

target_link_libraries(settings ${SFML_LIBRARIES})
