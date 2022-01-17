

#ifndef PLATFORMERGAME_GAMEOBJECT_H
#define PLATFORMERGAME_GAMEOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "Animation.h"


namespace object {
class GameObject{
public:
    GameObject();

    virtual ~GameObject() {};

    //Functions





    sf::Sprite& getSprite();
   // void loadSprite(std::string filename);
    //virtual void attack() const = 0;
    //virtual void moveRight() const = 0;
    //virtual void moveLeft() const = 0;



protected:

    //variables
    sf::Sprite sprite;
    sf::Texture* texture;



};
}
#endif //PLATFORMERGAME_GAMEOBJECT_H
