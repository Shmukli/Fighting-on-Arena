
#ifndef PLATFORMERGAME_COLLISION_H
#define PLATFORMERGAME_COLLISION_H
#include "../object/Hero.h"
#include "../object/Enemy.h"
class Collision{
public:
    Collision() = default;
    ~Collision() = default;

    bool resolveObjectCollision( object::Hero& object1,
                                 object::Enemy& object2);

private:


  bool collisionDetected;


};
#endif //PLATFORMERGAME_COLLISION_H
