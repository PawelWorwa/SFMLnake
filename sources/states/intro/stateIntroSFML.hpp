#ifndef STATEINTROSFML_H
#define STATEINTROSFML_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "../gameState.hpp"
#include "../menu/stateMainMenu.hpp"
#include "../../engine/color.hpp"
#include "../../engine/audio.hpp"
#include "../../engine/texture.hpp"
#include "../../engine/game.hpp"

class StateIntroSFML : public GameState {
    private:
        Game &game;
        sf::Clock animationTime;
        sf::Sprite logoSpr;

        void stopState () override;
        void centerLogoOrigin ();
        void centerLogoPosition ();
        void createLogoSprite ();
        void prepareAnimation ();
        void prepareLogo ();

    public:
        explicit StateIntroSFML ( Game &game );
        ~StateIntroSFML () override;

        std::unique_ptr< GameState > getNextState () override;
        void draw () override;
        void handleInput () override;
        void update () override;
};

#endif // INTROSFML_H
