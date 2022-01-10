//
// Created by Banana on 02.11.2021.
//
#include "GameObject.h"



void object::GameObject::moveLeft(){

    this->sprite.setPosition(this->sprite.getPosition().x - 1.0f,
                             this->sprite.getPosition().y);
    std::cout << "DONE LEFT MOVE";

}

void object::GameObject::moveRight(){

    this->sprite.setPosition(this->sprite.getPosition().x + 1.0f,
                             this->sprite.getPosition().y);
    std::cout << "DONE RIGHT MOVE";


}


sf::Sprite& object::GameObject::getSprite()
{

    return this->sprite;

}

void object::GameObject::loadSprite(std::string filename)
{

    if(!texture.loadFromFile(filename))
    {
        std::cout << "Error occured!";
    }
    this->sprite.setTexture(this->texture);

}

