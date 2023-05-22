cmake_minimum_required(VERSION 3.25)
project(ParallelProgramming C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")

# To execute first project uncomment this next line
add_executable(ParallelProgramming com.fee.omp/OMP_Workshare_1.c)
