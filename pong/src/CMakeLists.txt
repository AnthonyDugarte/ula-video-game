add_library(src "")

target_sources(src
PRIVATE
    ball.c
    fonts.c
    hitbox.c
    paddle.c
    pong.c
    sounds.c
    paddle_ia.c
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/ball.h
    ${CMAKE_CURRENT_LIST_DIR}/fonts.h
    ${CMAKE_CURRENT_LIST_DIR}/hitbox.h
    ${CMAKE_CURRENT_LIST_DIR}/paddle.h
    ${CMAKE_CURRENT_LIST_DIR}/pong.h
    ${CMAKE_CURRENT_LIST_DIR}/sounds.h
    ${CMAKE_CURRENT_LIST_DIR}/paddle_ia.h
)

target_include_directories(src
	PUBLIC . ${ALLEGRO5_INCLUDE_DIRS})

target_link_libraries(src ${ALLEGRO5_LIBRARIES} settings)
