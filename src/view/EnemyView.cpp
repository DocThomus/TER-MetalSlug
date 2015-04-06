#include "view/EnemyView.h"


vector<SoundBuffer*> EnemyView::sounds_buffers[NB_TYPE_ENEMY];
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
		loadRessources(REBEL);
		initSounds();
		setTexture(textures[REBEL]);
		addAnimations(animations_list[REBEL]);
		changeAnimation(REBEL_WATCH);
		updateIntRect();
	}

	/* BOWSER */
	else if(type == BOWSER)
	{
		loadRessources(BOWSER);
		initSounds();
		setTexture(textures[BOWSER]);
		addAnimations(animations_list[BOWSER]);
		changeAnimation(BOWSER_STAND);
		updateIntRect();
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
	for(unsigned int i=0; i<sounds_buffers[type].size(); ++i)
		sounds.push_back(new Sound(*(sounds_buffers[type])[i]));
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

	if(type == BOWSER)
	{
		if(state_b==PRESHOOT && animations[current_anim].getIndFrame() == 4)
			shoot(save_air,save_angle);
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
	AmmoView* av;
	
	if(type == REBEL)
	{
		Enemy::shoot(&tmp,angle);
	}

	else if(type == BOWSER)
	{
		if(current_anim==BOWSER_FIRE && state_b==PRESHOOT)
		{
			Enemy::shoot(&tmp,angle);
		}
		else
		{
			state_b = PRESHOOT;
			save_air = air;
			save_angle = angle;
			changeAnimation(BOWSER_FIRE,false,BOWSER_STAND);
		}
	}
	

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

	switch(type)
	{
		case REBEL  : changeAnimation(REBEL_DEATH,false);  break;
		case BOWSER : changeAnimation(BOWSER_DEATH,false); break;
	}
    
    srand(time(NULL));
    
    if(type == REBEL)
    {
		RebelSounds tmp_snd[3] = {REBEL_DEATH_SND, REBEL_DEATH2_SND, REBEL_DEATH3_SND};
		sounds[tmp_snd[rand()%3]]->play();
    }
    else if(type == BOWSER)
	{
		sounds[BOWSER_DEATH_SND]->play();
		sounds[BOWSER_DEATH2_SND]->play();
    }
    
}






void EnemyView::loadRessources(TypeEnemy t)
{
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
	    animations_list[REBEL] = loadAnimationsFromFile("res/xml/enemy/rebel.xml");

	    // SOUNDS
	    SoundBuffer* buffer;

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/rebel/death1.wav"); // DEATH
	    sounds_buffers[REBEL].push_back(buffer);

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/rebel/death2.wav"); // DEATH2
	    sounds_buffers[REBEL].push_back(buffer); 

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/rebel/death3.wav"); // DEATH3
	    sounds_buffers[REBEL].push_back(buffer); 
	}

	/* BOWSER */
	else if(t == BOWSER)
	{
		// TEXTURE
		Texture* tex = new Texture();
	    tex->loadFromFile("res/tex/enemy/bowser.png");
	    textures[BOWSER] = tex;

	    // ANIMATION
	    animations_list[BOWSER] = loadAnimationsFromFile("res/xml/enemy/bowser.xml");

	    // SOUNDS
	    SoundBuffer* buffer;

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/bowser/death.wav"); // DEATH
	    sounds_buffers[BOWSER].push_back(buffer);

	    buffer = new SoundBuffer;
		buffer->loadFromFile("res/snd/enemy/bowser/death2.wav"); // DEATH2
	    sounds_buffers[BOWSER].push_back(buffer);
	}
}


void EnemyView::deleteRessources()
{
	// sounds_buffers.clear();

 //    for(int i=0; i<NB_TYPE_ENEMY; ++i)
 //    	animations_list[i].clear();
}