cmake_minimum_required(VERSION 3.13)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(libft LIBA)
add_executable(Lem_in ${LIBA} main.c lemin.h parsing.c links.c aux_fns1.c algorithm.c way.c arrayways.c moveants.c bfs.c aux_fns2.c aux_fns3.c readrooms.c)
link_libraries(./libft/libft.a)
