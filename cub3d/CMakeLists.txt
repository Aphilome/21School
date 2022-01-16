cmake_minimum_required(VERSION 3.20)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3d main.c)

#add_library(cub3d minilibx_opengl/libmlx.a)

#link_libraries(cub3d minilibx_opengl/libmlx.a)

#target_link_libraries(cub3d minilibx_opengl/libmlx.a)

#find_library(cub3d minilibx_opengl/libmlx.a)
