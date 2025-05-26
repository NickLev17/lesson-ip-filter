cmake_minimum_required(VERSION 3.12)


project(filter)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ip_filter.tsv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(ip_filter main.cpp)


set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)



install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

