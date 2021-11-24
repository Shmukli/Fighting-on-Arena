

#ifndef PLATFORMERGAME_EVENTCONTROLLER_H
#define PLATFORMERGAME_EVENTCONTROLLER_H
#include <SFML/Graphics.hpp>
#include <vector>
class eventController{
public:
    eventController();
    ~eventController();


    //Functions

    void updateMousePosition(sf::RenderWindow* window);

private:
    sf::Event event;
    std::vector<sf::Event> event_vector;
    sf::Vector2f mousePosView;
    sf::Vector2i mousePosWindow;


};
#endif //PLATFORMERGAME_EVENTCONTROLLER_H
