#include "view/Animation.h"


Animation::Animation()
{
	current = 0;
	speed = 100;
	repeat = true;
	next_anim = -1;
}


Animation::Animation(vector<Frame> v)
{
	current = 0;
	speed = 100;
	repeat = true;
	next_anim = -1;
	frames = v;
}


Animation::~Animation()
{}


int Animation::getNbFrames()
{
	return int(frames.size());
}


Frame* Animation::getFrame()
{
	if(int(frames.size())>current)
		return &frames[current];
	else
		return NULL;
}


bool Animation::setNextFrame()
{
	current++;

	if(current>=int(frames.size()))
	{
		if(!repeat)
		{
			current--;
			return false;
		}
		else
			current = 0;
	}

	return true;
}


void Animation::changeFrame(int i)
{
	if(i<int(frames.size()))
		current = i;
}


void Animation::addFrame(Frame f)
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

void Animation::setSpeed(int s)
{
	speed = s;
}


int Animation::getNextAnim()
{
	return next_anim;
}

int Animation::getSpeed()
{
	return speed;
}
