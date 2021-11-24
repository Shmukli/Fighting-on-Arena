//
// Created by Banana on 02.11.2021.
//
#include "GameObject.h"



sf::Sprite object::GameObject::getSprite()
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

