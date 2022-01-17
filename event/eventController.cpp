#include "eventController.h"



eventController::eventController(){




}

eventController::~eventController(){




}

void eventController::shutdownGame(sf::RenderWindow* window) {

    if(this->event.type == sf::Event::KeyPressed) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            sf::VideoMode videoMode1;
            videoMode1.height = 150;
            videoMode1.width = 250;

            sf::RenderWindow menuExitWindow(videoMode1, "Exit", sf::Style::Titlebar | sf::Style::Close);
            Menu menu(menuExitWindow.getSize().x, menuExitWindow.getSize().y, 2);
            while (menuExitWindow.isOpen()) {
                sf::Event event;

                while (menuExitWindow.pollEvent(event)) {
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
                                            std::cout << "Play button has been pressed" << std::endl;
                                            window->close();
                                            menuExitWindow.close();
                                            break;
                                        case 1:
                                            std::cout << "Difficulty button has been pressed" << std::endl;
                                            menuExitWindow.close();

                                    }

                                    break;
                            }

                            break;
                        case sf::Event::Closed:
                            menuExitWindow.close();

                            break;

                    }
                }


                menuExitWindow.clear(sf::Color::Black);
                menu.draw(menuExitWindow);
                menuExitWindow.display();
            }


            // window->close();
        }
    }

}

void eventController::ifWindowIsClosedEvent(sf::RenderWindow *window){

    if(this->event.type == sf::Event::Closed)
        window->close();

}

void eventController::handleEventHero(object::Hero& hero,object::Enemy& enemy, float deltaTime, bool collision){





 if(this->event.type == sf::Event::KeyPressed)
 {
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
         hero.rightAttack(deltaTime);
         if (collision) {
             if(enemy.getHealth() >= 1) {
                 enemy.setHealth(enemy.getHealth() - 1);
             }
         }
     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
         hero.leftAttack(deltaTime);
     if(collision){
         if(enemy.getHealth() >= 1) {
             enemy.setHealth(enemy.getHealth() - 1);
         }
     }
     }

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
         hero.moveRight(deltaTime);

     }

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
         hero.moveLeft(deltaTime);

     }
 ;}


}

void eventController::setEvent(sf::Event &event_non_member){

    this->event.type = event_non_member.type;

}

void eventController::updateMousePosition(sf::RenderWindow* window){

  this->mousePosWindow = sf::Mouse::getPosition(*window);
  this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);

}

void eventController::handleEventEnemy(object::Enemy &enemy, object::Hero& hero, float deltaTime, bool collision) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        enemy.rightAttackEnemy(deltaTime);
        if (collision) {
            if(hero.getHealth() >= 1) {
                hero.setHealth(hero.getHealth() - 1);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
        enemy.leftAttackEnemy(deltaTime);
        if (collision) {
            if(hero.getHealth() >= 1) {
                hero.setHealth(hero.getHealth() - 1);
            }
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        enemy.moveRightEnemy(deltaTime);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        enemy.moveLeftEnemy(deltaTime);

    }

}

void eventController::setSizeOfWindow(sf::RenderWindow *window) {

    this->sizeOfWindow = window->getSize();

}


