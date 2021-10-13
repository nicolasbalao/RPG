#VERSION
cmake_minimum_required(VERSION 3.18.4)

#NAME
project(RPG)

#INCLUDES
include_directories(includes)

#SOURCES
file(GLOB SOURCES "source/*.cpp")

#EXEXCUTABLE
add_executable(${PROJECT_NAME} ${SOURCES})