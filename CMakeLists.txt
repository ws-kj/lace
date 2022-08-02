# CMakeList.txt : CMake project for lace, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("lace")

# Add source to this project's executable.
add_executable (lace "lace.cpp" "lace.h" "lace_example.cpp")

# TODO: Add tests and install targets if needed.
