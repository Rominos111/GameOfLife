cmake_minimum_required(VERSION 3.10)
project(GameOfLife C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_C_STANDARD 11)

include_directories(./include)

set(HEADER_FILES
        include/game.h
        include/main.h
        include/map.h
        include/queue.h
        )

set(SOURCE_FILES
        src/game.c
        src/main.c
        src/map.c
        src/queue.c
        )

add_executable(GameOfLife ${HEADER_FILES} ${SOURCE_FILES})
