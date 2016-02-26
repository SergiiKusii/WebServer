cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -L/usr/lib -I/usr/include -I/usr/include/freetype2 -lpthread -lboost_system -lboost_filesystem -lboost_thread")

project(WebServerPrj)

set(SOURCE_EXE ./WebServer/WebServer.cpp)

set(connection_lib ./WebServer/connection.cpp)
set(connection_manager_lib ./WebServer/connection_manager.cpp)
set(mime_types_lib ./WebServer/mime_types.cpp)
set(reply_lib ./WebServer/reply.cpp)
set(request_handler_lib ./WebServer/request_handler.cpp)
set(request_parser_lib ./WebServer/request_parser.cpp)
set(server_lib ./WebServer/server.cpp)
set(wsTrace_lib ./WebServer/wsTrace.cpp)

add_library(connection STATIC ${connection_lib})
add_library(connection_manager STATIC ${connection_manager_lib})
add_library(mime_types STATIC ${mime_types_lib})
add_library(reply STATIC ${reply_lib})
add_library(request_handler STATIC ${request_handler_lib})
add_library(request_parser STATIC ${request_parser_lib})
add_library(server STATIC ${server_lib})
add_library(wsTrace STATIC ${wsTrace_lib})

add_executable(WebServerRun ${SOURCE_EXE})

target_link_libraries(WebServerRun connection connection_manager mime_types reply request_handler request_parser server wsTrace) 
