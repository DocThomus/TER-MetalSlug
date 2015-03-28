#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

#include <model/Enemy.h>
#include <view/MyDrawable.h>
#include <view/AmmoView.h>

using namespace std;
using namespace sf;

class WeaponView;


/***
* EnemyView -> Enemy -> Character -> ObjetPhysique
*           -> MyDrawable
* ===========================================================
* Permet d'afficher un objet Enemy avec diverses animations.
***/



class EnemyView : public Enemy, public MyDrawable
{

	private :

		static vector<Sound*> sounds;


	public :

		
		EnemyView(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow);
		EnemyView();
		~EnemyView();

		static vector<Sound*> loadSounds();

		void init();

		void display(RenderWindow* window);

		void animate(int dt);

		void updateIntRect();

		void walk(int way);
		
		void die();

		void shoot(list<AmmoView*>* ammos, Int2 angle = Int2(1,0), Texture* tex=NULL);
};


#endif
