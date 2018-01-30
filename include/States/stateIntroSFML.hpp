#ifndef STATEINTROSFML_H
#define STATEINTROSFML_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "../../include/States/gameState.hpp"
#include "../../include/Managment/Color.hpp"
#include "../../include/Managment/Sound.hpp"
#include "../../include/Managment/Texture.hpp"
#include "../../include/game.hpp"

class StateIntroSFML : public GameState {
    private:
        Game &game;
        sf::Clock animationTime;
        sf::Sound introSound;
        sf::Sprite logoSpr;

        void stopState( void );
        void centerLogoOrigin( void );
        void centerLogoPosition( void );
        void createLogoSprite( void );
        void prepareAnimation( void );
        void prepareLogo( void );
        void prepareSound( void );

    public:
        explicit StateIntroSFML( Game &game );
        virtual ~StateIntroSFML();

        std::unique_ptr< GameState > getNextState( void );
        void draw( void );
        void handleInput( void );
        void update( void );
};

#endif // INTROSFML_H
