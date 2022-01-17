

#ifndef PLATFORMERGAME_PHYSICSOBJECT_H
#define PLATFORMERGAME_PHYSICSOBJECT_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Animation.h"
namespace object {
    class PhysicsObject{
    public:

        PhysicsObject() = default;

        virtual ~PhysicsObject() {};

        //Functions


       void initObject(b2World* world);



    private:

        //Variables

     b2BodyDef BodyDef;
        b2Body* body;



    };

}
#endif //PLATFORMERGAME_PHYSICSOBJECT_H
