cmake_minimum_required(VERSION 3.20)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3d main.c parser/parser.c parser/parser.h utils/utils.c utils/utils.h get_next_line/get_next_line.c get_next_line/get_next_line.h get_next_line/get_next_line_utils.c list/list.c list/list.h parser/cardinal_direction_setters.c parser/parser_private.h parser/file_reader.c parser/line_checkers.c parser/settings_func.c parser/color_setters.c parser/map_func.c mlx_adapter/mlx_adapter.c mlx_adapter/mlx_adapter.h parser/texture_setters.c loader/game_loader.c loader/game_loader.h loader/game_loader_private.h)

#add_library(cub3d minilibx_opengl/libmlx.a)

#link_libraries(cub3d minilibx_opengl/libmlx.a)

#target_link_libraries(cub3d minilibx_opengl/libmlx.a)

#find_library(cub3d minilibx_opengl/libmlx.a)
