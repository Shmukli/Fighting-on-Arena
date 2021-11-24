#include "eventController.h"


eventController::eventController(){



}

void eventController::updateMousePosition(sf::RenderWindow* window){

  this->mousePosWindow = sf::Mouse::getPosition(*window);
  this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);

}


