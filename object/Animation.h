//
// Created by Banana on 08.01.2022.
//

#ifndef PLATFORMERGAME_ANIMATION_H
#define PLATFORMERGAME_ANIMATION_H
#include "SFML/Graphics.hpp"
class Animation{
public:
  Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
  ~Animation();

  void update(int row, float dt);

  sf::IntRect uvRect;


private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;


};

#endif //PLATFORMERGAME_ANIMATION_H
