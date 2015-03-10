#include <iostream>

#include <model/Environment.h>

using namespace std;

class Environment;

class Level
{

	private :

		Environment environment;

	public :

		Level();
		Level(string filename);
		~Level();

};
