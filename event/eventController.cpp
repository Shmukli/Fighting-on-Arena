#include "eventController.h"





void eventController::ifWindowIsClosedEvent(sf::RenderWindow *window){

    if(this->event.type == sf::Event::Closed)
        window->close();

}

void eventController::handleEvent(object::GameObject& game_object){

 if(this->event.type == sf::Event::KeyPressed)
 {
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            game_object.moveRight();


     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            game_object.moveLeft();
 ;}


}

void eventController::setEvent(sf::Event &temp_event){

    this->event.type = temp_event.type;

}

void eventController::updateMousePosition(sf::RenderWindow* window){

  this->mousePosWindow = sf::Mouse::getPosition(*window);
  this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);

}


