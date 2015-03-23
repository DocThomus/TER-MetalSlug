#include "view/PlatformView.h"


PlatformView::PlatformView(Int2 pos, Int2 siz, int wl)
:Platform(pos,siz,wl)
{
	//body.setFillColor(Color::Black);
	body.setSize(Vector2f(size.x,size.y));
	body.setPosition(Vector2f(position.x,position.y));
	body.setOutlineThickness(2);
	body.setOutlineColor(Color::Black);
}



PlatformView::PlatformView()
:Platform()
{
	body.setSize(Vector2f(size.x,size.y));
	body.setPosition(Vector2f(position.x,position.y));
	body.setOutlineThickness(2);
	body.setOutlineColor(Color::Black);
}


PlatformView::~PlatformView()
{
}


void PlatformView::display(RenderWindow* window)
{
	if(size.y!=0) // Si la plateform n'a aucune hauteur (plateforme invisible)
	{
		window->draw(body);
	}
}
