#include "view/PlayerView.h"



vector<Sound*> PlayerView::sounds;

Texture* PlayerView::textures[2];

vector<Animation> PlayerView::animations_list[2];




PlayerView::PlayerView(Int2 pos, Int2 siz, int m, int max_h)
:Player(pos,siz,m,max_h)
{
	loadRessources();

	/* BODY */
	setTexture(textures[0]);
	addAnimations(animations_list[0]);
	
	/* LEGS */
	legs.setTexture(textures[1]);
	legs.addAnimations(animations_list[1]);

	/* ANIMATIONS */
	changeAnimation(PISTOLRUN);
	legs.changeAnimation(STAND);
	
	/* INITIALISATION TAILLES */
	legs.setSize(Int2(size.x*0.68,size.y*0.47));
	body.setSize(Vector2f(size.x,size.y*0.76));
}



PlayerView::PlayerView()
:Player()
{
	if(textures[0] == NULL)
		loadRessources();

	/* BODY */
	setTexture(textures[0]);
	addAnimations(animations_list[0]);
	
	/* LEGS */
	legs.setTexture(textures[1]);
	legs.addAnimations(animations_list[1]);

	/* ANIMATIONS */
	changeAnimation(PISTOLRUN);
	legs.changeAnimation(STAND);

	/* INITIALISATION TAILLES */
	legs.setSize(Int2(size.x*0.68,size.y*0.47));
	body.setSize(Vector2f(size.x,size.y*0.76));
}


PlayerView::~PlayerView()
{
}



void PlayerView::display(RenderWindow* window)
{
	/* JAMBES */
	Vector2f legs_size = legs.getSize();

	if(walkway>0) // marcher à droite
		legs.setPosition(Int2(position.x-(legs_size.x-size.x)/2,position.y+size.y-legs_size.y));
	else // marcher à gauche
		legs.setPosition(Int2(position.x-(legs_size.x-size.x)/2,position.y+size.y-legs_size.y));
	
	/* CORPS */
	Vector2f body_size = body.getSize();
	Vector2f legs_pos = legs.getPosition();

	if(state_b == DEAD) // mort
		body.setPosition(Vector2f(position.x,position.y+size.y-body_size.y));
	else if(state_b==KNIFE && current_anim==getAnimKnife2()) // corps à corps 2
		body.setPosition(Vector2f(legs_pos.x-((body_size.x-legs_size.x)/2),legs_pos.y-body_size.y+30));
	else if(state_b == SHOOT) // tirer
	{
		if(gunway.x > 0 && gunway.y == 0) // tirer à droite
			body.setPosition(Vector2f(position.x+15,position.y));
		else if(gunway.x < 0 && gunway.y == 0) // tirer à gauche
			body.setPosition(Vector2f(position.x+size.x-body_size.x-15,position.y));
		else if(gunway.x == 0 && gunway.y < 0) // tirer en haut
			body.setPosition(Vector2f(position.x+(walkway>0?15:size.x-body_size.x-15),legs_pos.y-body_size.y+15));
		else // tirer en bas
			body.setPosition(Vector2f(position.x+(walkway>0?20:size.x-body_size.x-20),position.y+10));
	}
	else // marcher
	{
		if(walkway > 0) // marcher à droite
			body.setPosition(Vector2f(position.x+15,position.y));
		else // marcher à gauche
			body.setPosition(Vector2f(position.x+size.x-body_size.x-15,position.y));
	}

	if(state_p == KNELT) // à genoux
	{
		Vector2f tmp = body.getPosition();
		body.setPosition(Vector2f(tmp.x,position.y+size.y-body_size.y));
	}


	
	/* FIX D'ANIMATIONS PARTICULIÈRES */
	
	// A genoux avec le SMG
	if(state_p!=KNELT && state_b==NORMAL && armes[current_weapon].getType()==Weapon::SMG)
	{
		if(walkway > 0)
			body.setPosition(Vector2f(position.x+15,position.y-28));
		else
			body.setPosition(Vector2f(position.x-45,position.y-28));
	}

	// Tirer vers le bas en l'air
	if(state_g==AIR && state_b==SHOOT && gunway.y>0)
	{
		Vector2f tmp = body.getPosition();
		if(armes[current_weapon].getType()==Weapon::SHOTGUN) // avec le shotgun
		{
			tmp.x += 15*-walkway ;
			body.setPosition(tmp);
		}
		if(armes[current_weapon].getType()==Weapon::SMG) // avec le smg
		{
			tmp.x += 20*-walkway ;
			body.setPosition(tmp);
		}
	}

	// Corps à corps 
	if(state_b==KNIFE && armes[current_weapon].getType()!=Weapon::PISTOL)
	{
		Vector2f tmp = body.getPosition();
		if(armes[current_weapon].getType()==Weapon::SHOTGUN)
		{
			if(current_anim==getAnimKnife())
				tmp.x = position.x-15;
			else
				tmp.x = position.x-50;
			tmp.y -= 5;
			body.setPosition(tmp);
		}
		if(armes[current_weapon].getType()==Weapon::SMG)
		{
			if(current_anim==getAnimKnife())
				tmp.x = position.x-10;
			else
				tmp.x = position.x+(size.x-body_size.x)/2;
			tmp.y = position.y+(size.y-body_size.y)/2-10;
			body.setPosition(tmp);
		}

	}


	/* DEBUG */
	// body.setOutlineThickness(3);
	// body.setOutlineColor(Color::Black);
	// RectangleShape debug(Vector2f(size.x,size.y));
	// debug.setPosition(Vector2f(position.x,position.y));
	// debug.setOutlineThickness(3);
	// debug.setOutlineColor(Color::Black);
	// window->draw(debug);


	/* DESSIN */
	if(state_p!=KNELT && state_b!=DEAD)
		legs.display(window);
	window->draw(body);
}



