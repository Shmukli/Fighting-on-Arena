//
// Created by Banana on 08.01.2022.
//

#ifndef PLATFORMERGAME_ANIMATION_H
#define PLATFORMERGAME_ANIMATION_H
#include "SFML/Graphics.hpp"
#include <iostream>
class Animation{
public:
  Animation();
  ~Animation() = default;

  void updateAttack(int row, float dt);
  void update(int row, float dt);
  void setTexture(sf::Texture* texture);
  void setImageCount(sf::Vector2u imageCount);
  void setSwitchTime(float switchTime);

  void initSizeOfUvRect();
  sf::IntRect& getRect();

    sf::IntRect uvRect;



private:


    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    sf::Texture* texture;

    float totalTime;
    float switchTime;


};

#endif //PLATFORMERGAME_ANIMATION_H
