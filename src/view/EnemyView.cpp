#include "view/EnemyView.h"


vector<Sound*> EnemyView::sounds;

Texture* EnemyView::textures[NB_TYPE_ENEMY];

vector<Animation> EnemyView::animations_list[NB_TYPE_ENEMY];



EnemyView::EnemyView(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow)
:Enemy(pos, siz, m, max_h, AI, pow)
{

}


EnemyView::EnemyView(Int2 pos, TypeEnemy t)
:Enemy(pos,t)
{
	/* REBEL */
	if(type == REBEL)
	{
		setTexture(textures[REBEL]);
		addAnimations(animations_list[REBEL]);
		changeAnimation(0);
	}

	body.setSize(Vector2f(size.x,size.y));
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
}



void EnemyView::display(RenderWindow* window)
{
	Vector2f body_siz = body.getSize();

	body.setPosition(Vector2f(position.x+(size.x-body_siz.x)/2,position.y+size.y-body_siz.y));

	/* DEBUG */
	// body.setOutlineThickness(5);
	// body.setOutlineColor(Color::Black);

	/* DESSIN */
	window->draw(body);
}



void EnemyView::animate(int dt)
{
	Enemy::animate(dt);

	/* CHANGEMENT DE FRAME */
	cpt_time += dt;
	if(cpt_time >= animations[current_anim].getSpeed())
	{
		setNextFrame();
		cpt_time = 0;
	}

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



void EnemyView::shoot(list<AmmoView*>* air, Int2 angle)
{	
	list<Ammo*> tmp;
	Enemy::shoot(&tmp,angle);
	AmmoView* av;
	for(list<Ammo*>::iterator a = tmp.begin(); a != tmp.end(); a++)
    {
    	av = new AmmoView(**a);
    	air->push_back(av);
    	tmp.erase(a++);
    }
}


void EnemyView::die()
{
	state_b = DEAD;
	changeAnimation(1,false);
	sounds[0]->play();
}






void EnemyView::loadRessources(TypeEnemy t)
{
	SoundBuffer* buffer;
	Sound* s;

	if(textures[t] != NULL)
		return;

	/* REBEL */
	if(t == REBEL)
	{
		// TEXTURE
		Texture* tex = new Texture();
	    tex->loadFromFile("res/tex/enemy/rebel.png");
	    textures[REBEL] = tex;

	    // ANIMATION
	    animations_list[REBEL] = loadSpriteFromFile("res/xml/enemy/rebel.xml");

	    // SOUNDS
		buffer = new SoundBuffer();
		buffer->loadFromFile("res/snd/enemy/death1.wav"); // DEATH
	    s = new Sound();
	    s->setBuffer(*buffer);
	    sounds.push_back(s);
	}

}


void EnemyView::deleteRessources()
{
	for(vector<Sound*>::iterator s = sounds.begin(); s != sounds.end(); s++)
        delete (*s);
    sounds.clear();

    for(int i=0; i<NB_TYPE_ENEMY; ++i)
    	if(textures[i] != NULL)
    		delete textures[i];
}