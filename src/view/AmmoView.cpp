#include "view/AmmoView.h"


vector<Texture*> AmmoView::textures;


AmmoView::AmmoView()
:Ammo(),MyDrawable()
{
	body.setSize(Vector2f(size.x,size.y));
	body.setOrigin(size.x/2,size.y/2);
	initRotation();

	switch(type)
	{
		case BULLET :
			setTexture(textures[0]);
			addAnimations("res/xml/ammo/bullet.xml");
			changeAnimation(0,false);
			break;
	}

	updateIntRect();
}



AmmoView::AmmoView(Ammo a)
:Ammo(a),MyDrawable()
{
	body.setSize(Vector2f(size.x,size.y));
	body.setOrigin(size.x/2,size.y/2);
	initRotation();

	switch(type)
	{
		case BULLET :
			setTexture(textures[0]);
			addAnimations("res/xml/ammo/bullet.xml");
			changeAnimation(0,false);
			break;
	}

	updateIntRect();
}



AmmoView::~AmmoView()
{

}


void AmmoView::display(RenderWindow* window)
{
	if(state_a == GHOST)
		return;

	/* DEBUG */
	// body.setOutlineThickness(3);
	// body.setOutlineColor(Color::Black);

	body.setPosition(Vector2f(position.x,position.y-size.y/2));
	window->draw(body);
}


void AmmoView::animate(int dt)
{	
	Ammo::animate(dt);

	if(state_a == GHOST)
		return;

	bool change = false;

	/* CHANGEMENT DE FRAME */
	static int cpt = 0;
	cpt += dt;
	if(cpt >= 100)
	{
		change = setNextFrame();
		cpt = 0;

		if(!change && state_a==STOP)
			state_a = GHOST;
	}


	/* MISE A JOUR DE LA SELECTION DE LA TEXTURE */
	if(change)
		updateIntRect();	
}


void AmmoView::die(Int2 pos)
{
	Ammo::die(pos);
	changeAnimation(1,false);
}


void AmmoView::initRotation()
{
	float a = 0;
	a = atan2(movement.y,movement.x)*180/M_PI;
	body.setRotation(a);
}



void AmmoView::loadTextures()
{
	vector<Texture*> tmp;

	/* BULLET */
	Texture* tex = new Texture();
    tex->loadFromFile("res/tex/ammo/bullet.png");
    tmp.push_back(tex);

    textures = tmp;
}