#ifndef DECOR_H
#define DECOR_H

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>

using namespace std;



class Decor : public ObjetPhysique
{
	
	protected :

		


	public :

		Decor(Int2 pos, Int2 siz, int z);
		Decor();
		~Decor();

		void print(ostream& os) const;



};

#endif