#include "view/PlatformView.h"


PlatformView::PlatformView(Int2 pos, Int2 siz, int z, int wl)
:Platform(pos,siz,z,wl)
{
	body.setFillColor(Color::Black);
}



PlatformView::PlatformView()
:Platform()
{}


PlatformView::~PlatformView()
{
}


void PlatformView::display(RenderWindow* window)
{
	if(size.y!=0) // Si la plateform n'a aucune hauteur (plateforme invisible)
	{
		body.setSize(Vector2f(size.x,size.y));
		body.setPosition(Vector2f(position.x,position.y));
		window->draw(body);
	}
}
