

#ifndef PLATFORMERGAME_EVENTCONTROLLER_H
#define PLATFORMERGAME_EVENTCONTROLLER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "../object/Hero.h"
#include "../object/GameObject.h"
#include "../object/Animation.h"
#include "../object/Enemy.h"
#include "../visual/Menu.h"
class eventController{
public:
    eventController();
    ~eventController();


    //Functions

    void shutdownGame(sf::RenderWindow* window);
    void ifWindowIsClosedEvent(sf::RenderWindow* window);
    void updateMousePosition(sf::RenderWindow* window);
    void setEvent(sf::Event &event_non_member);
    void setSizeOfWindow(sf::RenderWindow* window);
    void handleEventHero(object::Hero& hero, object::Enemy& enemy, float deltaTime, bool collision);
    void handleEventEnemy(object::Enemy &enemy,object::Hero& hero, float deltaTime, bool collision);


private:
    sf::Vector2u sizeOfWindow;

    sf::Event event;
    std::vector<sf::Event>* event_vector;
    sf::Vector2f mousePosView;
    sf::Vector2i mousePosWindow;


};
#endif //PLATFORMERGAME_EVENTCONTROLLER_H
