#include "view/PlayerView.h"


PlayerView::PlayerView(Int2 pos, Int2 siz, int z, int m, int max_h)
:Player(pos,siz,z,m,max_h)
{
}



PlayerView::PlayerView()
:Player()
{}


PlayerView::~PlayerView()
{
}


void PlayerView::display(RenderWindow* window)
{
	rectangle.setSize(Vector2f(size.x,size.y));
	rectangle.setPosition(Vector2f(position.x,position.y));

	window->draw(rectangle);
}



void PlayerView::animate(int dt)
{
	Player::animate(dt);
	
	/* CHANGEMENT DE FRAME */
	static int cpt = 100;
	cpt -= dt;
	if(cpt <= 0)
	{
		setNextFrame();
		updateIntRect();
		cpt = 100;
	}

	/* CHANGEMENT D'ANIMATION */
	if(state_p == RUN)
		changeAnimation(1);
	else
		changeAnimation(0);
}



void PlayerView::updateIntRect()
{
	if(animations.size()>0)
	{
		Frame* f = getFrame();
		Int2 pos = f->getPosition();
		Int2 siz = f->getSize();

		if(state_p == RUN || state_p == WAIT)
		{
			if(walkway > 0)
				rectangle.setTextureRect(IntRect(pos.x,pos.y,siz.x,siz.y));
			else
				rectangle.setTextureRect(IntRect(pos.x+siz.x,pos.y,-siz.x,siz.y));
		}
	}
}



void PlayerView::walk(int way)
{
	Player::walk(way);
	updateIntRect();
}



void PlayerView::shoot(list<AmmoView*>* air, Int2 angle, Texture* tex)
{
	shootSound();
	list<Ammo*> tmp;
	Player::shoot(&tmp,angle);
	AmmoView* av;
	for(list<Ammo*>::iterator a = tmp.begin(); a != tmp.end(); a++)
    {
    	av = new AmmoView(**a);
    	if(tex!=NULL)
    		av->setTexture(tex);
    	air->push_back(av);
    }
}


void PlayerView::shootSound()
{
	WeaponView* tmp = (WeaponView*)(armes[current_weapon]);
	tmp->shootSound();
}