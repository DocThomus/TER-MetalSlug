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


void DecorView::updateIntRect()
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

