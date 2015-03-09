#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>
#include <model/Player.h>
#include <model/Ammo.h>

using namespace std;


class Player;
class Ammo;


class Weapon : public ObjetPhysique
{
	
	protected :

		Int2 angle;

		Player* owner;

		int max_munitions;
		int munitions;
		int mass_munitions; // masse des projectils produits par l'arme
		Int2 size_munitions;


	public :

		enum State {GROUND,OWNED};
		State state;
		
		Weapon(Int2 pos, Int2 siz, int z, int m, int max_mun, int mass_mun);
		Weapon(Player* p, int max_mun, int mass_mun);
		Weapon();
		~Weapon();

		string toString();

		void shoot(vector<Ammo*>* air);	


};

#endif