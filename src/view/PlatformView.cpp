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
	if(visible && size.y!=0) // On affiche que si la plateforme a une hauteur non nulle
		window->draw(body);
}


void PlatformView::updateIntRect()
{
	if(tex != NULL)
	{
		Vector2u t_siz = tex->getSize();
		Float2 siz(t_siz.x,t_siz.y);

		// cout << siz.x << "   " << siz.y << endl;
		// cout << size.x << "   " << size.y << endl;

		if(repeat_tex.x)
		{
			if(!repeat_tex.y)
				siz.x *= size.y/t_siz.y; 
			siz.x *= size.x/siz.x;
		}

		if(repeat_tex.y)
		{
			if(!repeat_tex.x)
				siz.y *= size.x/t_siz.x; 
			siz.y *= size.y/siz.y;
		}

		body.setTextureRect(IntRect(0,0,siz.x,siz.y));
	}
}