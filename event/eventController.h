

#ifndef PLATFORMERGAME_EVENTCONTROLLER_H
#define PLATFORMERGAME_EVENTCONTROLLER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "../object/GameObject.h"
#include "../object/Animation.h"
class eventController{
public:
    eventController();
    ~eventController();


    //Functions

    void ifWindowIsClosedEvent(sf::RenderWindow* window);
    void updateMousePosition(sf::RenderWindow* window);
    void setEvent(sf::Event& temp_event);
    void handleEvent(object::GameObject& game_object);


private:
    sf::Event event;
    std::vector<sf::Event>* event_vector;
    sf::Vector2f mousePosView;
    sf::Vector2i mousePosWindow;


};
#endif //PLATFORMERGAME_EVENTCONTROLLER_H
