#include "controller/Game.h"


Game::Game()
{

}


Game::~Game()
{
    for(list<AmmoView*>::iterator a = ammo.begin(); a != ammo.end(); a++)
        delete(*a);
    ammo.clear();

    for(list<EnemyView*>::iterator e = enemies.begin(); e != enemies.end(); e++)
        delete(*e);
    enemies.clear();

    for(unsigned int i=0; i<textures.size(); ++i)
        delete textures[i];
    textures.clear();
}


void Game::update(Time dt)
{
    int t = dt.asMilliseconds(); // temps écoulé

    deleteDeadObjects(); // suppression des objets hors de l'écran ou "morts"
    
    player.animate(t); // animation du player

    updateView(t); // mise a jour de la vue

    for(list<DecorView>::iterator d = level.environment.decors.begin(); d != level.environment.decors.end(); d++)
    {
        (*d).animate(int(view.getCenter().x-view.getSize().x/2)); // déplacement des décors
    }

    for(list<EnemyView*>::iterator e = enemies.begin(); e != enemies.end(); e++)
    {
        (*e)->animate(t); // animation des ennemis
    }

    for(list<AmmoView*>::iterator a = ammo.begin(); a != ammo.end(); a++)
    {
        (*a)->animate(t); // animation des amos
    }
}   


void Game::updateView(int dt)
{
    Int2 pos   = view_target->getPosition();
    Int2 siz   = view_target->getSize();
    Float2 mov = view_target->getMovement();

    Vector2f v_center = view.getCenter(); 
    Vector2f v_size   = view.getSize(); 


    // if(pos.x+siz.x>v_center.x-100)
    //     view.move(float(pos.x+siz.x-(v_center.x-100)),0);
    // else if(pos.x+siz.x>v_center.x-v_size.x/4)
    //     //view.move(float(pos.x+siz.x-(v_center.x-v_size.x/4)-dt/3),0);
    //     view.move(dt/10,0);

    if(pos.x+siz.x>v_center.x-v_size.x/5)
        view.move(float(pos.x+siz.x-(v_center.x-v_size.x/5)-dt/3),0);

}




void Game::display(RenderWindow* window)
{
    window->setView(view);

	level.display(window);

    for(list<EnemyView*>::iterator e = enemies.begin(); e != enemies.end(); e++)
        (*e)->display(window);

    player.display(window);
    // cout << player << endl;
    
    for(list<AmmoView*>::iterator a = ammo.begin(); a != ammo.end(); a++)
        (*a)->display(window);
}




void Game::checkEvents(RenderWindow* window)
{ 

    if(Keyboard::isKeyPressed(Keyboard::S))
        player.kneel(true);


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
                    player.shoot(&ammo, Int2(1,0)/*, textures[textures.size()-1]*/);
                    break;

                case Keyboard::Left :
                    player.shoot(&ammo, Int2(-1,0)/*, textures[textures.size()-1]*/);
                    break;

                case Keyboard::Up :
                    player.shoot(&ammo, Int2(0,-1)/*, textures[textures.size()-1]*/);
                    break;


                /* RECHARGER */
                case Keyboard::R :
                    player.reload(100);
                    break;


                /* SAUTER */
                case Keyboard::Space :
                    player.jump(250);
                    break;


                /* TEST */
                case Keyboard::P :
                    enemies.front()->die();
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

                case Keyboard::S :
                    player.kneel(false);
                    break;
            }
    }

}


