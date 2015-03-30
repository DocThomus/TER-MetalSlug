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
    game.init();
}





void MasterClass::playGame()
{
    Clock clock;

	while (window->isOpen())
    {
        game.checkKeyboardEvents(window);
        game.update(clock.restart());
        game.checkCollisions();

        window->clear();
        game.display(window);

        window->display();
    }
}