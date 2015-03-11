#include "view/MyDrawable.h"


MyDrawable::MyDrawable()
{

}



MyDrawable::~MyDrawable()
{}


void MyDrawable::addAnimation(Animation a)
{
	animations.push_back(a);
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
	return animations[current_anim].getFrame();
}


void MyDrawable::setNextFrame()
{
	animations[current_anim].setNextFrame();
}