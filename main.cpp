#include <iostream>
#include <SFML/Graphics.hpp>
#include "../PlatformerGame/Engine/GameEngine.h"



int main() {
    engine::GameEngine engine;

    while(engine.isGameRunning()) {
        sf::Event event;



        while (engine.getWindow()->pollEvent(event)) {

            engine.getEventController().setEvent(event);
            engine.getEventController().ifWindowIsClosedEvent(engine.getWindow());
            engine.getEventController().handleEvent(engine.getHero());



            // updatE
            // render

        }
        engine.render();
    }

    /*b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
*/



    return 0;
}

