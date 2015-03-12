#include "view/Animation.h"


Animation::Animation()
{
	current = 0;
}


Animation::Animation(vector<Frame*> v)
{
	frames = v;
}


Animation::~Animation()
{}



Frame* Animation::getFrame()
{
	if(frames.size()>0)
		return frames[current];
	else
		return NULL;
}


void Animation::setNextFrame()
{
	current++;
	if(current>=int(frames.size()))
		current = 0;
}



void Animation::addFrame(Frame* f)
{
	frames.push_back(f);
}