void Game::checkCollisions()
{
    Int2 p_pos = player.getPosition();
    Int2 p_siz = player.getSize();

    /* PLAYER / BORD DE L'ECRAN */
    if(p_pos.x <= view.getCenter().x-view.getSize().x/2)
        player.bumpLeft(view.getCenter().x-view.getSize().x/2);


    /* PLAYER / PLATFORM */
    list<PlatformView>* pltf = &(level.environment.platforms);
    bool collision = false;
    for(list<PlatformView>::iterator pl=pltf->begin(); pl!=pltf->end(); pl++) // On check les collisions avec TOUTES les plateformes (on peut etre en collision avec le sol et un mur...)
    {
        Int2 pos = (*pl).getPosition();
        Int2 siz = (*pl).getSize();

        ObjetPhysique* p_ptr = (ObjetPhysique*)(&player);
        ObjetPhysique* pl_ptr = (ObjetPhysique*)(&*pl);

        if(checkIntersect(p_ptr,pl_ptr))
        {
            collision = true; 
            if(checkCollisionTop(p_ptr,pl_ptr))
                player.land(pos.y);
            else if (checkCollisionBottom(p_ptr,pl_ptr))
                player.bumpTop(pos.y + siz.y);
            else if (checkCollisionLeft(p_ptr,pl_ptr))
                player.bumpRight(pos.x + 20);
            else if (checkCollisionRight(p_ptr,pl_ptr))
                player.bumpLeft(pos.x + siz.x - 20);
                       
        }
    }
    if(!collision) { // Si il n'y a collision avec aucune plateforme, le personnage est en l'air et tombe
        player.jump(0);
    }



    /* AMMO */
    for(list<AmmoView*>::iterator a = ammo.begin(); a != ammo.end(); a++)
    {
        Int2 a_pos = (*a)->getPosition();
        Int2 a_siz = (*a)->getSize();
        Float2 a_mov = (*a)->getMovement();

        /* VS PLATFORM */
        for(list<PlatformView>::iterator p = pltf->begin(); p != pltf->end(); p++)
        {
            if(checkIntersect((ObjetPhysique*)(*a),(ObjetPhysique*)(&*p)))
            {
                if((*a)->getState() != Ammo::GHOST)
                {
                    Int2 p_pos = (*p).getPosition();
                    Int2 p_siz = (*p).getSize();
                    
                    Int2 tmp = a_pos;
                    
                    if(a_pos.x <= p_pos.x+10)
                        tmp.x = p_pos.x;
                    else if(a_pos.x+a_siz.x >= p_pos.x+p_siz.x+10)
                        tmp.x = p_pos.x+p_siz.x;
                    else if(a_pos.y <= p_pos.y+10)
                        tmp.y = p_pos.y;
                    else
                        tmp.y = p_pos.y+p_siz.y;

                    (*a)->die(tmp);
                }
            }
        }

        /* VS ENEMY */
        for(list<EnemyView*>::iterator e = enemies.begin(); e != enemies.end(); e++)
        {
            if(checkIntersect((ObjetPhysique*)(*a),(ObjetPhysique*)(*e)))
            {
                if((*a)->getState() != Ammo::GHOST && (*e)->getStateBattle() != Character::DEAD)
                {
                    (*e)->decreaseHealth((*a)->getDamage());

                    Int2 e_pos = (*e)->getPosition();
                    Int2 e_siz = (*e)->getSize();
                    
                    Int2 tmp = Int2(e_pos.x+e_siz.x/2,e_pos.y+e_siz.y/2);

                    (*a)->die(tmp);
                }
            }
        }
    }

    

    /* ENNEMIS / SOL */
        // TODO

}



bool Game::checkIntersect(ObjetPhysique* obj1, ObjetPhysique* obj2) // Renvoie True si il y a une collision (peu importe de quel côté)
{
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    if(pos1.x + 20 > pos2.x + siz2.x  // p1(gauche) a droite de   p2(droite)
    || pos1.x + siz1.x - 20 < pos2.x  // p1(droite) a gauche de   p2(gauche)
    || pos1.y > pos2.y + siz2.y  // p1(haut)   au dessous de p2(bas)
    || pos1.y + siz1.y < pos2.y) // p1(bas)    au dessus de  p2(haut) 
        return false;
    else
        return true;

}


