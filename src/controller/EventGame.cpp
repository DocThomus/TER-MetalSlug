#include "controller/EventGame.h"
#include <controller/Game.h>


EventGame::EventGame()
:position(0)
{

}


EventGame::EventGame(int pos)
:position(pos)
{

}


EventGame::~EventGame()
{

}


int EventGame::getPosition()
{
	return position;
}

