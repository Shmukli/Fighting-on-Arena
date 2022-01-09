#include "PhysicsObject.h"

void object::PhysicsObject::initObject(b2World* world){

    this->BodyDef.type = b2_dynamicBody;
    this->BodyDef.position.Set(0.0f, 4.0f);
    this->body = world->CreateBody(&this->BodyDef);



}

