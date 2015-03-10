#include "controller/Game.h"


Game::Game()
{

}


Game::~Game()
{
	enemies.clear();
	ammo.clear();
}


void Game::update(Time dt)
{

}


void Game::display(RenderWindow* window)
{
	
}


void Game::setLevel(Level l)
{
	level = l;
}


void Game::setPlayer(Player p)
{
	player = p;
}