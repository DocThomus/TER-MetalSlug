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

    for(list<AmmoView*>::iterator a = ammo.begin(); a != ammo.end(); a++)
        (*a)->animate(t);
}   


void Game::display(RenderWindow* window)
{
	level.display(window);
    player.display(window);
    for(list<AmmoView*>::iterator a = ammo.begin(); a != ammo.end(); a++)
        (*a)->display(window);
}


void Game::checkEvents(RenderWindow* window)
{ 
    Event event;
    while (window->pollEvent(event))
    {
        /* EVENEMENTS CLAVIER TOUCHE APPUYÉE */
        if (event.type == Event::KeyPressed)
        {
        	switch(event.key.code)
            {
                /* QUITTER */
                case Keyboard::Escape :
                    window->close();
                    break;


                /* PLEIN ECRAN */
                case Keyboard::F :
                    if(Keyboard::isKeyPressed(Keyboard::LControl))
                    {
                        config->fullscreen = !config->fullscreen;
                        applyConfig(window);
                    }
                    break;


                /* CHANGEMENT D'ARME */
                case Keyboard::Num1 :
                case Keyboard::Numpad1 :
                    player.setWeapon(0);
                    break;

                case Keyboard::Num2 :
                case Keyboard::Numpad2 :
                    player.setWeapon(1);
                    break;

                case Keyboard::Num3 :
                case Keyboard::Numpad3 :
                    player.setWeapon(2);
                    break;

                case Keyboard::Num4 :
                case Keyboard::Numpad4 :
                    player.setWeapon(3);
                    break;


                /* MARCHER */
                case Keyboard::D :
                    player.walk(1);
                    break;

                case Keyboard::Q :
                    player.walk(-1);
                    break;


                /* TIRER */
                case Keyboard::Right :
                    // if(Keyboard::isKeyPressed(Keyboard::Up))
                    //     player.shoot(&ammo,Int2(1,-1), textures[textures.size()-1]);
                    // else if(Keyboard::isKeyPressed(Keyboard::Down))
                    //     player.shoot(&ammo, Int2(1,1), textures[textures.size()-1]);
                    // else
                        player.shoot(&ammo, Int2(1,0), textures[textures.size()-1]);
                    break;

                case Keyboard::Left :
                    // if(Keyboard::isKeyPressed(Keyboard::Up))
                    //     player.shoot(&ammo,Int2(-1,-1), textures[textures.size()-1]);
                    // else if(Keyboard::isKeyPressed(Keyboard::Down))
                    //     player.shoot(&ammo, Int2(-1,1), textures[textures.size()-1]);
                    // else
                        player.shoot(&ammo, Int2(-1,0), textures[textures.size()-1]);
                    break;

                case Keyboard::Up :
                    // if(Keyboard::isKeyPressed(Keyboard::Left))
                    //     player.shoot(&ammo,Int2(-1,-1), textures[textures.size()-1]);
                    // else if(Keyboard::isKeyPressed(Keyboard::Right))
                    //     player.shoot(&ammo, Int2(1,-1), textures[textures.size()-1]);
                    // else
                        player.shoot(&ammo, Int2(0,-1), textures[textures.size()-1]);
                    break;

                // case Keyboard::Down :
                //     if(Keyboard::isKeyPressed(Keyboard::Left))
                //         player.shoot(&ammo,Int2(-1,1), textures[textures.size()-1]);
                //     else if(Keyboard::isKeyPressed(Keyboard::Right))
                //         player.shoot(&ammo, Int2(1,1), textures[textures.size()-1]);
                //     else
                //         player.shoot(&ammo, Int2(0,1), textures[textures.size()-1]);
                //     break;


                /* RECHARGER */
                case Keyboard::R :
                    player.reload(100);
                    break;


                /* SAUTER */
                case Keyboard::Space :
                    player.jump(250);
                    break;
            }
        }


        /* EVENEMENTS CLAVIER TOUCHE RELÂCHÉE */
        if(event.type == Event::KeyReleased)
            switch(event.key.code)
            {
                case Keyboard::Q :
                    if(Keyboard::isKeyPressed(Keyboard::D))
                        player.walk(1);
                    else
                        player.walk(0);
                    break;

                case Keyboard::D :
                    if(Keyboard::isKeyPressed(Keyboard::Q))
                        player.walk(-1);
                    else
                        player.walk(0);
                    break;
            }

    }
}	


void Game::checkCollisions()
{
    Int2 p_pos = player.getPosition();
    Int2 p_siz = player.getSize();

    list<PlatformView>* pltf = &level.environment.platforms;

    /* PLAYER / SOL */
    bool test = true;
    for(list<PlatformView>::iterator pl=pltf->begin(); test && pl!=pltf->end(); pl++)
    {
        Int2 pos = (*pl).getPosition();

        ObjetPhysique* p_ptr = (ObjetPhysique*)(&player);
        ObjetPhysique* pl_ptr = (ObjetPhysique*)(&*pl);
        
        if(checkCollision(p_ptr,pl_ptr))
        {
            player.land(pos.y);
            test = false;
        }
    }
    if(test) {
        player.jump(0);
    }


    /* PLAYER / ENNEMIS */

        // TODO

}



bool Game::checkCollision(ObjetPhysique* obj1, ObjetPhysique* obj2)
{
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    if(pos1.x > pos2.x + siz2.x
    || pos1.x + siz1.x < pos2.x
    || pos1.y > pos2.y + siz2.y
    || pos1.y + siz1.y < pos2.y)
        return false;
    else
        return true;

}



void Game::applyConfig(RenderWindow* window)
{
    VideoMode mode;
    Uint32 style;

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
    window->setKeyRepeatEnabled(false);
}


void Game::setConfig(Config* c)
{
    config = c;
}

void Game::init()
{
    loadLevel();
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
    level.addPlatform(Int2(200,300),Int2(50,50),4,100);
    level.addPlatform(Int2(500,600),Int2(100,30),4,100);



    /* PLAYER */
    t = new Texture();
    t->loadFromFile("res/tex/player/body.png");
    textures.push_back(t);

    player.setPosition(Int2(100,530));
    player.setSize(Int2(100,120));
    player.setMass(5);
    player.setTexture(textures[textures.size()-1]);
    player.addAnimations(loadSpriteFromFile("res/xml/player/body.xml"));

    t = new Texture();
    t->loadFromFile("res/tex/player/legs.png");
    textures.push_back(t);

    player.legs.setTexture(textures[textures.size()-1]);
    player.legs.addAnimations(loadSpriteFromFile("res/xml/player/legs.xml"));

    player.init();
    

    /* WEAPON */
    new Weapon(&player,PISTOL,100);
    new Weapon(&player,SHOTGUN,100);
    player.setWeapon(0);


    /* AMMO */
    t = new Texture();
    t->loadFromFile("res/tex/ammo/bullet.png");
    textures.push_back(t);

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