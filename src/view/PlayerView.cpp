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
	
	/* INITIALISATION TAILLES */
	legs.setSize(Int2(size.x*0.68,size.y*0.47));
	body.setSize(Vector2f(size.x,size.y*0.76));

	/* ANIMATIONS */
	changeAnimation(PISTOLRUN);
	legs.changeAnimation(STAND);
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

	if(state_b == KNIFE && current_anim==PISTOLKNIFE2) // corps à corps 
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


	/* DEBUG */
	// body.setOutlineThickness(5);
	// body.setOutlineColor(Color::Black);
	// legs.body.setOutlineThickness(5);
	// legs.body.setOutlineColor(Color::Black);


	/* DESSIN */
	if(state_p != KNELT)
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
	if(legs.cpt_time >= legs.animations[current_anim].getSpeed())
	{
		legs.setNextFrame();
		legs.cpt_time = 0;
	}


	/* CHANGEMENT D'ETAT : CORPS */
	if(state_b == SHOOT || state_b == KNIFE)
		if(current_anim==PISTOLRUN || current_anim==PISTOLKNEE)
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
	Character::jump(h);
	legs.changeAnimation(JUMP,false);
}


void PlayerView::land(int h)
{
	Character::land(h);
	if(state_p == WAIT)
		legs.changeAnimation(STAND);
	else if(state_p == Character::RUN)
		legs.changeAnimation(RUN);
}


void PlayerView::kneel(bool b)
{
	Player::kneel(b);
	if(state_g == Character::GROUND)
	{
		int i = (b ? PISTOLKNEE : PISTOLRUN);
		if(current_anim!=PISTOLKNEESHOOT && current_anim!=PISTOLKNEESHOOTUP)
			changeAnimation(i);
		if(!b && (current_anim==PISTOLKNEESHOOT || current_anim==PISTOLKNEESHOOTUP))
			changeAnimation(PISTOLRUN);
	}
}




void PlayerView::shoot(list<AmmoView*>* air, Int2 angle)
{
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
			anim_shoot    = PISTOLKNEESHOOT;
			anim_shoot_up = PISTOLKNEESHOOTUP;
			anim_after    = PISTOLKNEE;
		}
		else
		{
			anim_shoot      = PISTOLSHOOT;
			anim_shoot_up   = PISTOLSHOOTUP;
			anim_shoot_down = PISTOLSHOOTDOWN;
			anim_after      = PISTOLRUN;
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
    Player::knife();

    PlayerAnimationsBody knife1 = PISTOLKNIFE;
    PlayerAnimationsBody knife2 = PISTOLKNIFE2;

    srand(time(NULL));

    if(rand()%2)
    	changeAnimation(knife1,false,PISTOLRUN);
    else
    	changeAnimation(knife2,false,PISTOLRUN);
}




void PlayerView::loadRessources()
{
	if(textures[0] != NULL)
		return;

	Texture* tex = new Texture();
    tex->loadFromFile("res/tex/player/body.png");
    textures[0] = tex;

    tex = new Texture();
    tex->loadFromFile("res/tex/player/legs.png");
    textures[1] = tex;

    animations_list[0] = loadSpriteFromFile("res/xml/player/body.xml");
    animations_list[1] = loadSpriteFromFile("res/xml/player/legs.xml");
}




void PlayerView::deleteRessources()
{
	for(vector<Sound*>::iterator s = sounds.begin(); s != sounds.end(); s++)
        delete (*s);
    sounds.clear();

    delete textures[0];
    delete textures[1];
}