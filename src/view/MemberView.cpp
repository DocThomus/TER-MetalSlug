#include "view/MemberView.h"


MemberView::MemberView()
{
	current_anim = 0;
}



MemberView::~MemberView()
{

}


void MemberView::display(RenderWindow* window)
{
	// body.setOutlineThickness(5);
	// body.setOutlineColor(Color::Black);
	window->draw(body);
}


void MemberView::setSize(Int2 siz)
{
	body.setSize(Vector2f(siz.x,siz.y));
}


void MemberView::setPosition(Int2 pos)
{
	body.setPosition(Vector2f(pos.x,pos.y));
}


Vector2f MemberView::getSize()
{
	return body.getSize();
}


Vector2f MemberView::getPosition()
{
	return body.getPosition();
}


void MemberView::setTextureRect(IntRect r)
{
	body.setTextureRect(r);
}