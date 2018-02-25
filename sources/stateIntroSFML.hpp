#ifndef STATEINTROSFML_H
#define STATEINTROSFML_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "gameState.hpp"
#include "stateMainMenu.hpp"
#include "color.hpp"
#include "sound.hpp"
#include "texture.hpp"
#include "game.hpp"

class StateIntroSFML : public GameState {
    private:
        Game& game;
        sf::Clock animationTime;
        sf::Sound introSound;
        sf::Sprite logoSpr;

        void stopState() override;
        void centerLogoOrigin();
        void centerLogoPosition();
        void createLogoSprite();
        void prepareAnimation();
        void prepareLogo();
        void prepareSound();

    public:
        explicit StateIntroSFML( Game& game );
        ~StateIntroSFML() override;

        std::unique_ptr< GameState > getNextState() override;
        void draw() override;
        void handleInput() override;
        void update() override;
};

#endif // INTROSFML_H
