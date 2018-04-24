cmake_minimum_required(VERSION 3.9)

project(SFMLnake)
set (SFMLnake_VERSION_MAJOR 0)
set (SFMLnake_VERSION_MINOR 5)
set (SFMLnake_VERSION_PATCH 1)


set(CMAKE_CXX_STANDARD 11)

add_executable(SFMLnake
        dependencies/SFML/include/SFML/Audio/AlResource.hpp
        dependencies/SFML/include/SFML/Audio/Export.hpp
        dependencies/SFML/include/SFML/Audio/InputSoundFile.hpp
        dependencies/SFML/include/SFML/Audio/Listener.hpp
        dependencies/SFML/include/SFML/Audio/Music.hpp
        dependencies/SFML/include/SFML/Audio/OutputSoundFile.hpp
        dependencies/SFML/include/SFML/Audio/Sound.hpp
        dependencies/SFML/include/SFML/Audio/SoundBuffer.hpp
        dependencies/SFML/include/SFML/Audio/SoundBufferRecorder.hpp
        dependencies/SFML/include/SFML/Audio/SoundFileFactory.hpp
        dependencies/SFML/include/SFML/Audio/SoundFileReader.hpp
        dependencies/SFML/include/SFML/Audio/SoundFileWriter.hpp
        dependencies/SFML/include/SFML/Audio/SoundRecorder.hpp
        dependencies/SFML/include/SFML/Audio/SoundSource.hpp
        dependencies/SFML/include/SFML/Audio/SoundStream.hpp
        dependencies/SFML/include/SFML/Graphics/BlendMode.hpp
        dependencies/SFML/include/SFML/Graphics/CircleShape.hpp
        dependencies/SFML/include/SFML/Graphics/Color.hpp
        dependencies/SFML/include/SFML/Graphics/ConvexShape.hpp
        dependencies/SFML/include/SFML/Graphics/Drawable.hpp
        dependencies/SFML/include/SFML/Graphics/Export.hpp
        dependencies/SFML/include/SFML/Graphics/Font.hpp
        dependencies/SFML/include/SFML/Graphics/Glsl.hpp
        dependencies/SFML/include/SFML/Graphics/Glyph.hpp
        dependencies/SFML/include/SFML/Graphics/Image.hpp
        dependencies/SFML/include/SFML/Graphics/PrimitiveType.hpp
        dependencies/SFML/include/SFML/Graphics/Rect.hpp
        dependencies/SFML/include/SFML/Graphics/RectangleShape.hpp
        dependencies/SFML/include/SFML/Graphics/RenderStates.hpp
        dependencies/SFML/include/SFML/Graphics/RenderTarget.hpp
        dependencies/SFML/include/SFML/Graphics/RenderTexture.hpp
        dependencies/SFML/include/SFML/Graphics/RenderWindow.hpp
        dependencies/SFML/include/SFML/Graphics/Shader.hpp
        dependencies/SFML/include/SFML/Graphics/Shape.hpp
        dependencies/SFML/include/SFML/Graphics/Sprite.hpp
        dependencies/SFML/include/SFML/Graphics/Text.hpp
        dependencies/SFML/include/SFML/Graphics/Texture.hpp
        dependencies/SFML/include/SFML/Graphics/Transform.hpp
        dependencies/SFML/include/SFML/Graphics/Transformable.hpp
        dependencies/SFML/include/SFML/Graphics/Vertex.hpp
        dependencies/SFML/include/SFML/Graphics/VertexArray.hpp
        dependencies/SFML/include/SFML/Graphics/View.hpp
        dependencies/SFML/include/SFML/Network/Export.hpp
        dependencies/SFML/include/SFML/Network/Ftp.hpp
        dependencies/SFML/include/SFML/Network/Http.hpp
        dependencies/SFML/include/SFML/Network/IpAddress.hpp
        dependencies/SFML/include/SFML/Network/Packet.hpp
        dependencies/SFML/include/SFML/Network/Socket.hpp
        dependencies/SFML/include/SFML/Network/SocketHandle.hpp
        dependencies/SFML/include/SFML/Network/SocketSelector.hpp
        dependencies/SFML/include/SFML/Network/TcpListener.hpp
        dependencies/SFML/include/SFML/Network/TcpSocket.hpp
        dependencies/SFML/include/SFML/Network/UdpSocket.hpp
        dependencies/SFML/include/SFML/System/Clock.hpp
        dependencies/SFML/include/SFML/System/Err.hpp
        dependencies/SFML/include/SFML/System/Export.hpp
        dependencies/SFML/include/SFML/System/FileInputStream.hpp
        dependencies/SFML/include/SFML/System/InputStream.hpp
        dependencies/SFML/include/SFML/System/Lock.hpp
        dependencies/SFML/include/SFML/System/MemoryInputStream.hpp
        dependencies/SFML/include/SFML/System/Mutex.hpp
        dependencies/SFML/include/SFML/System/NativeActivity.hpp
        dependencies/SFML/include/SFML/System/NonCopyable.hpp
        dependencies/SFML/include/SFML/System/Sleep.hpp
        dependencies/SFML/include/SFML/System/String.hpp
        dependencies/SFML/include/SFML/System/Thread.hpp
        dependencies/SFML/include/SFML/System/ThreadLocal.hpp
        dependencies/SFML/include/SFML/System/ThreadLocalPtr.hpp
        dependencies/SFML/include/SFML/System/Time.hpp
        dependencies/SFML/include/SFML/System/Utf.hpp
        dependencies/SFML/include/SFML/System/Vector2.hpp
        dependencies/SFML/include/SFML/System/Vector3.hpp
        dependencies/SFML/include/SFML/Window/Context.hpp
        dependencies/SFML/include/SFML/Window/ContextSettings.hpp
        dependencies/SFML/include/SFML/Window/Event.hpp
        dependencies/SFML/include/SFML/Window/Export.hpp
        dependencies/SFML/include/SFML/Window/GlResource.hpp
        dependencies/SFML/include/SFML/Window/Joystick.hpp
        dependencies/SFML/include/SFML/Window/Keyboard.hpp
        dependencies/SFML/include/SFML/Window/Mouse.hpp
        dependencies/SFML/include/SFML/Window/Sensor.hpp
        dependencies/SFML/include/SFML/Window/Touch.hpp
        dependencies/SFML/include/SFML/Window/VideoMode.hpp
        dependencies/SFML/include/SFML/Window/Window.hpp
        dependencies/SFML/include/SFML/Window/WindowHandle.hpp
        dependencies/SFML/include/SFML/Window/WindowStyle.hpp
        dependencies/SFML/include/SFML/Audio.hpp
        dependencies/SFML/include/SFML/Config.hpp
        dependencies/SFML/include/SFML/Graphics.hpp
        dependencies/SFML/include/SFML/Main.hpp
        dependencies/SFML/include/SFML/Network.hpp
        dependencies/SFML/include/SFML/OpenGL.hpp
        dependencies/SFML/include/SFML/System.hpp
        dependencies/SFML/include/SFML/Window.hpp
        media/sfx/sfml-logo-animation.ogg
        media/textures/gameTextures.png
        media/textures/menuButtons.png
        media/textures/menuTheme.png
        media/textures/score.bmp
        media/textures/SFMLlogo.png
        sources/engine/color.cpp
        sources/engine/color.hpp
        sources/engine/engine.cpp
        sources/engine/engine.hpp
        sources/engine/game.cpp
        sources/engine/game.hpp
        sources/engine/resourceManager.cpp
        sources/engine/resourceManager.hpp
        sources/engine/sound.cpp
        sources/engine/sound.hpp
        sources/engine/texture.cpp
        sources/engine/texture.hpp
        sources/states/game/direction.hpp
        sources/states/game/fruit.cpp
        sources/states/game/fruit.hpp
        sources/states/game/gameSprites.cpp
        sources/states/game/gameSprites.hpp
        sources/states/game/score.cpp
        sources/states/game/score.hpp
        sources/states/game/spriteType.hpp
        sources/states/intro/stateIntroSFML.cpp
        sources/states/intro/stateIntroSFML.hpp
        sources/states/menu/buttonState.hpp
        sources/states/menu/menuButton.cpp
        sources/states/menu/menuButton.hpp
        sources/states/menu/stateMainMenu.cpp
        sources/states/menu/stateMainMenu.hpp
        sources/states/gameState.hpp
        sources/states/game/field.cpp
        sources/states/game/field.hpp
        sources/states/game/snake.cpp
        sources/states/game/snake.hpp
        sources/stateMainGame.cpp
        sources/stateMainGame.hpp
        main.cpp
        README.md Collision.cpp Collision.hpp)

# Detect and add SFML
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/dependencies/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/dependencies/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED audio network graphics window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLnake ${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()