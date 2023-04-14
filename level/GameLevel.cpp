#include "GameLevel.h"

void level::Game_level::setWorld() {

  //Set gravity
  b2Vec2 gravity(0.0f, -10.0f);

  //Create the world
  b2World world(gravity);
  this->world_m = world;

}

void level::Game_level::setGroundBody() {

  b2BodyDef groundBodyDef;

  b2Body *groundBody = this->world_m.CreateBody(&groundBodyDef);
  this->bodies_m.emplace_back(groundBody);

}

void level::Game_level::createGroundFixture() {

  b2PolygonShape groundBox;
  groundBox.SetAsBox(50.0f, 10.0f);
  this->bodies_m.front()->CreateFixture(&groundBox, 0.0f);

}
}
