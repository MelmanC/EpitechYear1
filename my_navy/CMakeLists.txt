cmake_minimum_required(VERSION 3.27.6)

project(my_navy C)

add_subdirectory(lib/my)
add_compile_options(-W -Wall -Wextra -g3)

add_executable(${PROJECT_NAME}
        src/create_map.c
        src/get.c
        src/navy.c
        src/put_position.c
        src/display_map.c
        src/hit.c
        src/connection.c
        src/game.c
        src/modify_map.c
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} my)