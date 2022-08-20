cmake_minimum_required(VERSION 3.15)
project(5x_Puzzle)

set(CMAKE_CXX_STANDARD 14)

link_libraries(C:/TDM-GCC-32/lib/libbgi.a)

add_link_options(-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32)

add_executable(5x_Puzzle
        main.cpp)
