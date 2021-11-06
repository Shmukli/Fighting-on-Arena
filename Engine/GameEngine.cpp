
#include "GameEngine.h"

void engine::GameEngine::drawObjects(){



}
void engine::GameEngine::start(){

}

void engine::GameEngine::initWindow(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    while (window.isOpen())
    {
        object::Hero hero;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(hero.getSprite());
        window.display();
    }

}

