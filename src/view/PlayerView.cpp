#include "view/PlayerView.h"


PlayerView::PlayerView(Int2 pos, Int2 siz, int m, int max_h)
:Player(pos,siz,m,max_h)
{
	//body.setOrigin(size.x/2,size.y/2);
}



PlayerView::PlayerView()
:Player()
{
	//body.setOrigin(size.x/2,size.y/2);
}


PlayerView::~PlayerView()
{
}


void PlayerView::init()
{
	legs.setSize(Int2(size.x*0.68,size.y*0.47));
	body.setSize(Vector2f(size.x,size.y*0.76));
	//changeAnimation(1);
}


void PlayerView::display(RenderWindow* window)
{
	/* JAMBES */
	Vector2f legs_size = legs.getSize();

	if(walkway>0)
		legs.setPosition(Int2(position.x-(legs_size.x-size.x)/2,position.y+size.y-legs_size.y));
	else
		legs.setPosition(Int2(position.x-(legs_size.x-size.x)/2,position.y+size.y-legs_size.y));
	
	/* CORPS */
	Vector2f body_size = body.getSize();
	Vector2f legs_pos = legs.getPosition();
	
	if(state_p == KNELT)
	{
		if(state_b==SHOOT && gunway.x<0)
			body.setPosition(Vector2f(position.x+size.x-body_size.x,position.y+size.y-body_size.y));
		else
			body.setPosition(Vector2f(position.x,position.y+size.y-body_size.y));
	}
	else
	{
		if(state_b==SHOOT && gunway.x==0) // tire vers le haut
			body.setPosition(Vector2f(position.x+(walkway>0?15:0),legs_pos.y-body_size.y+15));
		else if((state_b==SHOOT && gunway.x>0) || (state_b!=SHOOT && walkway>0)) // tire a gauche
			body.setPosition(Vector2f(position.x+15,position.y));
		else // tire a droite ou autre
			body.setPosition(Vector2f(position.x+size.x-body_size.x-15,position.y));
	}


	/* DESSIN */
	if(state_p != KNELT)
		legs.display(window);
	window->draw(body);
}



void PlayerView::animate(int dt)
{
	Player::animate(dt);

	/* CHANGEMENT DE FRAME : CORPS */
	int speed = (state_b==NORMAL ? 200 : 80);
	static int cpt_b = 0;
	cpt_b += dt;
	if(cpt_b >= speed)
	{
		setNextFrame();
		cpt_b = 0;
	}

	/* CHANGEMENT DE FRAME : JAMBES */
	static int cpt_l = 0;
	cpt_l += dt;
	if(cpt_l >= 100)
	{
		legs.setNextFrame();
		cpt_l = 0;
	}

	/* CHANGEMENT D'ANIMATION : JAMBES */
	if(state_g == AIR)
		legs.changeAnimation(2,false);
	else if(state_p == RUN)
		legs.changeAnimation(1);
	else
		legs.changeAnimation(0);

	/* CHANGEMENT D'ANIMATION : CORPS */
	if(state_b == SHOOT)
	{
		if(current_anim==0 || current_anim==3)
			state_b = NORMAL;
	}
	else if(state_p == KNELT)
		changeAnimation(3);
	else
		changeAnimation(0);

	/* MISE A JOUR DE LA SELECTION DE LA TEXTURE */
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
	updateIntRect();
}


void PlayerView::kneel(bool b)
{
	Player::kneel(b);
	int i = (b ? 3 : 0);
	if(current_anim!=4)
		changeAnimation(i);
	if(!b && current_anim==4)
		changeAnimation(0);
	updateIntRect();
}


void PlayerView::shoot(list<AmmoView*>* air, Int2 angle, Texture* tex)
{

	bool change = false;

	/* TIR + RECUPERATION DES MUNITIONS GÉNÉRÉES + CONVERSION AMMO->AMMOVIEW */
	list<Ammo*> tmp;
	Player::shoot(&tmp,angle);
	AmmoView* av;
	for(list<Ammo*>::iterator a = tmp.begin(); a != tmp.end(); a++)
    {
    	av = new AmmoView(**a);
    	if(tex!=NULL)
    		av->setTexture(tex);
    	air->push_back(av);

    	change = true;
    }

    if(change) // si le joueur a pu tirer
    {
    	/* SON */
		WeaponView* wv = (WeaponView*)(armes[current_weapon]);
		wv->shootSound();
	
    	/* ANIMATION */
		gunway = angle;
		if(state_p==KNELT)
		{
			changeAnimation(4,false,3);
		}
		else
		{
			if(gunway.x==0)
				changeAnimation(2,false,0);
			else
				changeAnimation(1,false,0);
		}
		reset();
		updateIntRect();
		
    }
}

