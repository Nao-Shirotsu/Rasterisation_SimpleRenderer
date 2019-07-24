cmake_minimum_required(VERSION 3.1)
project(RasterisationTest CXX)
find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin) 

#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs)
add_executable(test_run
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TestVector3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TestMatrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TestPolygon.cpp
)
target_link_libraries(test_run
    PRIVATE
    GTest::GTest
    GTest::Main
    #    raster462
)
