#include "../../include/States/stateIntroSFML.hpp"

StateIntroSFML::StateIntroSFML( Game &game ) : game( game ) {
    prepareLogo();
    prepareSound();
    prepareAnimation();
}

StateIntroSFML::~StateIntroSFML() {
}

void StateIntroSFML::handleInput( void ) {
    sf::RenderWindow &window = game.getWindow();

    sf::Event event;
    while ( window.pollEvent( event ) ) {
        switch ( event.type ) {
            case sf::Event::Closed :
                stopState();
                window.close();
                break;

            case sf::Event::KeyPressed :
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ) {
                    stopState();
                }
                break;

            default :
                break;
        }
    }
}

void StateIntroSFML::update( void ) {
    ResourceManager& manager = game.getResManager();
    sf::SoundBuffer& buffer = manager.getSoundBuffer( Sound::SFML_INTRO );

    int maxDuration = buffer.getDuration().asMilliseconds();
    int currentAnimationTime = animationTime.getElapsedTime().asMilliseconds();
    if ( currentAnimationTime >= maxDuration ) {
        stopState();

    } else {
        int brightness = logoSpr.getColor().a;
        if ( brightness < 255 ) {
            brightness += 3;
        }

        sf::Color color = sf::Color( 255, 255, 255, brightness );
        logoSpr.setColor( color );
    }
}

void StateIntroSFML::draw( void ) {
    sf::RenderWindow &window = game.getWindow();
    window.draw( logoSpr );
}

void StateIntroSFML::prepareLogo( void ) {
    createLogoSprite();
    centerLogoOrigin();
    centerLogoPosition();
    logoSpr.setScale( 0.8f, 0.8f );
    logoSpr.setColor( Color::NONE );
}

void StateIntroSFML::prepareSound( void ) {
    ResourceManager& manager = game.getResManager();
    sf::SoundBuffer& buffer = manager.getSoundBuffer( Sound::SFML_INTRO );
    introSound.setBuffer( buffer );
}

void StateIntroSFML::prepareAnimation( void ) {
    animationTime.restart();
    introSound.play();
}

void StateIntroSFML::createLogoSprite( void ) {
    ResourceManager& manager = game.getResManager();
    sf::Texture& logoTxr = manager.getTexture( Texture::SFML_LOGO );
    logoSpr.setTexture(logoTxr);

    int width = logoTxr.getSize().x;
    int height = logoTxr.getSize().y;
    logoSpr.setTextureRect( sf::IntRect( 0, 0, width, height ) );
}

void StateIntroSFML::centerLogoOrigin(void) {
    int xCenter = logoSpr.getGlobalBounds().width / 2;
    int yCenter = logoSpr.getGlobalBounds().height / 2;
    logoSpr.setOrigin( xCenter, yCenter );
}

void StateIntroSFML::centerLogoPosition( void ) {
    sf::RenderWindow &window = game.getWindow();
    int windowWidth = window.getSize().x;
    int windowHeight = window.getSize().y;
    logoSpr.setPosition(windowWidth / 2, windowHeight / 2);
}

std::unique_ptr< GameState > StateIntroSFML::getNextState( void ) {
    return nullptr;
}

void StateIntroSFML::stopState( void ) {
    introSound.stop();
    //running = false;
}
