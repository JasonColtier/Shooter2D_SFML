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
    ${HEADER_DIR}/GameObjects/Player.h
    ${HEADER_DIR}/GameObjects/Bullet.h
    ${HEADER_DIR}/GameObjects/GameObject.h
    ${HEADER_DIR}/GameLevel.h
    ${HEADER_DIR}/GameLoop.h
    ${HEADER_DIR}/GameWorld.h
    ${HEADER_DIR}/Managers/TextureManager.h
    ${HEADER_DIR}/Managers/CollisionManager.h
    ${HEADER_DIR}/Managers/InputManager.h
    ${HEADER_DIR}/Components/Component.h
    ${HEADER_DIR}/Components/RenderComponent.h
    ${HEADER_DIR}/Components/ShootComponent.h
    ${HEADER_DIR}/Components/CollisionComponent.h
    ${HEADER_DIR}/Components/MovementComponent.h
    ${HEADER_DIR}/Spawner.h
    ${HEADER_DIR}/Enemy.h
)

set(SOURCES
    ${SOURCE_DIR}/Main.cpp
    ${SOURCE_DIR}/TestSignalSimple.cpp
    ${SOURCE_DIR}/GameLoop.cpp
    ${SOURCE_DIR}/GameLevel.cpp
    ${SOURCE_DIR}/GameObjects/GameObject.cpp
    ${SOURCE_DIR}/GameObjects/Player.cpp
    ${SOURCE_DIR}/GameObjects/Bullet.cpp
    ${SOURCE_DIR}/Managers/TextureManager.cpp
    ${SOURCE_DIR}/Managers/CollisionManager.cpp
    ${SOURCE_DIR}/Managers/InputManager.cpp
    ${SOURCE_DIR}/Components/CollisionComponent.cpp
    ${SOURCE_DIR}/Components/RenderComponent.cpp
    ${SOURCE_DIR}/Components/ShootComponent.cpp
    ${SOURCE_DIR}/Components/MovementComponent.cpp
	${SOURCE_DIR}/Spawner.cpp
	${SOURCE_DIR}/Enemy.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${HEADER_DIR}   
)