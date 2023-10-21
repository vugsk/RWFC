cmake_minimum_required(VERSION 3.26)
project(ReadWriteFileCpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS)
include_directories(${Boost_INCLUDE_DIRS})

## Nlohmann json
find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(includes)
set(SRC_ROOT 
    src/ParserFile.cpp
    src/ParserIniFile.cpp
    src/ParserJsonFile.cpp
)

## building project
add_library(${PROJECT_NAME} ${SRC_ROOT})
target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_link_libraries(${PROJECT_NAME} ${PD_OR_N_CURSES})
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

## ABI version
set_property(TARGET ${PROJECT_NAME} PROPERTY SOVERSION 1)