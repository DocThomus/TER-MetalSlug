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
                    player.jump(100);
                    break;
            }

        if(!Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Left)) // arreter de marcher
            player.walk(0);

    }
}	


void Game::checkAllCollisions()
{ 
// ---- Vérifie les collisions entre tous les objets ----
// ex : En cas de collision entre le joueur et une plateforme, récupère le bords de la plateforme, et le set chez le joueur.
// Entre le joueur et l'environnement :
    for(list<PlatformView>::iterator it = level.environment.platforms.begin(); it != level.environment.platforms.end(); it++) {
        if(checkCollision(player, (*it))) { // Si collision avec une plateforme...
            int niveauplateforme = (*it).getWalkline();
            int niveauJoueur = player.getPosition().y + player.getPosition().y;
            if (niveauJoueur < niveauplateforme + 10) { // Si le joueur est "au nvieau" de la plateforme,
                player.setPositionY(niveauplateforme - player.getPosition().y); // On place le joueur dessus
                player.wait(); // et on change son état pour wait
            }
        }
    }
}

bool Game::checkCollision(ObjetPhysique o1, ObjetPhysique o2) {
    int o1gauche = o1.getPosition().x;
    int o1droite = o1.getPosition().x + o1.getSize().x;
    int o1haut = o1.getPosition().y;
    int o1bas = o1.getPosition().y + o1.getSize().y;
    int o2gauche = o2.getPosition().x;
    int o2droite = o2.getPosition().x + o2.getSize().x;
    int o2haut = o2.getPosition().y;
    int o2bas = o2.getPosition().y + o2.getSize().y;

    return(((o2gauche < o1gauche) && (o1gauche < o2droite) && (o2haut < o1haut) && (o1haut < o2bas))   // coin haut gauche   de o1 dans o2
        || ((o2gauche < o1droite) && (o1droite < o2droite) && (o2haut < o1haut) && (o1haut < o2bas))   // coin haut droite   de o1 dans o2
        || ((o2gauche < o1gauche) && (o1gauche < o2droite) && (o2haut < o1bas ) && (o1bas  < o2bas))   // coin bas gauche    de o1 dans o2
        || ((o2gauche < o1droite) && (o1droite < o2droite) && (o2haut < o1bas ) && (o1bas  < o2bas))); // coin bas droite    de o1 dans o2
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
    
    level.addPlatform(Int2(-10,650),Int2(10000,1),4,0);


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
