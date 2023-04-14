
#include "GameEngine.h"

void engine::GameEngine::initVaribles() {
  this->playersScore.firstPlayerWin = false;
  this->playersScore.secondPlayerWin = false;

  this->gameOverResult = false;
  this->collisionResult = false;
  this->actualHeroHealth = 100;
  this->actualEnemyHealth = 100;
  this->clock = new sf::Clock;
  this->deltaTime = 0.0f;
  spawnHero();
  spawnEnemy();
  loadBackGround("../asset/PNG/background/gladiator_background.jpg");

}

eventController &engine::GameEngine::getEventController() {

  return this->event_controller;

}

void engine::GameEngine::setBackGroundScale() {

  this->background_sprite.setScale(this->scale.x, this->scale.y);

}
void engine::GameEngine::calculateScaleOfWindow() {

  this->sizeOfWindow = this->window->getSize();
  this->scale.x = ((static_cast<float>(sizeOfWindow.x) / 900));
  this->scale.y = ((static_cast<float>(sizeOfWindow.y) / 701));
}

object::Hero &engine::GameEngine::getHero() {

  return this->hero;

}

void engine::GameEngine::render() {

  setGameField();
  renderText(*this->window);
  renderHero();
  renderEnemy();

}

void engine::GameEngine::renderHero() {

  drawHero();

}

void engine::GameEngine::updateHeroHealth() {

  this->actualHeroHealth = this->hero.getHealth();
}

void engine::GameEngine::updateEnemyHealth() {

  this->actualEnemyHealth = this->enemy.getHealth();

}
void engine::GameEngine::update() {
  updateHeroHealth();
  updateEnemyHealth();
  updateText();

}

void engine::GameEngine::loadBackGround(std::string filename) {

  if (!(this->background_texture.loadFromFile(filename)));
  {
    std::cout << "Oops, something went wrong!";
  }
  this->background_sprite.setTexture(this->background_texture);

}

void engine::GameEngine::setGameField() {

  setBackGroundScale();
  this->window->draw(this->background_sprite);

}

engine::GameEngine::GameEngine() {

  initWindow();
  initVaribles();
  initHealthHero();
  initEnemyHealth();

}
sf::RenderWindow *engine::GameEngine::getWindow() {

  return this->window;

}
engine::GameEngine::~GameEngine() {

  delete this->clock;
  delete this->window;

}

const bool engine::GameEngine::isGameRunning() {

  return this->window->isOpen();

}
void engine::GameEngine::drawHero() {

  this->window->draw(this->hero.getSprite());

}
void engine::GameEngine::spawnHero() {

  this->hero.getSprite().setPosition(this->hero.getSprite().getPosition().x * this->scale.x,
                                     this->hero.getSprite().getPosition().y + 600 * this->scale.y);

}

void engine::GameEngine::initWindow() {

  this->videoMode.height = 1080;
  this->videoMode.width = 1920;
  this->window = new sf::RenderWindow(this->videoMode, "PlatformerGame", sf::Style::Titlebar | sf::Style::Close);

  this->window->setFramerateLimit(60);

  calculateScaleOfWindow();

}

sf::Clock *engine::GameEngine::getClock() {
  return this->clock;
}

float engine::GameEngine::getDeltaTime() {
  return this->deltaTime;
}

void engine::GameEngine::setDeltaTime(sf::Clock *clock) {

  this->deltaTime = clock->restart().asSeconds();
}

void engine::GameEngine::spawnEnemy() {

  this->enemy.getSpriteEnemy().setPosition(this->enemy.getSpriteEnemy().getPosition().x + 700 * this->scale.x,
                                           this->enemy.getSpriteEnemy().getPosition().y + 600 * this->scale.y);

}

object::Enemy &engine::GameEngine::getEnemy() {
  return this->enemy;
}

void engine::GameEngine::drawEnemy() {

  this->window->draw(this->enemy.getSpriteEnemy());

}

void engine::GameEngine::renderEnemy() {

  drawEnemy();

}

Collision engine::GameEngine::getCollision() {
  return this->collision;
}

bool engine::GameEngine::getCollisionResult() {

  return this->collisionResult;
}

void engine::GameEngine::setCollisionResult(bool collision_res) {

  this->collisionResult = collision_res;

}

bool engine::GameEngine::gameOver() {
  if (actualEnemyHealth == 0) {

    this->playersScore.secondPlayerWin = false;
    this->playersScore.firstPlayerWin = true;
    loadToFile();
    return playersScore.firstPlayerWin;

  }
  if (actualHeroHealth == 0) {

    this->playersScore.firstPlayerWin = false;
    this->playersScore.secondPlayerWin = true;
    loadToFile();
    return playersScore.secondPlayerWin;

  }
}

void engine::GameEngine::initHealthHero() {

  if (!this->healthHeroFont.loadFromFile("../asset/Cute Letters.ttf")) {

    std::cout << "Oops, couldn't download font for hero health!";

  }
  this->heroHealthString = std::to_string(this->actualHeroHealth);
  this->heroHealth.setFont(this->healthHeroFont);
  this->heroHealth.setFillColor(sf::Color::Red);
  this->heroHealth.setPosition(50, 50);
  this->heroHealth.setString(this->heroHealthString);
  this->heroHealthDecription.setFont(healthHeroFont);
  this->heroHealthDecription.setString("PLAYER 1");
  this->heroHealthDecription.setFillColor(sf::Color::Red);
  this->heroHealthDecription.setPosition(50, 0);

}

void engine::GameEngine::renderText(sf::RenderTarget &target) {
  target.draw(this->enemyHealth);
  target.draw(this->enemyHealthDecription);
  target.draw(this->heroHealth);
  target.draw(this->heroHealthDecription);

}

unsigned int &engine::GameEngine::getHeroHealth() {

  return this->actualHeroHealth;

}

unsigned int &engine::GameEngine::getEnemyHealth() {
  return this->actualEnemyHealth;
}

void engine::GameEngine::updateText() {

  this->enemyHealthString = std::to_string(this->actualEnemyHealth);
  this->enemyHealth.setString(this->enemyHealthString);
  this->heroHealthString = std::to_string(this->actualHeroHealth);
  this->heroHealth.setString(this->heroHealthString);

}

void engine::GameEngine::initEnemyHealth() {
  if (!this->healthEnemyFont.loadFromFile("../asset/Cute Letters.ttf")) {

    std::cout << "Oops, couldn't download font for hero health!";

  }
  this->enemyHealthString = std::to_string(this->actualEnemyHealth);
  this->enemyHealth.setFont(this->healthEnemyFont);
  this->enemyHealth.setFillColor(sf::Color::Red);
  this->enemyHealth.setPosition(1770, 50);
  this->enemyHealth.setString(this->heroHealthString);
  this->enemyHealthDecription.setFont(healthEnemyFont);
  this->enemyHealthDecription.setString("PLAYER 2");
  this->enemyHealthDecription.setFillColor(sf::Color::Red);
  this->enemyHealthDecription.setPosition(1770, 0);

}

void engine::GameEngine::loadToFile() {
  ;
  this->myFile.open("info.txt", std::ios_base::app);
  myFile << "PLAYER 1" << "\t" << this->playersScore.firstPlayerWin << "\t" << "PLAYER 2" << "\t"
         << this->playersScore.secondPlayerWin << "\n";
}