bool Game::checkCollisionTop(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche le haut d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();
    Float2 mov1 = obj1->getMovement();

    //Si o1 est dans la partie haute de o2, et que la largeur de l'intersection entre o1 et o2 est suppérieure a sa hauteur, alors on a une collision entre o1 et o2 venant du haut

    int hauteurIntersect = pos1.y + siz1.y - pos2.y; // la hauteur de la superposition entre le bas de o1 et le haut de o2 (on part du principe que o1 est dans la partie haute de o2)
    int largeurIntersect = min(pos1.x + siz1.x, pos2.x + siz2.x) - max(pos1.x, pos2.x); // La largeur de la superposition est égale a la taille de la superposition entre la plus grande des valeurs gauche, et la plus petite des valeurs droites.
    if (((hauteurIntersect > 0) && (pos2.y > pos1.y)) // Si o1 est dans la partie haute de o2 (si le bas de o1 est en dessous du haut de o2, et que le haut de o1 est au dessus du haut de o2)
        && (largeurIntersect > hauteurIntersect) 
        && mov1.y>=0) {
        return true;
    } else {
        return false;
    }
}


bool Game::checkCollisionBottom(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche le bas d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    //Si o1 est dans la partie basse de o2, et que la largeur de l'intersection entre o1 et o2 est suppérieure a sa hauteur, alors on a une collision entre o1 et o2 venant du bas

    int hauteurIntersect = pos2.y + siz2.y - pos1.y; // la hauteur de la superposition entre le bas de o2 et le haut de o1 (on part du principe que o1 est dans la partie basse de o2)
    int largeurIntersect = std::min(pos1.x + siz1.x, pos2.x + siz2.x) - max(pos1.x, pos2.x); // La largeur de la superposition est égale a la distance entre la plus grande des valeurs gauche, et la plus petite des valeurs droites.
    if (((hauteurIntersect > 0) && (pos1.y + siz1.y > pos2.y + siz2.y)) // Si o1 est dans la partie basse de o2 (si le haut de o1 est au dessus du bas de o2, et que le bas de o1 est en dessous du bas de o2)
        && (largeurIntersect > hauteurIntersect)) {
        return true;
    } else {
        return false;
    }
}


bool Game::checkCollisionLeft(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche la gauche d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    //Si o1 est dans la partie gauche de o2, et que la hauteur de l'intersection entre o1 et o2 est suppérieure a sa largeur, alors on a une collision entre o1 et o2 venant de gauche

    int largeurIntersect = pos1.x + siz1.x - pos2.x; // la largeur de la superposition entre la gauche de o2 et la droite de o1 (on part du principe que o1 est dans la partie gauche de o2)
    int hauteurIntersect = std::min(pos1.y + siz1.y, pos2.y + siz2.y) - max(pos1.y, pos2.y); // La hauteur de la superposition est égale a la distance entre la plus grande des valeurs haute, et la plus petite des valeurs basses.
    if (((largeurIntersect > 0) && (pos2.x > pos1.x)) // Si o1 est dans la partie gauche de o2 (si la droite de o1 est a droite de la gauche de o2, et que la gauche de o1 est a gauche de la gauche de o2)
        && (hauteurIntersect > largeurIntersect)) {
        return true;
    } else {
        return false;
    }
}


bool Game::checkCollisionRight(ObjetPhysique* obj1, ObjetPhysique* obj2) {
    // ex: o1 touche la droite d'une plate-forme o2.
    Int2 pos1 = obj1->getPosition();
    Int2 pos2 = obj2->getPosition();
    Int2 siz1 = obj1->getSize();
    Int2 siz2 = obj2->getSize();

    //Si o1 est dans la partie droite de o2, et que la hauteur de l'intersection entre o1 et o2 est suppérieure a sa largeur, alors on a une collision entre o1 et o2 venant de droite

    int largeurIntersect = pos2.x + siz2.x - pos1.x; // la largeur de la superposition entre la gauche de o1 et la droite de o2 (on part du principe que o1 est dans la partie droite de o2)
    int hauteurIntersect = std::min(pos1.y + siz1.y, pos2.y + siz2.y) - max(pos1.y, pos2.y); // La hauteur de la superposition est égale a la distance entre la plus grande des valeurs haute, et la plus petite des valeurs basses.
    if (((largeurIntersect > 0) && (pos1.x + siz1.x > pos2.x + siz2.x)) // Si o1 est dans la partie droite de o2 (si la gauche de o1 est a gauche de la droite de o2, et que la droite de o1 est a droite de la droite de o2)
        && (hauteurIntersect > largeurIntersect)) {
        return true;
    } else {
        return false;
    }
}


