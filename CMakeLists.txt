cmake_minimum_required(VERSION 3.1)

project(Rasterizer CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#add_library(raster462 STATIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/src/dummy.cpp
#)
add_executable(rasterizer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Image.cpp
)
#target_link_libraries(rasterizer
#    raster462
#)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
