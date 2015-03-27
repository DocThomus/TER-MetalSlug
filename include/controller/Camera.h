#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <tools/tools.h>
#include <model/ObjetPhysique.h>

using namespace std;


class ObjetPhysique;


class Camera
{
	
	private :

		Int2 position;
		Int2 size;

		ObjetPhysique* target;

	public :

		Camera();
		Camera(Int2 pos, Int2 siz);
		~Camera();

		Int2 getPosition();
		Int2 getSize();

		void setPosition(Int2);
		void setSize(Int2);
		void setTarget(ObjetPhysique*);

		void animate(int dt);

};


#endif