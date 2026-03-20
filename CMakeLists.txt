cmake_minimum_required(VERSION 3.22.1)
project(game DESCRIPTION "A simple game" LANGUAGES C)
# 1. Buscar la librería SDL2 en el sistema
find_package(SDL2 REQUIRED)
add_executable(programa map.c mazmorra.c main.c)
# 2. Incluir los directorios de cabecera de SDL2
target_include_directories(programa PRIVATE ${SDL2_INCLUDE_DIRS})
# 3. Enlazar la librería al ejecutable
target_link_libraries(programa PRIVATE ${SDL2_LIBRARIES})
if(NOT PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    file(GENERATE OUTPUT "${PROJECT_BINARY_DIR}/.gitignore" CONTENT "*")
endif()


