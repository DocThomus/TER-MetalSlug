#include "view/EnemyView.h"

bool EnemyView::ressources_loaded = false;
vector<SoundBuffer*> EnemyView::sounds_buffers;
Texture* EnemyView::textures[NB_TYPE_ENEMY];
vector<Animation> EnemyView::animations_list[NB_TYPE_ENEMY];



EnemyView::EnemyView(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow)
:Enemy(pos, siz, m, max_h, AI, pow)
{

}


EnemyView::EnemyView(Int2 pos, TypeEnemy t, bool AI)
:Enemy(pos,t,AI)
{
	/* REBEL */
	if(type == REBEL)
	{

		initSounds();
		setTexture(textures[REBEL]);
		addAnimations(animations_list[REBEL]);
		changeAnimation(WATCH);
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


void EnemyView::initSounds()
{
	switch(type)
	{
		case REBEL :
			sounds.push_back(new Sound(*sounds_buffers[0]));
			sounds.push_back(new Sound(*sounds_buffers[1]));
			sounds.push_back(new Sound(*sounds_buffers[2]));
			break;
	}
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

	changeAnimation(DEATH,false);
    
    srand(time(NULL));
    sounds[rand()%3]->play();
}






void EnemyView::loadRessources(TypeEnemy t)
{
	if(ressources_loaded)
		return;

	/* REBEL */
	if(t == REBEL)
	{
		// TEXTURE
		Texture* tex = new Texture();
	    tex->loadFromFile("res/tex/enemy/rebel.png");
	    textures[REBEL] = tex;

	    // ANIMATION
	    animations_list[REBEL] = loadAnimationsFromFile("res/xml/enemy/rebel.xml");

	    // SOUNDS
	    SoundBuffer* buffer;

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/death1.wav"); // DEATH
	    sounds_buffers.push_back(buffer);

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/death2.wav"); // DEATH2
	    sounds_buffers.push_back(buffer); 

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/death3.wav"); // DEATH3
	    sounds_buffers.push_back(buffer); 
	}

	ressources_loaded = true;
}


void EnemyView::deleteRessources()
{
	// sounds_buffers.clear();

 //    for(int i=0; i<NB_TYPE_ENEMY; ++i)
 //    	animations_list[i].clear();

    ressources_loaded = false;
}