cmake_minimum_required( VERSION 2.6 )
project( PissMeOff )

include_directories( ${CMAKE_SOURCE_DIR} )
include_directories( ${CMAKE_BINARY_DIR} )

configure_file( 
    "${PROJECT_SOURCE_DIR}/Configs.h.in"
    "${PROJECT_BINARY_DIR}/Configs.h" )

add_executable( ${PROJECT_NAME} main.cpp )
