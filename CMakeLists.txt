# CMakeList.txt : CMake project for lace, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project ("lace")

# Add source to this project's executable.
add_executable (lace "lace_example.cpp" "builder.cpp" "lace.h"  "lexer.cpp" "lexer.h")

# TODO: Add tests and install targets if needed.
