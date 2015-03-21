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
    bool collision = false;
    for(list<PlatformView>::iterator pl=pltf->begin(); pl!=pltf->end(); pl++) // On check les collisions avec TOUTES les plateformes (on peut etre en collision avec le sol et un mur...)
    {
        Int2 pos = (*pl).getPosition();
        Int2 siz = (*pl).getSize();

        ObjetPhysique* p_ptr = (ObjetPhysique*)(&player);
        ObjetPhysique* pl_ptr = (ObjetPhysique*)(&*pl);
        
        if(checkCollision(p_ptr,pl_ptr))
        {
            collision = true; 
            if(checkCollisionHaut(p_ptr,pl_ptr)) {
                player.land(pos.y);
            } else if (checkCollisionBas(p_ptr,pl_ptr)) {
                player.touchePlafond(pos.y + siz.y);
            } else if (checkCollisionGauche(p_ptr,pl_ptr)) {
                //player.land(pos.y); //TMP TODO
                player.prendMurDroite(pos.x);
            } else if (checkCollisionDroite(p_ptr,pl_ptr)) {
                //player.land(pos.y); //TMP TODO
                player.prendMurGauche(pos.x + siz.x);
            }            
        }
    }
    if(!collision) { // Si il n'y a collision avec aucune plateforme, le personnage est en l'air.
        player.jump(0);
    }


    /* PLAYER / ENNEMIS */
        // TODO

    /* ENNEMIS / SOL */
        // TODO

}



bool Game::checkCollision(ObjetPhysique* obj1, ObjetPhysique* obj2) // Renvoie True si il y a une collision (peu importe de quel côté)
{
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    if(pos1.x > pos2.x + siz2.x  // p1(gauche) a droite de   p2(droite)
    || pos1.x + siz1.x < pos2.x  // p1(droite) a gauche de   p2(gauche)
    || pos1.y > pos2.y + siz2.y  // p1(haut)   au dessous de p2(bas)
    || pos1.y + siz1.y < pos2.y) // p1(bas)    au dessus de  p2(haut) 
        return false;
    else
        return true;

}

bool Game::checkCollisionHaut(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche le haut d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    //Si o1 est dans la partie haute de o2, et que la largeur de l'intersection entre o1 et o2 est suppérieure a sa hauteur, alors on a une collision entre o1 et o2 venant du haut

    int hauteurIntersect = pos1.y + siz1.y - pos2.y; // la hauteur de la superposition entre le bas de o1 et le haut de o2 (on part du principe que o1 est dans la partie haute de o2)
    int largeurIntersect = std::min(pos1.x + siz1.x, pos2.x + siz2.x) - std::max(pos1.x, pos2.x); // La largeur de la superposition est égale a la taille de la superposition entre la plus grande des valeurs gauche, et la plus petite des valeurs droites.
    if (((hauteurIntersect > 0) && (pos2.y > pos1.y)) // Si o1 est dans la partie haute de o2 (si le bas de o1 est en dessous du haut de o2, et que le haut de o1 est au dessus du haut de o2)
        && (largeurIntersect > hauteurIntersect)) {
        return true;
    } else {
        return false;
    }
}

bool Game::checkCollisionBas(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche le bas d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    //Si o1 est dans la partie basse de o2, et que la largeur de l'intersection entre o1 et o2 est suppérieure a sa hauteur, alors on a une collision entre o1 et o2 venant du bas

    int hauteurIntersect = pos2.y + siz2.y - pos1.y; // la hauteur de la superposition entre le bas de o2 et le haut de o1 (on part du principe que o1 est dans la partie basse de o2)
    int largeurIntersect = std::min(pos1.x + siz1.x, pos2.x + siz2.x) - std::max(pos1.x, pos2.x); // La largeur de la superposition est égale a la distance entre la plus grande des valeurs gauche, et la plus petite des valeurs droites.
    if (((hauteurIntersect > 0) && (pos1.y + siz1.y > pos2.y + siz2.y)) // Si o1 est dans la partie basse de o2 (si le haut de o1 est au dessus du bas de o2, et que le bas de o1 est en dessous du bas de o2)
        && (largeurIntersect > hauteurIntersect)) {
        return true;
    } else {
        return false;
    }
}

bool Game::checkCollisionGauche(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche la gauche d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    //Si o1 est dans la partie gauche de o2, et que la hauteur de l'intersection entre o1 et o2 est suppérieure a sa largeur, alors on a une collision entre o1 et o2 venant de gauche

    int largeurIntersect = pos1.x + siz1.x - pos2.x; // la largeur de la superposition entre la gauche de o2 et la droite de o1 (on part du principe que o1 est dans la partie gauche de o2)
    int hauteurIntersect = std::min(pos1.y + siz1.y, pos2.y + siz2.y) - std::max(pos1.y, pos2.y); // La hauteur de la superposition est égale a la distance entre la plus grande des valeurs haute, et la plus petite des valeurs basses.
    if (((largeurIntersect > 0) && (pos2.x > pos1.x)) // Si o1 est dans la partie gauche de o2 (si la droite de o1 est a droite de la gauche de o2, et que la gauche de o1 est a gauche de la gauche de o2)
        && (hauteurIntersect > largeurIntersect)) {
        return true;
    } else {
        return false;
    }
}

bool Game::checkCollisionDroite(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche la droite d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    //Si o1 est dans la partie droite de o2, et que la hauteur de l'intersection entre o1 et o2 est suppérieure a sa largeur, alors on a une collision entre o1 et o2 venant de droite

    int largeurIntersect = pos2.x + siz2.x - pos1.x; // la largeur de la superposition entre la gauche de o1 et la droite de o2 (on part du principe que o1 est dans la partie droite de o2)
    int hauteurIntersect = std::min(pos1.y + siz1.y, pos2.y + siz2.y) - std::max(pos1.y, pos2.y); // La hauteur de la superposition est égale a la distance entre la plus grande des valeurs haute, et la plus petite des valeurs basses.
    if (((largeurIntersect > 0) && (pos1.x + siz1.x > pos2.x + siz2.x)) // Si o1 est dans la partie droite de o2 (si la gauche de o1 est a gauche de la droite de o2, et que la droite de o1 est a droite de la droite de o2)
        && (hauteurIntersect > largeurIntersect)) {
        return true;
    } else {
        return false;
    }
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
    
    level.addPlatform(Int2(-10,650),Int2(10000,0),4,0); // Sol
    level.addPlatform(Int2(200,300),Int2(50,50),4,100); // Haut1
    level.addPlatform(Int2(320,370),Int2(30,30),4,100); // Haut2
    level.addPlatform(Int2(500,600),Int2(100,70),4,100); // Bas



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