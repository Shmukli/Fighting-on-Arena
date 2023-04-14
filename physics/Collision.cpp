#include "Collision.h"

bool Collision::resolveObjectCollision(object::Hero &object1, object::Enemy &object2) {

  if (object1.getSprite().getGlobalBounds().intersects(object2.getSpriteEnemy().getGlobalBounds())) {
    return collisionDetected = true;
  }

}
