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
	level.display(window);
}


void Game::checkEvents(RenderWindow* window)
{
    Event event;
    while (window->pollEvent(event))
    {
        if (event.type == Event::Closed)
            window->close();

        if (event.type == Event::KeyPressed)
        	switch(event.key.code)
            {
                case Keyboard::Escape :
                    window->close();
                    break;

                case Keyboard::F :
                    if(Keyboard::isKeyPressed(Keyboard::LControl))
                    {
                        config->fullscreen = !config->fullscreen;
                        applyConfig(window);
                    }
                    break;

            }
    }
}	


void Game::checkCollisions()
{

}



void Game::applyConfig(RenderWindow* window)
{
    VideoMode mode;
    Uint32 style;

    loadLevel();

    if(config->fullscreen)
    {
        mode = VideoMode::getDesktopMode();
        style = Style::None;
    }
    else
    {
        mode = VideoMode(config->resolution.x,config->resolution.y);
        style = Style::Titlebar;
    }
   

    window->create(mode,"Metal Slug !!!",style);
    window->setFramerateLimit(60);

}


void Game::setConfig(Config* c)
{
    config = c;
}



void Game::setLevel(Level l)
{
	level = l;
}


void Game::setPlayer(Player p)
{
	player = p;
}


void Game::loadLevel()
{
    Texture* t = new Texture();
    t->loadFromFile("res/tex/decor/city.gif");
    t->setRepeated(true);
    textures.push_back(t);

    level.addDecor(textures[textures.size()-1]);
}