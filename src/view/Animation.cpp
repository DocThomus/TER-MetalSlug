#include "view/Animation.h"


Animation::Animation()
{
	current = 0;
	repeat = true;
	next_anim = 0;
}


Animation::Animation(vector<Frame*> v)
{
	repeat = true;
	next_anim = 0;
	frames = v;
}


Animation::~Animation()
{}



Frame* Animation::getFrame()
{
	if(int(frames.size())>current)
		return frames[current];
	else
		return NULL;
}


bool Animation::setNextFrame()
{
	current++;

	if(current>=int(frames.size()))
	{
		if(!repeat)
			return false;
		current = 0;
	}

	return true;
}


void Animation::changeFrame(int i)
{
	if(i<int(frames.size()))
		current = i;
}


void Animation::addFrame(Frame* f)
{
	frames.push_back(f);
}


void Animation::reset()
{
	current = 0;
}


void Animation::setRepeat(bool r)
{
	repeat = r;
}


void Animation::setNextAnim(int i)
{
	next_anim = i;
}


int Animation::getNextAnim()
{
	return next_anim;
}
