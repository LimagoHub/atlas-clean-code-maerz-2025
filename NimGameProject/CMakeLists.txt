cmake_minimum_required(VERSION 3.30)
project(NimGameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGameProject main.cpp
        game/Game.h
        client/GameClient.h
        game/nimgame/NimGame.h
)
