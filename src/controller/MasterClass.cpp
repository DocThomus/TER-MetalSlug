#include "controller/MasterClass.h"


MasterClass::MasterClass()
{
}


MasterClass::~MasterClass()
{
	
}


void MasterClass::initGame()
{
	window = new RenderWindow();
    game.setConfig(&config);
    game.applyConfig(window);
}





void MasterClass::playGame()
{
    Clock clock;

	while (window->isOpen())
    {
        window->clear();
        
        game.checkEvents(window);
        game.update(clock.restart());
        game.checkCollisions();
        game.display(window);

        window->display();
    }
}