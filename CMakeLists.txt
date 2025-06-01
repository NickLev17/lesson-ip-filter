cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(filter VERSION ${PROJECT_VESRION})

configure_file(ip_filter.tsv ip_filter.tsv COPYONLY)

option(WITH_BOOST_TEST "Whether to build Boost test" ON)



add_executable(filter main.cpp)


set_target_properties(ip_filter filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(ip_filter PRIVATE
    helloworld
)



if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
    target_compile_options(filter PRIVATE
        /W4
    )
    
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    
endif()

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

include(CPack)



