#include "view/AmmoView.h"



AmmoView::AmmoView()
:Ammo(),MyDrawable()
{
	body.setSize(Vector2f(size.x,size.y));
	body.setOrigin(size.x/2,size.y/2);
	initPosition();
}



AmmoView::AmmoView(Ammo a)
:Ammo(a),MyDrawable()
{
	body.setSize(Vector2f(size.x,size.y));
	body.setOrigin(size.x/2,size.y/2);
	initPosition();
}



AmmoView::~AmmoView()
{

}


void AmmoView::display(RenderWindow* window)
{
	body.setPosition(Vector2f(position.x,position.y-size.y/2));
	
	window->draw(body);
}



void AmmoView::initPosition()
{
	float a = 0;
	
	// if(movement.x>=0.2)
	// {
	// 	if(movement.y>=0.2)
	// 		a = 45;
	// 	else if(movement.y<=-0.2)
	// 		a = -45;
	// }
	// else if(movement.x==0)
	// {
	// 	if(movement.y>=0.2)
	// 		a = 90;
	// 	else if(movement.y<=-0.2)
	// 		a = -90;
	// }
	// else
	// {
	// 	if(movement.y>=0.2)
	// 		a = 135;
	// 	else if(movement.y==0)
	// 		a = 180;
	// 	else 
	// 		a = -135;
	// }

	a = atan2(movement.y,movement.x)*180/M_PI;
	

	body.setRotation(a);
}