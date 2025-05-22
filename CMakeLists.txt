cmake_minimum_required(VERSION 3.12)


project(filter)


add_executable(ip_filter main.cpp)


set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)