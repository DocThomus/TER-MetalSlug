#include "view/ItemView.h"


vector<Texture*> ItemView::textures;
vector<Sound*> ItemView::sounds;



ItemView::ItemView(Int2 pos, TypeItem type_i, Weapon::TypeWeapon type_w)
:Item(pos,type_i,type_w)
{
	if(textures.size() <= 0)
		loadRessources();

	switch(type)
	{
		case WEAPON :
			size = Int2(60,60);
			if(type_weapon==Weapon::SHOTGUN)  setTexture(textures[0]);
			else if(type_weapon==Weapon::SMG) setTexture(textures[1]);
			break;
	}

	body.setPosition(Vector2f(position.x,position.y));
	body.setSize(Vector2f(size.x,size.y));
	updateIntRect();
}


ItemView::ItemView()
:Item()
{
	if(textures.size() <= 0)
		loadRessources();
}


ItemView::~ItemView()
{

}


void ItemView::display(RenderWindow* window)
{
	/* DEBUG */
	// body.setOutlineThickness(3);
	// body.setOutlineColor(Color::Black);
	
	if(state==WAIT)
		window->draw(body);
}


void ItemView::trigger(PlayerView* p)
{
	Item::trigger(p);
	
	p->setWeapon(p->current_weapon);
	
	sounds[0]->play();
}



void ItemView::loadRessources()
{	
	if(textures.size() > 0)
		return;

	/* === TEXTURES === */
	Texture* tex;

	/* SHOTGUN */
	tex = new Texture();
    tex->loadFromFile("res/tex/item/shotgun.png");
    textures.push_back(tex);

    /* SMG */
    tex = new Texture();
    tex->loadFromFile("res/tex/item/smg.png");
    textures.push_back(tex);
   
    /* === SONS === */

    /* BULLET */
	SoundBuffer* buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/item/drop.wav");
    Sound* s = new Sound();
    s->setBuffer(*buffer);
    sounds.push_back(s);
}