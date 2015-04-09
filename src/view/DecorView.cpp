#include "view/DecorView.h"


DecorView::DecorView(Int2 pos, Int2 siz, int z)
:Decor(pos,siz,z), tex_x(0)
{
}



DecorView::DecorView()
:Decor(), tex_x(0)
{	
}


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





void DecorView::animate(int x)
{
	Decor::animate(x); // decalage de l'objet

	
	/* DÉCALAGE DE LA TEXTURE EN PRENANT COMPTE DU Z POUR LE PARALLAXE */
	IntRect rect = body.getTextureRect();
	int offset = x-tex_x;
	if(offset > 0)
	{
		rect.left += (x-tex_x) / -z;
		body.setTextureRect(rect);
		tex_x = x;
	}
}