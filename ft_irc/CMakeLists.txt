cmake_minimum_required(VERSION 3.20)
project(ft_irc)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_irc main.cpp Server/Server.cpp Server/Server.h User/User.cpp User/User.h Server/Parser.cpp Utils/Utils.cpp Utils/Utils.h Utils/Replies.h User/CommandHandlers.cpp Channel/Channel.cpp Channel/Channel.h)
