#include <iostream>
#include <SFML/Graphics.hpp>
#include "../PlatformerGame/Engine/GameEngine.h"
#include "visual/Menu.h"



int main() {
    int health_coefficient = 1;
    bool selected;
    sf::VideoMode videoMode1;
    videoMode1.height = 1000;
    videoMode1.width = 800;

    sf::RenderWindow menuWindow(videoMode1, "Menu", sf::Style::Titlebar | sf::Style::Close);
    Menu menu(menuWindow.getSize().x, menuWindow.getSize().y, 1);

    while (menuWindow.isOpen()) {
        sf::Event event;

        while (menuWindow.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    selected = true;
                                    menuWindow.close();
                                    break;
                                case 1:
                                    health_coefficient += 1;

                                    break;
                                case 2:
                                    menu.showHistory();
                                    break;

                                case 3:
                                    menu.showHelp();
                                    break;

                                case 4:
                                    menuWindow.close();
                                    break;
                            }

                            break;
                    }

                    break;
                case sf::Event::Closed:
                    menuWindow.close();

                    break;

            }
        }


        menuWindow.clear(sf::Color::Black);
        menu.draw(menuWindow);
        menuWindow.display();
    }
    while(selected) {

        engine::GameEngine engine;
        engine.getHero().setHealthCoefficient(health_coefficient);
        engine.getEnemy().setHealthCoefficient(health_coefficient);


            while (engine.isGameRunning() && !(engine.gameOver())) {
                selected = false;
                engine.setDeltaTime(engine.getClock());

                sf::Event event_new;


                while (engine.getWindow()->pollEvent(event_new)) {

                    engine.getEventController().shutdownGame(engine.getWindow());
                    engine.getEventController().helpOnF1();
                    engine.getEventController().setEvent(event_new);
                    engine.getEventController().ifWindowIsClosedEvent(engine.getWindow());
                    engine.getEventController().setSizeOfWindow(engine.getWindow());
                    engine.getEventController().handleEventHero(engine.getHero(), engine.getEnemy(), engine.getDeltaTime(),
                                                                engine.getCollisionResult());
                    engine.getEventController().handleEventEnemy(engine.getEnemy(), engine.getHero(), engine.getDeltaTime(),
                                                                 engine.getCollisionResult());


                }
                engine.setCollisionResult(engine.getCollision().resolveObjectCollision(engine.getHero(), engine.getEnemy()));
                engine.getWindow()->clear();
                engine.update();
                engine.render();
                engine.getWindow()->display();
            }


        }


       /* sf::VideoMode videoMode2;
        videoMode2.height = 1000;
        videoMode2.width = 800;

        sf::RenderWindow whoWinWindow(videoMode2, "Menu", sf::Style::Titlebar | sf::Style::Close); */


    return 0;
}

