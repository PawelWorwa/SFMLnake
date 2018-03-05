cmake_minimum_required(VERSION 3.9)
project(SFMLnake)

set(CMAKE_CXX_STANDARD 11)

add_executable(SFMLnake
        sources/color.hpp
        sources/font.hpp
        sources/resourceManager.hpp
        sources/sound.hpp
        sources/texture.hpp
        sources/buttonState.hpp
        sources/gameState.hpp
        sources/stateIntroSFML.hpp
        sources/stateMainGame.hpp
        sources/stateMainMenu.hpp
        sources/direction.hpp
        sources/engine.hpp
        sources/field.hpp
        sources/game.hpp
        sources/gameSprites.hpp
        sources/menuButton.hpp
        sources/snake.hpp
        sources/spriteType.hpp
        media/fonts/verdana.ttf
        media/sfx/sfml-logo-animation.ogg
        media/textures/gameTextures.png
        media/textures/menuButtons.png
        media/textures/menuTheme.png
        media/textures/SFMLlogo.png
        sources/color.cpp
        sources/font.cpp
        sources/resourceManager.cpp
        sources/sound.cpp
        sources/texture.cpp
        sources/stateIntroSFML.cpp
        sources/stateMainGame.cpp
        sources/stateMainMenu.cpp
        sources/engine.cpp
        sources/Field.cpp
        sources/game.cpp
        sources/gameSprites.cpp
        sources/menuButton.cpp
        sources/snake.cpp
        LICENSE
        main.cpp
        README.md sources/fruit.cpp sources/fruit.hpp)

# Detect and add SFML
set(SFML_ROOT "C:/00_SFML/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED audio network graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLnake ${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()