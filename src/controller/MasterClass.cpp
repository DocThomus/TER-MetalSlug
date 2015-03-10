#include "controller/MasterClass.h"


MasterClass::MasterClass()
{
}


MasterClass::~MasterClass()
{
	
}


void MasterClass::initGame()
{
	window = new RenderWindow(sf::VideoMode(400, 400), "SFML works!");
	window->setFramerateLimit(60);
}





void MasterClass::playGame()
{
	Clock clock;

	while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
        }

        game.update(clock.restart());
        game.display(window);

        window->clear();
        window->display();
    }
}