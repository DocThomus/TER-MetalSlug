#include "view/PlatformView.h"


PlatformView::PlatformView(Int2 pos, Int2 siz, int z, int wl)
:Platform(pos,siz,z,wl)
{
	rectangle.setFillColor(Color::Black);
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
		rectangle.setSize(Vector2f(size.x,size.y));
		rectangle.setPosition(Vector2f(position.x,position.y));
		window->draw(rectangle);
	}
}