void PlayerView::animate(int dt)
{
	Player::animate(dt);

	/* CHANGEMENT DE FRAME : CORPS */
	cpt_time += dt;
	if(cpt_time >= animations[current_anim].getSpeed())
	{
		setNextFrame();
		cpt_time = 0;
	}

	/* CHANGEMENT DE FRAME : JAMBES */
	legs.cpt_time += dt;
	//cout << legs.animations[current_anim].getSpeed() << endl;
	if(legs.cpt_time >= legs.animations[legs.current_anim].getSpeed())
	{
		legs.setNextFrame();
		legs.cpt_time = 0;
	}

	/* CHANGEMENT D'ETAT : CORPS */
	if(state_b == SHOOT || state_b == KNIFE)
		if(current_anim==getAnimRun())
			state_b = NORMAL;

	updateIntRect();
}



void PlayerView::updateIntRect()
{
	if(animations.size()>0)
	{
		Frame* f = getFrame();
		Int2 pos = f->getPosition();
		Int2 siz = f->getSize();

		Frame* fl = legs.getFrame();
		Int2 posl = fl->getPosition();
		Int2 sizl = fl->getSize();

		/* JAMBES */
		if(walkway > 0)
			legs.setTextureRect(IntRect(posl.x,posl.y,sizl.x,sizl.y));
		else
			legs.setTextureRect(IntRect(posl.x+sizl.x,posl.y,-sizl.x,sizl.y));

		/* CORPS */
		if((state_b!=SHOOT && walkway>0) || (state_b==SHOOT && (gunway.x>0 || (gunway.x==0 && walkway>0))))
			body.setTextureRect(IntRect(pos.x,pos.y,siz.x,siz.y));
		else
			body.setTextureRect(IntRect(pos.x+siz.x,pos.y,-siz.x,siz.y));
	}
}



void PlayerView::walk(int way)
{
	if(state_b == DEAD)
        return;

	Player::walk(way);

	if(state_g == GROUND)
	{
		if(way == 0)
			legs.changeAnimation(STAND);
		else
			legs.changeAnimation(RUN);
	}
}


void PlayerView::jump(int h)
{
	if(state_b == DEAD)
        return;

	Character::jump(h);

	legs.changeAnimation(JUMP,false);
}


void PlayerView::land(int h)
{
	Character::land(h);

	/* CORPS */
	if(current_anim == getAnimShootDown())
		changeAnimation(getAnimRun());

	/* JAMBES */
	if(state_p == WAIT)
		legs.changeAnimation(STAND);
	else if(state_p == Character::RUN)
		legs.changeAnimation(RUN);
}


