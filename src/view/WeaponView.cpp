#include "view/WeaponView.h"

vector<Sound*> WeaponView::sounds = loadSounds();


WeaponView::WeaponView()
:Weapon()
{	
}


WeaponView::WeaponView(PlayerView* p, TypeWeapon type, int max_mun)
:Weapon(p,type,max_mun)
{
	//p->addWeapon(this);
}


WeaponView::~WeaponView()
{

}


void WeaponView::shootSound()
{
	// if(ammos.x>0)
	// {
		switch(type)
		{
			case PISTOL :
				sounds[0]->play();
				break;
			case SHOTGUN :
				sounds[1]->play();
	//	}
	}
}


vector<Sound*> WeaponView::loadSounds()
{
	vector<Sound*> tmp;

	/* PISTOL */
	SoundBuffer* buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/weapon/bullet.wav");
    Sound* s = new Sound();
    s->setBuffer(*buffer);
    tmp.push_back(s);

    /* SHOTGUN */
    buffer = new SoundBuffer();
	buffer->loadFromFile("res/snd/weapon/shotgun.wav");
    s = new Sound();
    s->setBuffer(*buffer);
    tmp.push_back(s);

    return tmp;
}