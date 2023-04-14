//
// Created by Banana on 09.01.2022.
//

#ifndef PLATFORMERGAME_GAMELEVEL_H
#define PLATFORMERGAME_GAMELEVEL_H
#include "Box2D/Box2D.h"
#include "../object/Hero.h"
namespace level {
class Game_level {
 public:

  //Functions

  //Physics
  void setWorld();
  void setGroundBody();
  void createGroundFixture();

  //Random generating
  void random_object_generating();


  //Objects


 private:

  std::vector<b2Body *> bodies_m;

  b2World world_m;

};
#endif //PLATFORMERGAME_GAMELEVEL_H
