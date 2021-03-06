#include "stateIntroSFML.hpp"

StateIntroSFML::StateIntroSFML ( Game &game ) : game( game ) {
    prepareLogo();
    prepareAnimation();

    game.getSoundManager().playSound( Audio::SFML_INTRO );
}

StateIntroSFML::~StateIntroSFML () = default;

void StateIntroSFML::handleInput () {
    sf::RenderWindow &window = game.getWindow();

    sf::Event event;
    while ( window.pollEvent( event )) {
        switch ( event.type ) {
            case sf::Event::Closed :
                stopState();
                window.close();
                break;

            case sf::Event::KeyPressed :
                stopState();
                break;

            default :
                break;
        }
    }
}

void StateIntroSFML::update () {
    bool isIntroTheme = game.getSoundManager().isPlaying( Audio::SFML_INTRO );
    if ( !isIntroTheme ) {
        stopState();

    } else {
        sf::Uint8 brightness = logoSpr.getColor().a;
        if ( brightness < 255 ) {
            brightness += 3;
        }

        sf::Color color = sf::Color( 255, 255, 255, brightness );
        logoSpr.setColor( color );
    }
}

void StateIntroSFML::draw () {
    sf::RenderWindow &window = game.getWindow();
    window.draw( logoSpr );
}

void StateIntroSFML::prepareLogo () {
    createLogoSprite();
    centerLogoOrigin();
    centerLogoPosition();
    logoSpr.setScale( 0.8f, 0.8f );
    logoSpr.setColor( Color::NONE );
}

void StateIntroSFML::prepareAnimation () {
    animationTime.restart();
}

void StateIntroSFML::createLogoSprite () {
    TextureManager &manager = game.getTextureManager();
    sf::Texture &logoTxr = manager.getTexture( Texture::SFML_LOGO );
    logoSpr.setTexture( logoTxr );

    int width = logoTxr.getSize().x;
    int height = logoTxr.getSize().y;
    logoSpr.setTextureRect( sf::IntRect( 0, 0, width, height ));
}

void StateIntroSFML::centerLogoOrigin () {
    float xCenter = logoSpr.getGlobalBounds().width / 2;
    float yCenter = logoSpr.getGlobalBounds().height / 2;
    logoSpr.setOrigin( xCenter, yCenter );
}

void StateIntroSFML::centerLogoPosition () {
    sf::RenderWindow &window = game.getWindow();
    int windowWidth = window.getSize().x;
    int windowHeight = window.getSize().y;
    logoSpr.setPosition( windowWidth / 2, windowHeight / 2 );
}

std::unique_ptr< GameState > StateIntroSFML::getNextState () {
    std::unique_ptr< GameState > mainMenuState( new StateMainMenu( game ));
    return std::move( mainMenuState );
}

void StateIntroSFML::stopState () {
    game.getSoundManager().stopSound( Audio::SFML_INTRO );
    stateRunning = false;
}