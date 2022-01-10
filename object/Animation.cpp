#include "Animation.h"

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime){

    this->imageCount = imageCount;
    this->switchTime = switchTime;
    this->totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);


}

void Animation::update(int row, float dt){

    currentImage.y = row;
    totalTime  += dt;

    if(totalTime >= switchTime) {

        totalTime -= switchTime;

        if (currentImage.x >= imageCount.x)
        {

            currentImage.x = 0;

        }

    }

    uvRect.left = currentImage.x * uvRect.width;

    uvRect.top = currentImage.y * uvRect.height;


}