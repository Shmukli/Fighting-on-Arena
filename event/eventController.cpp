#include "eventController.h"


eventController::eventController(){



}

void eventController::handleEvent(object::GameObject& game_object){

 if(this->event.type == sf::Event::KeyPressed)
 {
     if(this->event.key.code == sf::Keyboard::D)
         // TODO game_object.moveRight();

         if(this->event.key.code == sf::Keyboard::A)
             //TODO game_object.moveLeft();
 ;}


}

void eventController::setEvent(sf::Event &temp_event){

    this->event = temp_event;

}

void eventController::updateMousePosition(sf::RenderWindow* window){

  this->mousePosWindow = sf::Mouse::getPosition(*window);
  this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);

}


