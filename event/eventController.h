

#ifndef PLATFORMERGAME_EVENTCONTROLLER_H
#define PLATFORMERGAME_EVENTCONTROLLER_H
#include <SFML/Graphics.hpp>
#include <vector>
class eventController{
public:
    eventController();
    ~eventController();
private:
    std::vector<sf::Event> event_vector;


};
#endif //PLATFORMERGAME_EVENTCONTROLLER_H
