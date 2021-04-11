cmake_minimum_required(VERSION 3.2)

project(Shooter2D_SFML VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS
    ${HEADER_DIR}/Tools/Print.h
    ${HEADER_DIR}/Signal.h
    ${HEADER_DIR}/Singleton.h
    ${HEADER_DIR}/TestSignalSimple.h
    ${HEADER_DIR}/Player.h
    ${HEADER_DIR}/GameObject.h
    ${HEADER_DIR}/GameLevel.h
    ${HEADER_DIR}/GameLoop.h
    ${HEADER_DIR}/TextureManager.h
    ${HEADER_DIR}/Component.h
    ${HEADER_DIR}/CollisionComponent.h
    ${HEADER_DIR}/RenderedGameObject.h
)

set(SOURCES
    ${SOURCE_DIR}/TestSignalSimple.cpp
    ${SOURCE_DIR}/GameLoop.cpp
    ${SOURCE_DIR}/GameObject.cpp
    ${SOURCE_DIR}/GameLevel.cpp
    ${SOURCE_DIR}/Player.cpp
    ${SOURCE_DIR}/TextureManager.cpp
    ${SOURCE_DIR}/Main.cpp
    ${SOURCE_DIR}/CollisionComponent.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${HEADER_DIR}   
)