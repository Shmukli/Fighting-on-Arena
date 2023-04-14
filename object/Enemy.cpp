#include "Enemy.h"

object::Enemy::Enemy() {

  textureEnemy = new sf::Texture;

  this->healthEnemy = 100;

  loadSprite("../asset/sprite_sheet2.png");

  initAnimationEnemy();

}

object::Enemy::~Enemy() {

  delete this->textureEnemy;
}

void object::Enemy::initAnimationEnemy() {

  this->animationEnemy.setTexture(this->textureEnemy);
  this->animationEnemy.setImageCount(sf::Vector2u(6, 4));
  this->animationEnemy.setSwitchTime(0.08f);
  this->animationEnemy.initSizeOfUvRect();
  this->spriteEnemy.setTextureRect(animationEnemy.getRect());

}

void object::Enemy::moveLeftEnemy(float deltaTime) {

  this->spriteEnemy.setPosition(this->spriteEnemy.getPosition().x - 4.0f,
                                this->spriteEnemy.getPosition().y);
  this->animationEnemy.update(1, deltaTime);
  this->spriteEnemy.setTextureRect(animationEnemy.getRect());

}

void object::Enemy::moveRightEnemy(float deltaTime) {

  this->spriteEnemy.setPosition(this->spriteEnemy.getPosition().x + 4.0f,
                                this->spriteEnemy.getPosition().y);

  this->animationEnemy.update(0, deltaTime);
  this->spriteEnemy.setTextureRect(animationEnemy.getRect());

}

void object::Enemy::loadSprite(std::string filename) {

  if (!textureEnemy->loadFromFile(filename)) {
    std::cout << "Error occured!";
  }
  this->spriteEnemy.setTexture(*this->textureEnemy);

}

sf::Sprite &object::Enemy::getSpriteEnemy() {

  return this->spriteEnemy;

}

void object::Enemy::leftAttackEnemy(float deltaTime) {

  this->animationEnemy.update(3, deltaTime);
  this->spriteEnemy.setTextureRect(animationEnemy.getRect());

}
void object::Enemy::rightAttackEnemy(float deltaTime) {

  this->animationEnemy.update(2, deltaTime);

  this->spriteEnemy.setTextureRect(animationEnemy.getRect());

}

unsigned int &object::Enemy::getHealth() {

  return this->healthEnemy;
}

void object::Enemy::setHealth(unsigned int Health) {

  this->healthEnemy = Health;

}

void object::Enemy::setHealthCoefficient(int health_coefficient) {

  this->healthEnemy = healthEnemy * health_coefficient;

}
