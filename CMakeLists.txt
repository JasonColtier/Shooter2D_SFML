cmake_minimum_required(VERSION 3.2)

project(Shouter2D_SFML VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS

)

set(SOURCES
    ${SOURCE_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${HEADER_DIR}   
)