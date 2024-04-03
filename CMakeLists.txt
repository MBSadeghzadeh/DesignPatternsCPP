cmake_minimum_required(VERSION 3.14)

project(DesignPatterns LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DesignPatterns
  src/main.cpp

  src/Prototype/Prototype.h
)
