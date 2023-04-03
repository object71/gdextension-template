cmake_minimum_required(VERSION 3.19)
project(gdextension-template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(cmake/GDExtensionBindings.cmake)
add_subdirectory(gameplay)

add_custom_target(create_link ALL
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${CMAKE_SOURCE_DIR}/gdproject/gameplay/"
    COMMAND "${CMAKE_COMMAND}" -E rm -rRf "${CMAKE_SOURCE_DIR}/gdproject/gameplay/bin/"
    COMMAND "${CMAKE_COMMAND}" -E create_symlink "$<TARGET_FILE_DIR:gameplay>" "${CMAKE_SOURCE_DIR}/gdproject/gameplay/bin/"
    COMMENT "Creating symbolic link to build directory"
)

add_dependencies(create_link gameplay)
