#include "view/MyDrawable.h"


MyDrawable::MyDrawable()
:current_anim(0)
{
	cpt_time = 0;
}



MyDrawable::~MyDrawable()
{
}


void MyDrawable::resetAnim()
{
	Int2 old = getFrame()->getSize();
	Vector2f siz = body.getSize();

	animations[current_anim].reset();

	Int2 now = getFrame()->getSize();
	body.setSize(Vector2f(siz.x*now.x/old.x,siz.y*now.y/old.y));

	updateIntRect();
}


void MyDrawable::addAnimation(Animation a)
{
	animations.push_back(a);
}


void MyDrawable::addAnimations(vector<Animation> v)
{
	for(unsigned int i=0; i<v.size(); ++i)
		addAnimation(v[i]);
}



void MyDrawable::addAnimations(string filename)
{
    vector<Int2> anim;
    vector<int> speed;
    vector<Int2> pos;
    vector<Int2> siz;

    if(!loadSpriteMap(filename,&anim,&speed,&pos,&siz))
    {
        cerr << "Erreur dans le chargement de l'animation : " << filename << endl;
        exit(-1);
    }

    vector<Animation> ret;

    for(unsigned int i=0; i<anim.size(); ++i)
    {
        Animation a;

        if(speed[i] >= 0)
        	a.setSpeed(speed[i]);

        for(int y=anim[i].x; y<=anim[i].y; ++y)
        {
            Frame f(pos[y],siz[y]);
            a.addFrame(f);
        }
        ret.push_back(a);
    }

    addAnimations(ret);
}


bool MyDrawable::changeAnimation(int i, bool repeat, int next)
{
	if(i != current_anim)
	{
		Int2 old = getFrame()->getSize();
		Vector2f siz = body.getSize();
		
		/* CHANGEMENT DE L'ANIMATION */
		current_anim = i;
		if(current_anim<0)
			current_anim = 0;
		else if(current_anim>=int(animations.size()))
			current_anim = animations.size()-1;

		animations[current_anim].reset();
		animations[current_anim].setRepeat(repeat);
		if(!repeat)
			animations[current_anim].setNextAnim(next);

		/* MISE A JOUR DES PROPORTIONS DU RECTANGLE */
		Int2 now = getFrame()->getSize();
		body.setSize(Vector2f(siz.x*now.x/old.x,siz.y*now.y/old.y));

		updateIntRect();

		return true;
	}

	return false;
}


void MyDrawable::changeFrame(int i)
{
	animations[current_anim].changeFrame(i);
	updateIntRect();
}


Frame* MyDrawable::getFrame()
{
	if(animations.size()>0)
		return animations[current_anim].getFrame();
	else
		return NULL;
}


bool MyDrawable::setNextFrame(int n)
{
	Int2 old = getFrame()->getSize();
	Vector2f siz = body.getSize();

	/* SELECTION DE LA FRAME SUIVANTE */
	bool ok = true;
	for(int i=0; ok && i<n; ++i)
	{
		if(!animations[current_anim].setNextFrame())
		{
			if(animations[current_anim].getNextAnim() >= 0)
				current_anim = animations[current_anim].getNextAnim();
			else
				return false;
			ok = false;
		}
	}

	/* MISE A JOUR DES PROPORTIONS DU RECTANGLE */
	Int2 now = getFrame()->getSize();
	body.setSize(Vector2f(siz.x*now.x/old.x,siz.y*now.y/old.y));

	/* MISE A JOUR DU RECTANGLESHAPE */
	updateIntRect();

	return true;

}



void MyDrawable::setTexture(Texture* t, Bool2 r)
{
	tex = t;
	Vector2u size = tex->getSize();
	body.setTexture(tex);
	body.setTextureRect(IntRect(0,0,size.x,size.y));
	repeat_tex = r;
	updateIntRect();
}


void MyDrawable::updateIntRect()
{
	if(animations.size()>0)
	{
		Frame* f = getFrame();
		Int2 pos = f->getPosition();
		Int2 siz = f->getSize();

		body.setTextureRect(IntRect(pos.x,pos.y,siz.x,siz.y));
	}
}


vector<Animation> MyDrawable::loadAnimationsFromFile(string filename)
{
vector<Int2> anim;
vector<int> speed;
vector<Int2> pos;
vector<Int2> siz;
if(!loadSpriteMap(filename,&anim,&speed,&pos,&siz))
{
cerr << "Erreur dans le chargement de l'animation : " << filename << endl;
exit(-1);
}
vector<Animation> ret;
for(unsigned int i=0; i<anim.size(); ++i)
{
Animation a;
if(speed[i] > 0)
a.setSpeed(speed[i]);
for(int y=anim[i].x; y<=anim[i].y; ++y)
{
Frame f(pos[y],siz[y]);
a.addFrame(f);
}
ret.push_back(a);
}
return ret;
}
