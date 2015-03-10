#include <iostream>
#include <list>

#include <model/Decor.h>
#include <model/Platform.h>

using namespace std;

class Decor;
class PLatform;


class Environment
{

	private :

		list<Decor> decors;
		list<Platform> platforms;
		//list<Destructible> destructibles;
		

	public :

		Environment();
		Environment(string filename);
		~Environment();

};
