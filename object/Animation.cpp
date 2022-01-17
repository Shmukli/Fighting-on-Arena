#include "Animation.h"

Animation::Animation(){


    this->totalTime = 0.0f;
    this->currentImage.x = 0;



}




void Animation::update(int row, float dt){

    currentImage.y = row;
    totalTime  += dt;

    if(totalTime >= switchTime) {

        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x)
        {

            currentImage.x = 0;

        }

    }

    uvRect.left = currentImage.x * uvRect.width;

    uvRect.top = currentImage.y * uvRect.height;


}

void Animation::setTexture(sf::Texture *texture) {

    this->texture = texture;

}

void Animation::setImageCount(sf::Vector2u imageCount) {

    this->imageCount = imageCount;

}

void Animation::setSwitchTime(float switchTime) {

    this->switchTime = switchTime;

}

void Animation::initSizeOfUvRect() {

    this->uvRect.width = this->texture->getSize().x/float(this->imageCount.x);
    this->uvRect.height= this->texture->getSize().y/float(this->imageCount.y);

}

sf::IntRect &Animation::getRect() {

    return this->uvRect;
}

void Animation::updateAttack(int row, float dt) {

    currentImage.y = row;
    totalTime  += dt;

    if(totalTime >= switchTime) {

        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x)
        {

            currentImage.x = 0;

        }

    }

    uvRect.left = currentImage.x * uvRect.width;

    uvRect.top = currentImage.y * uvRect.height;


}


