

#ifndef PLATFORMERGAME_GAMEOBJECT_H
#define PLATFORMERGAME_GAMEOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"

namespace object {
class GameObject : public PhysicsObject{
public:
    GameObject() = default;

    virtual ~GameObject() {};

    //Functions

    void moveRight();
    void moveLeft();

    sf::Sprite& getSprite();
    void loadSprite(std::string filename);
    //virtual void attack() const = 0;
    //virtual void moveRight() const = 0;
    //virtual void moveLeft() const = 0;



protected:

    //variables
    sf::Sprite sprite;
    sf::Texture texture;



};
}
#endif //PLATFORMERGAME_GAMEOBJECT_H
