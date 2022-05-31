cmake_minimum_required (VERSION 3.12)

project(Nimmspiel)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)




add_executable(Nimmspiel
        source/Nimmspiel.cpp
        source/abstract_takegame_player.h
        source/AbstractGame.h
        source/abstrcat_player.h
        source/computer_player.h
        source/consolen_writer.h
        source/consolen_writer.cpp
        source/game.h
        source/game_client.cpp
        source/game_client.h
        source/human_player.h
        source/player.h
        source/takegame_impl.h
        source/consolen_writer.cpp
        )



# Add tests
add_subdirectory(tests)

