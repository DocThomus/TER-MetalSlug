#include "view/Animation.h"


Animation::Animation()
{
	current = 0;
}



Animation::~Animation()
{}



Frame* Animation::getFrame()
{
	return &frames[current];
}


void Animation::setNextFrame()
{
	current++;
	if(current>=int(frames.size()))
		current = 0;
}