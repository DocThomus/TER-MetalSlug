#include "view/MyDrawable.h"


MyDrawable::MyDrawable()
:current_anim(0)
{

}



MyDrawable::~MyDrawable()
{

}


void MyDrawable::addAnimation(Animation* a)
{
	animations.push_back(a);
}


void MyDrawable::addAnimations(vector<Animation*> v)
{
	for(unsigned int i=0; i<v.size(); ++i)
		addAnimation(v[i]);
}


void MyDrawable::changeAnimation(int i)
{
	current_anim = i;
	if(current_anim<0)
		current_anim = 0;
	else if(current_anim>=int(animations.size()))
		current_anim = animations.size()-1;
}


Frame* MyDrawable::getFrame()
{
	if(animations.size()>0)
		return animations[current_anim]->getFrame();
	else
		return NULL;
}


void MyDrawable::setNextFrame()
{
	animations[current_anim]->setNextFrame();
}



void MyDrawable::setTexture(Texture* tex)
{
	Vector2u size = tex->getSize();
	rectangle.setTexture(tex);
	rectangle.setTextureRect(IntRect(0,0,size.x,size.y));
	updateIntRect();
}


void MyDrawable::updateIntRect()
{
	if(animations.size()>0)
	{
		Frame* f = getFrame();
		Int2 pos = f->getPosition();
		Int2 siz = f->getSize();
		rectangle.setTextureRect(IntRect(pos.x,pos.y,siz.x,siz.y));
	}
}