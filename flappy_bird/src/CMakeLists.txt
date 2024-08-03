add_library(src "")

target_sources(
  src
  PRIVATE Bird.cpp
          Game.cpp
          Log.cpp
          LogPair.cpp
          text_utilities.cpp
          World.cpp
          states/CountDownState.cpp
          states/PlayingState.cpp
          states/StateMachine.cpp
          states/TitleScreenState.cpp
	  states/PauseState.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Bird.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Factory.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Game.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Log.hpp
         ${CMAKE_CURRENT_LIST_DIR}/LogPair.hpp
         ${CMAKE_CURRENT_LIST_DIR}/text_utilities.hpp
         ${CMAKE_CURRENT_LIST_DIR}/World.hpp
         ${CMAKE_CURRENT_LIST_DIR}/states/BaseState.hpp
         ${CMAKE_CURRENT_LIST_DIR}/states/CountDownState.hpp
         ${CMAKE_CURRENT_LIST_DIR}/states/PlayingState.hpp
         ${CMAKE_CURRENT_LIST_DIR}/states/StateMachine.hpp
         ${CMAKE_CURRENT_LIST_DIR}/states/TitleScreenState.hpp
         ${CMAKE_CURRENT_LIST_DIR}/states/PauseState.hpp
)

target_include_directories(src PUBLIC . ${SFML_INCLUDE_DIRS} ./states)

target_link_libraries(src ${SFML_LIBRARIES} settings)
