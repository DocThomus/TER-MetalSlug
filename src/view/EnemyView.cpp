#include "view/EnemyView.h"


vector<Sound*> EnemyView::sounds = loadSounds();

Texture* EnemyView::textures[NB_TYPE_ENEMY];



EnemyView::EnemyView(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow)
:Enemy(pos, siz, m, max_h, AI, pow)
{

}


EnemyView::EnemyView(Int2 pos, TypeEnemy t)
:Enemy(pos,t)
{
	/* REBEL */
	if(type == REBEL)
		setTexture(textures[REBEL]);
}



EnemyView::EnemyView()
:Enemy()
{
	
}


EnemyView::~EnemyView()
{
}


void EnemyView::init()
{
	changeAnimation(0);
}



void EnemyView::display(RenderWindow* window)
{
	body.setSize(Vector2f(size.x,size.y));
	body.setPosition(Vector2f(position.x,position.y));

	// body.setOutlineThickness(5);
	// body.setOutlineColor(Color::Black);

	window->draw(body);
}



void EnemyView::animate(int dt)
{
	Enemy::animate(dt);

	bool change = false;

	/* CHANGEMENT DE FRAME */
	static int cpt = 0;
	cpt += dt;
	if(cpt >= 100)
	{
		setNextFrame();
		cpt = 0;
		change = true;
	}


	/* CHANGEMENT D'ANIMATION */
	if(state_b == DEAD)
	{
		static int cpt_die = 0;
		cpt_die += dt;
	}



	/* MISE A JOUR DE LA SELECTION DE LA TEXTURE */
	if(change)
		updateIntRect();
}



void EnemyView::updateIntRect()
{
	if(animations.size()>0)
	{
		Frame* f = getFrame();
		Int2 pos = f->getPosition();
		Int2 siz = f->getSize();


		body.setTextureRect(IntRect(pos.x,pos.y,siz.x,siz.y));
	}
}



void EnemyView::walk(int way)
{
	
}



void EnemyView::shoot(list<AmmoView*>* air, Int2 angle, Texture* tex)
{


}


void EnemyView::die()
{
	state_b = DEAD;
	changeAnimation(2,false);
	sounds[0]->play();
}




vector<Sound*> EnemyView::loadSounds()
{
	vector<Sound*> tmp;

	/* DEATH */
	SoundBuffer* buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/enemy/death1.wav");
    Sound* s = new Sound();
    s->setBuffer(*buffer);
    tmp.push_back(s);


    return tmp;
}



void EnemyView::loadTexture(TypeEnemy t)
{
	/* REBEL */
	if(t == REBEL)
	{
		Texture* tex = new Texture();
	    tex->loadFromFile("res/tex/enemy/rebel.png");
	    textures[REBEL] = tex;
	}

}