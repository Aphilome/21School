cmake_minimum_required(VERSION 3.20)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3d main.c parser/parser.c parser/parser.h utils/utils.c utils/utils.h get_next_line/get_next_line.c get_next_line/get_next_line.h get_next_line/get_next_line_utils.c list/list.c list/list.h parser/cardinal_direction_setters.c parser/parser_private.h parser/file_reader.c parser/line_checkers.c)

#add_library(cub3d minilibx_opengl/libmlx.a)

#link_libraries(cub3d minilibx_opengl/libmlx.a)

#target_link_libraries(cub3d minilibx_opengl/libmlx.a)

#find_library(cub3d minilibx_opengl/libmlx.a)
