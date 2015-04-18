#include "view/EnemyView.h"


vector<SoundBuffer*> EnemyView::sounds_buffers[NB_TYPE_ENEMY];
Texture* EnemyView::textures[NB_TYPE_ENEMY];
vector<Animation> EnemyView::animations_list[NB_TYPE_ENEMY];
float EnemyView::volume;



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
	updateVolume();
}



void EnemyView::display(RenderWindow* window)
{
	Vector2f body_siz = body.getSize();

	body.setPosition(Vector2f(position.x+(size.x-body_siz.x)/2,position.y+size.y-body_siz.y));

	/* DEBUG */
	// body.setOutlineThickness(3);
	// body.setOutlineColor(Color::Black);
	// RectangleShape debug(Vector2f(size.x,size.y));
	// debug.setPosition(Vector2f(position.x,position.y));
	// debug.setOutlineThickness(3);
	// debug.setOutlineColor(Color::Black);
	// window->draw(debug);

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

	if(type == REBEL)
	{
		if(state_b==PRESHOOT && animations[current_anim].getIndFrame() == 10)
			shoot(save_air,save_angle);
		else if(state_b==KNIFE && current_anim==REBEL_WATCH)
		{
			state_b = NORMAL;
			if(haveAI)
				walk(walkway);
		}
	}

	if(type == BOWSER)
	{
		if(state_b==PRESHOOT && animations[current_anim].getIndFrame() == 4)
			shoot(save_air,save_angle);
		else if(state_b==SHOOT && current_anim==BOWSER_STAND)
		{
			state_b = NORMAL;
			state_p = RUN;
		}
	}

	updateIntRect();
}



void EnemyView::updateIntRect()
{
	if(animations.size()>0)
	{
		Frame* f = getFrame();
		Int2 pos = f->getPosition();
		Int2 siz = f->getSize();

		if(state_b == SHOOT)
		{
			if(gunway.x > 0)
				body.setTextureRect(IntRect(pos.x+siz.x,pos.y,-siz.x,siz.y));
			else
				body.setTextureRect(IntRect(pos.x,pos.y,siz.x,siz.y));
		}

		if(walkway > 0)
			body.setTextureRect(IntRect(pos.x+siz.x,pos.y,-siz.x,siz.y));
		else
			body.setTextureRect(IntRect(pos.x,pos.y,siz.x,siz.y));
	}
}



void EnemyView::walk(int way)
{
	if(state_b == DEAD)
		return;

	Enemy::walk(way);

	switch(type)
	{
		case REBEL : changeAnimation(REBEL_RUN); break;
		case BOWSER : changeAnimation(BOWSER_WALK); break;
	}

	updateIntRect();
}



void EnemyView::shoot(list<AmmoView*>* air, Int2 angle)
{	
	if(state_b == DEAD)
		return;

	list<Ammo*> tmp;
	AmmoView* av;
	
	if(type == REBEL)
	{
		if(current_anim==REBEL_KNIFE && state_b==PRESHOOT)
		{
			Enemy::knife();
		}
		else
		{
			state_b = PRESHOOT;
			state_p = WAIT;
			save_air = air;
			save_angle = angle;
			changeAnimation(REBEL_KNIFE,false,REBEL_WATCH);
		}
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
			state_p = WAIT;
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


bool EnemyView::canShoot()
{
	if(!Enemy::canShoot())
		return false;

	if(type == REBEL)
	{
		if(current_anim!=REBEL_KNIFE)
			return true;
	}
	else if(type==BOWSER)
	{
		if(current_anim!=BOWSER_FIRE)
			return true;
	}

	return false;
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

void EnemyView::updateVolume()
{
	for(unsigned int i=0; i<sounds.size(); ++i)
		sounds[i]->setVolume(EnemyView::volume);
}

void EnemyView::setVolume(float volume)
{
	EnemyView::volume = volume;
}

void EnemyView::resume()
{
	for(unsigned int i=0; i<sounds.size(); ++i)
	{
		if(sounds[i]->getStatus() == SoundSource::Paused)
			sounds[i]->play();
	}
}

void EnemyView::pause()
{
	for(unsigned int i=0; i<sounds.size(); ++i)
	{
		if(sounds[i]->getStatus() == SoundSource::Playing)
			sounds[i]->pause();
	}
}