void PlayerView::kneel(bool b)
{
	if(state_b == DEAD)
        return;

	Player::kneel(b);

	if(state_g == Character::GROUND)
	{
		int i = (b ? getAnimKnee() : getAnimRun());
		if(current_anim!=getAnimKneeShoot() && current_anim!=getAnimKneeShootUp())
			changeAnimation(i);
		if(!b && (current_anim==getAnimKneeShoot() || current_anim==getAnimKneeShootUp()))
			changeAnimation(getAnimRun());
	}
}




void PlayerView::shoot(list<AmmoView*>* air, Int2 angle)
{
	if(state_b == DEAD)
        return;

    bool change = false;

	/* TIR + RECUPERATION DES MUNITIONS GÉNÉRÉES + CONVERSION AMMO->AMMOVIEW */
	list<Ammo*> tmp;
	Player::shoot(&tmp,angle);
	AmmoView* av;
	for(list<Ammo*>::iterator a = tmp.begin(); a != tmp.end(); a++)
    {
    	av = new AmmoView(**a);
    	air->push_back(av);
    	change = true;
    	delete *a;
    }
    tmp.clear();

    if(change) // si le joueur a pu tirer
    {
    	/* ANIMATION */
		gunway = angle;
		PlayerAnimationsBody anim_shoot;
		PlayerAnimationsBody anim_shoot_up;
		PlayerAnimationsBody anim_shoot_down;
		PlayerAnimationsBody anim_after;

		if(state_p == KNELT)
		{
			anim_shoot    = getAnimKneeShoot();
			anim_shoot_up = getAnimKneeShootUp();
			anim_after    = getAnimKnee();
		}
		else
		{
			anim_shoot      = getAnimShoot();
			anim_shoot_up   = getAnimShootUp();
			anim_shoot_down = getAnimShootDown();
			anim_after      = getAnimRun();
		}

		if(gunway.y<0)
			changeAnimation(anim_shoot_up,false,anim_after);
		else if(gunway.y>0)
			changeAnimation(anim_shoot_down,false,anim_after);
		else
			changeAnimation(anim_shoot,false,anim_after);	

		resetAnim();
    }
}

void PlayerView::throwGrenade(list<AmmoView*>* air) {
	if(state_b == DEAD)
        return;

    bool change = false;

    /* LANCEMENT DE LA GRENADE + RECUPERATION DES MUNITIONS GÉNÉRÉES + CONVERSION AMMO->AMMOVIEW */
	list<Ammo*> tmp;
	Player::throwGrenade(&tmp);
	AmmoView* av;

	for(list<Ammo*>::iterator a = tmp.begin(); a != tmp.end(); a++)
    {
    	av = new AmmoView(**a);
    	air->push_back(av);
    	change = true;
    	delete *a;
    }
    tmp.clear();

    if(change) // si le joueur a pu tirer
    {
    	/* ANIMATION */ // TODO
    	gunway = walkway;
		PlayerAnimationsBody anim_shoot;
		PlayerAnimationsBody anim_shoot_up;
		PlayerAnimationsBody anim_shoot_down;
		PlayerAnimationsBody anim_after;

		if(state_p == KNELT)
		{
			anim_shoot    = getAnimKneeShoot();
			anim_shoot_up = getAnimKneeShootUp();
			anim_after    = getAnimKnee();
		}
		else
		{
			anim_shoot      = getAnimShoot();
			anim_shoot_up   = getAnimShootUp();
			anim_shoot_down = getAnimShootDown();
			anim_after      = getAnimRun();
		}

		if(gunway.y<0)
			changeAnimation(anim_shoot_up,false,anim_after);
		else if(gunway.y>0)
			changeAnimation(anim_shoot_down,false,anim_after);
		else
			changeAnimation(anim_shoot,false,anim_after);	

		resetAnim();
    }
}

void PlayerView::knife()
{
    if(state_b == DEAD)
        return;

    Player::knife();

    PlayerAnimationsBody knife1 = getAnimKnife();
    PlayerAnimationsBody knife2 = getAnimKnife2();

    srand(time(NULL));

    if(rand()%2)
    	changeAnimation(knife1,false,getAnimRun());
    else
    	changeAnimation(knife2,false,getAnimRun());
}



void PlayerView::die()
{
	if(state_b == DEAD)
        return;

    Player::die();

	PlayerAnimationsBody death1 = DEATH;
    PlayerAnimationsBody death2 = DEATH2;

    srand(time(NULL));

    if(rand()%2)
    	changeAnimation(death1,false);
    else
    	changeAnimation(death2,false);

    sounds[0]->play();
}



