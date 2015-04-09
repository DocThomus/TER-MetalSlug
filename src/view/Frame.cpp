#include "view/Frame.h"


Frame::Frame()
{
}

Frame::Frame(Int2 pos, Int2 siz)
{
	position.x = pos.x; position.y = pos.y;
	size.x = siz.x;     size.y = siz.y;
}

Frame::~Frame()
{}


Int2 Frame::getPosition()
{
	return position;
}


Int2 Frame::getSize()
{
	return size;
}

