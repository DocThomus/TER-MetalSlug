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
    int t = dt.asMilliseconds();
    
    player.animate(t);
}   


void Game::display(RenderWindow* window)
{
	level.display(window);
    player.display(window);
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

                case Keyboard::Right :
                    player.walk(1);
                    break;


                case Keyboard::Left :
                    player.walk(-1);
                    break;

                case Keyboard::Space :
                    break;
            }

        if(!Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Left)) // arreter de marcher
            player.walk(0);

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


void Game::setPlayer(PlayerView p)
{
	player = p;
}


void Game::loadLevel()
{
    Texture* t;

    /* ENVIRONNEMENT */
    t = new Texture();
    t->loadFromFile("res/tex/decor/city.gif");
    t->setRepeated(true);
    textures.push_back(t);
    level.addDecor(textures[textures.size()-1]);
    
    level.addPlatform(Int2(-10,650),Int2(10000,0),4,0);


    /* PLAYER */
    t = new Texture();
    t->loadFromFile("res/tex/player/player.png");
    textures.push_back(t);

    //player = Player(Int2(100,650),Int2(100,100),4,10,100);
    player.setPosition(Int2(100,530));
    player.setSize(Int2(100,120));
    player.setMass(5);
    player.setTexture(textures[textures.size()-1]);
    player.addAnimations(loadSpriteFromFile("res/xml/player/player.xml"));

}




vector<Animation*> Game::loadSpriteFromFile(string filename)
{
    vector<Int2> anim;
    vector<Int2> pos;
    vector<Int2> siz;

    if(!loadSpriteMap(filename,&anim,&pos,&siz))
    {
        cerr << "Erreur dans le chargement de l'animation : " << filename << endl;
        exit(-1);
    }

    vector<Animation*> ret;

    for(unsigned int i=0; i<anim.size(); ++i)
    {
        Animation* a = new Animation();
        for(int y=anim[i].x; y<anim[i].y; ++y)
        {
            Frame* f = new Frame(pos[y],siz[y]);
            a->addFrame(f);
        }
        ret.push_back(a);
    }

    return ret;
}