void PlayerView::setWeapon(int w)
{
	if(state_b == DEAD)
        return;

	Player::setWeapon(w);

	if(state_p == KNELT)
		changeAnimation(getAnimKnee());
	else
		changeAnimation(getAnimRun());
	;
}



PlayerView::PlayerAnimationsBody PlayerView::getAnimRun()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLRUN;
		case Weapon::SHOTGUN : return SHOTGUNRUN;
		case Weapon::SMG     : return SMGRUN;

		default              : return PISTOLRUN;
	}
}



PlayerView::PlayerAnimationsBody PlayerView::getAnimShoot()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLSHOOT;
		case Weapon::SHOTGUN : return SHOTGUNSHOOT;
		case Weapon::SMG     : return SMGSHOOT;

		default              : return PISTOLSHOOT;
	}
}


PlayerView::PlayerAnimationsBody PlayerView::getAnimShootUp()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLSHOOTUP;
		case Weapon::SHOTGUN : return SHOTGUNSHOOTUP;
		case Weapon::SMG     : return SMGSHOOTUP;

		default              : return PISTOLSHOOTUP;
	}
}


PlayerView::PlayerAnimationsBody PlayerView::getAnimShootDown()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLSHOOTDOWN;
		case Weapon::SHOTGUN : return SHOTGUNSHOOTDOWN;
		case Weapon::SMG     : return SMGSHOOTDOWN;

		default              : return PISTOLSHOOTDOWN;
	}
}


PlayerView::PlayerAnimationsBody PlayerView::getAnimKnife()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLKNIFE;
		case Weapon::SHOTGUN : return SHOTGUNKNIFE;
		case Weapon::SMG     : return SMGKNIFE;

		default              : return PISTOLKNIFE;
	}
}


PlayerView::PlayerAnimationsBody PlayerView::getAnimKnife2()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLKNIFE2;
		case Weapon::SHOTGUN : return SHOTGUNKNIFE2;
		case Weapon::SMG     : return SMGKNIFE2;

		default              : return PISTOLKNIFE2;
	}
}


PlayerView::PlayerAnimationsBody PlayerView::getAnimKnee()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLKNEE;
		case Weapon::SHOTGUN : return SHOTGUNKNEE;
		case Weapon::SMG     : return SMGKNEE;

		default              : return PISTOLKNEE;
	}
}


PlayerView::PlayerAnimationsBody PlayerView::getAnimKneeShoot()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLKNEESHOOT;
		case Weapon::SHOTGUN : return SHOTGUNKNEESHOOT;
		case Weapon::SMG     : return SMGKNEESHOOT;

		default              : return PISTOLKNEESHOOT;
	}
}


PlayerView::PlayerAnimationsBody PlayerView::getAnimKneeShootUp()
{
	switch(armes[current_weapon].getType())
	{
		case Weapon::PISTOL  : return PISTOLKNEESHOOTUP;
		case Weapon::SHOTGUN : return SHOTGUNKNEESHOOTUP;
		case Weapon::SMG     : return SMGKNEESHOOTUP;

		default              : return PISTOLKNEESHOOTUP;
	}
}



void PlayerView::loadRessources()
{
	if(textures[0] != NULL)
		return;

	// TEXTURES 
	Texture* tex = new Texture();
    tex->loadFromFile("res/tex/player/body.png");
    textures[0] = tex;

    tex = new Texture();
    tex->loadFromFile("res/tex/player/legs.png");
    textures[1] = tex;

    // ANIMATIONS
    animations_list[0] = loadAnimationsFromFile("res/xml/player/body.xml");
    animations_list[1] = loadAnimationsFromFile("res/xml/player/legs.xml");

    // SOUNDS
    SoundBuffer* buffer;
	Sound* s;

	buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/player/death1.wav"); // DEATH
    s = new Sound();
    s->setBuffer(*buffer);
    sounds.push_back(s);
}




void PlayerView::deleteRessources()
{
	for(vector<Sound*>::iterator s = sounds.begin(); s != sounds.end(); s++)
        delete (*s);
    sounds.clear();

    delete textures[0];
    delete textures[1];
}