void Game::deleteDeadObjects()
{
    Vector2f v_cen = view.getCenter();
    Vector2f v_siz = view.getSize();

    for(list<EnemyView*>::iterator e = enemies.begin(); e != enemies.end(); e++)
    {
        Int2 e_pos = (*e)->getPosition();
        Int2 e_siz = (*e)->getSize();

        if(e_pos.x+e_siz.x < v_cen.x-v_siz.x/2)
            enemies.erase(e++);
    }

    for(list<AmmoView*>::iterator a = ammo.begin(); a != ammo.end(); a++)
    {
        if((*a)->getState() == Ammo::GHOST)
            ammo.erase(a++);
        else
        {
            Int2 a_pos = (*a)->getPosition();
            Int2 a_siz = (*a)->getSize();

            if((a_pos.x+a_siz.x < v_cen.x-v_siz.x/2)
            || (a_pos.x > v_cen.x+v_siz.x/2)
            || (a_pos.y+a_siz.y < v_cen.y-v_siz.y/2)
            || (a_pos.y > v_cen.y+v_siz.y/2))
                ammo.erase(a++);
        }
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


    /* CONFIG */
    config->resolution = Int2(mode.width,mode.height);

    /* CAMERA */
    view = View(FloatRect(0, 0, mode.width, mode.height));
    view_target = (ObjetPhysique*)(&player);
    window->setView(view);
}


void Game::setConfig(Config* c)
{
    config = c;
}

void Game::init()
{
    loadLevel();
}



void Game::loadLevel()
{

    /* ENVIRONNEMENT */
    //level.loadFromFile("res/xml/level/level1.xml",config->resolution);
    loadLevelXML("res/xml/level/level1.xml",config,&(level.environment),&textures);



    Texture* t;

    /* DECOR */
    // level.addPlatform(Int2(-10,650),Int2(10000,0),0); // Sol

    // t = new Texture();
    // t->loadFromFile("res/tex/decor/city.gif");
    // t->setRepeated(true);
    // textures.push_back(t);
    
    // level.addDecor(config->resolution,textures[textures.size()-1]);

    // /* PLATFORMS */
    // t = new Texture();
    // t->loadFromFile("res/tex/platform/wall.png");
    // t->setRepeated(true);
    // textures.push_back(t);

    // level.addPlatform(Int2(500,470),Int2(100,180),0,textures[textures.size()-1]); // Mur
    // level.addPlatform(Int2(760,320),Int2(400,40),0,textures[textures.size()-1]); // Mur

    
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
    new Weapon(&player,Weapon::PISTOL,100);
    new Weapon(&player,Weapon::SHOTGUN,100);
    player.setWeapon(0);


    /* ENNEMI */
    t = new Texture();
    t->loadFromFile("res/tex/enemy/rebel.png");
    textures.push_back(t);

    EnemyView* enemy = new EnemyView(Int2(1000,570),Int2(130,80),5,10,false,10);

    enemy->setTexture(textures[textures.size()-1]);
    enemy->addAnimations(loadSpriteFromFile("res/xml/enemy/rebel.xml"));
    enemy->changeAnimation(1);

    enemies.push_back(enemy);


    /* AMMO */
    // t = new Texture();
    // t->loadFromFile("res/tex/ammo/bullet.png");
    // textures.push_back(t);
    AmmoView::loadTextures();


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
        for(int y=anim[i].x; y<=anim[i].y; ++y)
        {
            Frame* f = new Frame(pos[y],siz[y]);
            a->addFrame(f);
        }
        ret.push_back(a);
    }

    return ret;
}