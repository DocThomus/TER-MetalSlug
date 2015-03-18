#include "view/DecorView.h"


DecorView::DecorView(Int2 pos, Int2 siz, int z)
:Decor(pos,siz,z)
{

}



DecorView::DecorView()
:Decor()
{}


DecorView::~DecorView()
{
}


void DecorView::display(RenderWindow* window)
{
	body.setSize(Vector2f(size.x,size.y));
	body.setPosition(Vector2f(position.x,position.y));
	window->draw(body);
}

