cmake_minimum_required(VERSION 3.13)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(libft LIBA)
add_executable(Lem_in ${LIBA} main.c lemin.h)
link_libraries(./libft/libft.a)
