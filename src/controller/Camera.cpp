#include <controller/Camera.h>


Camera::Camera(Int2 pos, Int2 siz)
:position(pos),size(siz)
{	

}


Camera::Camera()
{	
	position = Int2(0,0);
	size     = Int2(0,0);
}


Camera::~Camera()
{

}


Int2 Camera::getPosition()
{
	return position;
}
		

Int2 Camera::getSize()
{
	return size;
}


void Camera::setPosition(Int2 pos)
{
	position = pos;
}


void Camera::setSize(Int2 siz)
{
	size = siz;
}


void Camera::setTarget(ObjetPhysique* obj)
{
	target = obj;
}


void Camera::animate(int dt)
{
	Int2 pos   = target->getPosition();
	Int2 siz   = target->getSize();
	Float2 mov = target->getMovement();

	if(mov.x>0 && pos.x+siz.x>position.x+size.y/6)
	{
		position.x += pos.x+siz.x-position.x+size.y/6;
		cout << "lol" << endl;
	}
}