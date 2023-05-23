cmake_minimum_required(VERSION 3.25)
project(ParallelProgramming C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")

# To execute OMP_Workshare project uncomment this next line
#add_executable(ParallelProgramming com.fee/OMP_Workshare.c com.fee/OMP_orphan.c)

# To execute OMP_orphan project uncomment this next line
#add_executable(ParallelProgramming com.fee/openmp/OMP_orphan.c)

