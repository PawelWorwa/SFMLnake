#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "../../include/States/buttonState.hpp"
#include "../../include/States/gameState.hpp"
#include "../../include/States/stateMainGame.hpp"
#include "../../include/game.hpp"
#include "../../include/menuButton.hpp"

class StateMainMenu : public GameState {
    private:
        static const int BUTTON_TEXTURE_ROWS  = 2;
        static const int BUTTON_TEXTURE_CELLS = 3;
        static const int BUTTON_OFFSET = 10; // %

        sf::Sprite background;
        Game &game;

        MenuButton playButton;
        MenuButton trophiesButton;
        MenuButton quitButton;

        void createButtons( void );
        sf::Texture& getButtonsTexture( void );
        void prepareBackgorund( void );

    public:
        explicit StateMainMenu( Game &game );
        virtual ~StateMainMenu();

        std::unique_ptr< GameState > nextState;
        std::unique_ptr< GameState > getNextState( void );
        void draw( void );
        void handleInput( void );
        void update( void );
        void stopState( void );
};

#endif // STATEMAINMENU_H
