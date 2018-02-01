#include "../../include/States/stateMainMenu.hpp"

StateMainMenu::StateMainMenu( Game &game )
    :   game( game ),
        playButton( getButtonsTexture() ),
        trophiesButton( getButtonsTexture() ),
        quitButton( getButtonsTexture() )
    {
    nextState = nullptr;
    prepareBackgorund();
    createButtons();
}

StateMainMenu::~StateMainMenu() {
}

void StateMainMenu::handleInput( void ) {
    sf::RenderWindow &window = game.getWindow();

    sf::Event event;
    while ( window.pollEvent( event ) ) {
        switch ( event.type ) {
        case sf::Event::Closed :
            stopState();
            window.close();
            break;

        default :
            break;
        }
    }
}

void StateMainMenu::update( void ) {
    sf::RenderWindow &window = game.getWindow();

    if( playButton.isClicked( window ) ) {
        //std::unique_ptr< GameState > playGameState ( new StatePlayGame( game ) );
        //nextState = std::move( playGameState );
       // stopState();
    }

    if( trophiesButton.isClicked( window ) ) {
    }

    if( quitButton.isClicked( window ) ) {
        game.setExitGame();
        stopState();
    }
}

void StateMainMenu::draw( void ) {
    sf::RenderWindow &window = game.getWindow();
    window.draw( background );

    playButton.draw( window );
    trophiesButton.draw( window );
    quitButton.draw( window );
}

std::unique_ptr< GameState > StateMainMenu::getNextState( void ) {
    return std::move( nextState );
}

void StateMainMenu::stopState( void ) {
    this->running = false;
}

void StateMainMenu::prepareBackgorund( void ) {
    ResourceManager &manager = game.getResManager();
    sf::Texture &texture = manager.getTexture( Texture::MAIN_MENU_BACKGROUND );
    background.setTexture( texture );
}

void StateMainMenu::createButtons( void ) {
    sf::Texture &buttonTexture = getButtonsTexture();

    int buttonWidth  = buttonTexture.getSize().x / BUTTON_TEXTURE_ROWS;
    int buttonHeight = buttonTexture.getSize().y / BUTTON_TEXTURE_CELLS;

    int windowWidth = game.getWindow().getSize().x;
    int windowHeight= game.getWindow().getSize().y;
    int offset = buttonHeight / BUTTON_OFFSET;

    playButton.setPosition( sf::Vector2f( windowWidth / BUTTON_TEXTURE_CELLS - buttonWidth, windowHeight - buttonHeight - offset ) );
    playButton.addSprite( sf::IntRect( 0, 0, buttonWidth, buttonHeight ), ButtonState::NORMAL );
    playButton.addSprite( sf::IntRect( buttonWidth, 0, buttonWidth, buttonHeight ), ButtonState::PRESSED );

    trophiesButton.setPosition( sf::Vector2f( windowWidth / BUTTON_TEXTURE_CELLS, windowHeight - buttonHeight - offset ) );
    trophiesButton.addSprite( sf::IntRect( 0, buttonHeight, buttonWidth, buttonHeight ), ButtonState::NORMAL );
    trophiesButton.addSprite( sf::IntRect( buttonWidth, buttonHeight, buttonWidth, buttonHeight ), ButtonState::PRESSED );

    quitButton.setPosition( sf::Vector2f( windowWidth / BUTTON_TEXTURE_CELLS + buttonWidth, windowHeight - buttonHeight - offset ) );
    quitButton.addSprite( sf::IntRect( 0, 2 * buttonHeight, buttonWidth, buttonHeight ), ButtonState::NORMAL );
    quitButton.addSprite( sf::IntRect( buttonWidth, 2 * buttonHeight, buttonWidth, buttonHeight ), ButtonState::PRESSED );
}

sf::Texture& StateMainMenu::getButtonsTexture( void ) {
    ResourceManager &manager = game.getResManager();
    return manager.getTexture( Texture::MAIN_MENU_BUTTONS );
}
