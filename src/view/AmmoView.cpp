#include "view/AmmoView.h"


vector<Texture*> AmmoView::textures;
vector<Sound*> AmmoView::sounds;
vector<Animation> AmmoView::animations_list[NB_TYPE_AMMO];


AmmoView::AmmoView()
:Ammo(),MyDrawable()
{
	Int2 tmp_siz;

	if(type==BULLET || type==HEAVY_BULLET || type==LIGHT_BULLET)
		tmp_siz = Int2(50,12);

	if(type==FLAME)
		tmp_siz = Int2(300,150);

	if(type==GRENADE)
		tmp_siz = Int2(25,45);

	body.setOrigin(size.x/2,size.y/2);
	body.setSize(Vector2f(tmp_siz.x,tmp_siz.y));
	initRotation();

	loadRessources();
	initRessources();

	updateIntRect();
}



AmmoView::AmmoView(Ammo a)
:Ammo(a),MyDrawable()
{
	Int2 tmp_siz;

	if(type==BULLET || type==HEAVY_BULLET || type==LIGHT_BULLET)
		tmp_siz = Int2(50,12);

	if(type==FLAME)
		tmp_siz = Int2(300,150);

	if(type==GRENADE)
		tmp_siz = Int2(25,45);

	body.setSize(Vector2f(tmp_siz.x,tmp_siz.y));
	body.setOrigin(size.x/2,size.y/2);
	initRotation();

	loadRessources();
	initRessources();

	updateIntRect();
}



AmmoView::~AmmoView()
{

}


void AmmoView::initRessources()
{
	switch(type)
	{
		case BULLET :
			setTexture(textures[BULLET]);
			addAnimations(animations_list[BULLET]);
			sounds[BULLET]->play();
			break;

		case HEAVY_BULLET :
			setTexture(textures[BULLET]);
			addAnimations(animations_list[BULLET]);
			sounds[HEAVY_BULLET]->play();
			break;

		case LIGHT_BULLET :
			setTexture(textures[BULLET]);
			addAnimations(animations_list[BULLET]);
			sounds[BULLET]->play();
			break;

		case FLAME :
			setTexture(textures[FLAME]);
			addAnimations(animations_list[FLAME]);
			sounds[FLAME]->play();
			break;

		case GRENADE :
			setTexture(textures[GRENADE]); // Provisoire, besoin d'un sprite de grenade
			addAnimations(animations_list[GRENADE]);
			break;
	}

	changeAnimation(1,false);
	changeAnimation(0,false);
	updateIntRect();
}


void AmmoView::display(RenderWindow* window)
{
	if(state_a == GHOST)
		return;

	/* DEBUG */
	// body.setOutlineThickness(3);
	// body.setOutlineColor(Color::Black);
	// RectangleShape debug(Vector2f(size.x,size.y));
	// debug.setPosition(Vector2f(position.x,position.y));
	// debug.setOutlineThickness(3);
	// debug.setOutlineColor(Color::Black);
	// window->draw(debug);
	

	if(movement.x > 0)
		body.setPosition(Vector2f(position.x,position.y+size.y*0.5));
	else if(movement.x < 0)
		body.setPosition(Vector2f(position.x+size.x,position.y+size.y*0.5));
	else if(movement.y > 0)
		body.setPosition(Vector2f(position.x+size.x*0.5,position.y));
	else if(movement.y < 0)
		body.setPosition(Vector2f(position.x+size.x*0.5,position.y+size.y));
	
	if(type==GRENADE)
	{
		Vector2f body_siz = body.getSize();
		body.setPosition(Vector2f(position.x+(size.x-body_siz.x)/2,position.y+size.y-body_siz.y));
	}

	window->draw(body);
}



void AmmoView::animate(int dt)
{	
	Ammo::animate(dt);

	if(state_a == GHOST)
		return;

	bool change = false;

	/* CHANGEMENT DE FRAME */
	cpt_time += dt;
	if(cpt_time >= animations[current_anim].getSpeed())
	{
		change = setNextFrame();
		cpt_time = 0;

		if(type==FLAME && !change)
			state_a = GHOST;
		else if(!change && state_a==STOP)
			state_a = GHOST;
	}


	/* MISE A JOUR DE LA SELECTION DE LA TEXTURE */
	//if(change)
		updateIntRect();	
}


void AmmoView::die(Int2 pos)
{
	Ammo::die(pos);

	if(type==BULLET || type==HEAVY_BULLET || type==LIGHT_BULLET)
		changeAnimation(1,false);
	else if(type==GRENADE)
	{
		initRotation();
		changeAnimation(1,false);
	}
}


void AmmoView::initRotation()
{
	float a = 0;
	a = atan2(movement.y,movement.x)*180/M_PI;
	body.setRotation(a);
}



void AmmoView::loadRessources()
{	
	if(textures.size() > 0)
		return;

	/* === TEXTURES === */
	Texture* tex;

	/* BULLET */
	tex = new Texture();
    tex->loadFromFile("res/tex/ammo/bullet.png");
    textures.push_back(tex);

    textures.push_back(NULL);
    textures.push_back(NULL);

    /* FLAME */
	tex = new Texture();
    tex->loadFromFile("res/tex/ammo/flame.png");
    textures.push_back(tex);
    
    textures.push_back(NULL);
    
    /* GRENADE */
	tex = new Texture();
    tex->loadFromFile("res/tex/ammo/grenade.png");
    textures.push_back(tex);
    
	
    /* === ANIMATIONS ===*/
    animations_list[BULLET] = loadAnimationsFromFile("res/xml/ammo/bullet.xml");
    animations_list[FLAME] = loadAnimationsFromFile("res/xml/ammo/flame.xml");
    animations_list[GRENADE] = loadAnimationsFromFile("res/xml/ammo/grenade.xml");
    

   
    /* === SONS === */

    /* BULLET */
	SoundBuffer* buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/ammo/bullet.wav");
    Sound* s = new Sound();
    s->setBuffer(*buffer);
    sounds.push_back(s);

    /* HEAVY_BULLET */
    buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/ammo/shotgun.wav");
    s = new Sound();
    s->setBuffer(*buffer);
    sounds.push_back(s);

    /* LIGHT_BULLET */
    sounds.push_back(NULL);

    /* FLAME */
    buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/ammo/flame.wav");
    s = new Sound();
    s->setBuffer(*buffer);
    sounds.push_back(s);
}



void AmmoView::deleteRessources()
{
	for(vector<Texture*>::iterator t = textures.begin(); t != textures.end(); t++)
        delete (*t);
    textures.clear();

    for(vector<Sound*>::iterator s = sounds.begin(); s != sounds.end(); s++)
        delete (*s);
    sounds.clear();
}

void AmmoView::setVolume(float volume)
{
	for(unsigned int i=0; i<sounds.size(); ++i)
	{
		if(sounds[i] != NULL)
		{
			sounds[i]->setVolume(volume);
		}
	}
}

void AmmoView::resume()
{
	for(unsigned int i=0; i<sounds.size(); ++i)
	{
		if(sounds[i] != NULL && sounds[i]->getStatus() == SoundSource::Paused)
			sounds[i]->play();
	}
}

void AmmoView::pause()
{
	for(unsigned int i=0; i<sounds.size(); ++i)
	{
		if(sounds[i] != NULL && sounds[i]->getStatus() == SoundSource::Playing)
			sounds[i]->pause();
	}
}
