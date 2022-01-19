# cmake_minimum_required(VERSION <specify CMake version here>)
project(seper)

set(CMAKE_CXX_STANDARD 14)

add_executable(seper main.cpp Field.h MSBoard.cpp MSBoard.h MSBTextView.h MSBTextView.cpp MSTextController.h MSTextController.cpp )