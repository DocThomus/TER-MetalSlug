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
	rectangle.setSize(Vector2f(size.x,size.y));
	rectangle.setPosition(Vector2f(position.x,position.y));
	window->draw(rectangle);
}


void DecorView::setTexture(Texture* tex)
{
	Vector2u size = tex->getSize();
	rectangle.setTexture(tex);
	rectangle.setTextureRect(IntRect(0,0,size.x,360));
}