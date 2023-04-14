#include "PhysicsObject.h"

void object::PhysicsObject::initObject(b2World *world) {

  this->BodyDef.type = b2_dynamicBody;
  this->BodyDef.position.Set(0.0f, 4.0f);
  this->body = world->CreateBody(&this->BodyDef);

  b2PolygonShape *dynamicBox = new b2PolygonShape;
  dynamicBox->SetAsBox(1.0f, 1.0f);

  b2FixtureDef *fixtureDef = new b2FixtureDef;
  fixtureDef->shape = dynamicBox;
  fixtureDef->density = 1.0f;
  fixtureDef->friction = 0.3f;

  this->body->CreateFixture(fixtureDef);

}


