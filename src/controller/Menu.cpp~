#include "controller/Menu.h"

using namespace std;

Menu::Menu()
{
	/*selectedItemIndex = 0;
	font = NULL;
	menu = NULL;*/
}

Menu::Menu(vector<String> vectItems, RenderWindow* window, const Font& f, ScreenPositions screenPosition, unsigned int size)
{
	font = Font(f);
    
    // Récupération de la vue courante et la taille de la window pour bien positionner le menu
    View view;
    Vector2u window_size;
    if(window != NULL)
    {
    	view = window->getView();
    	window_size = window->getSize();
    }
    
    // Prise en compte de la position demandée
    float factX, factY;
    if(screenPosition == TOPLEFTHANDCORNER)
	{
		factX = -0.25;
		factY = -0.25;
	}
	else if(screenPosition == BOTTOMLEFTHANDCORNER)
	{
		factX = -0.25;
		factY = 0.25;
	}
	else if(screenPosition == BOTTOMRIGHTHANDCORNER)
	{
		factX = 0.25;
		factY = 0.25;
	}
	else if(screenPosition == TOPRIGHTHANDCORNER)
	{
		factX = 0.25;
		factY = -0.25;
	}
	else
	{
		factX = 0;
		factY = 0;
	}
    
    // Création du menu
	for(unsigned int i=0; i<vectItems.size(); i++)
	{
		Text text(vectItems[i], font, size);
		FloatRect text_size = text.getGlobalBounds();
		float x=0, y=0;
		
		x = view.getCenter().x + window_size.x*factX - text_size.width/2;
		y = view.getCenter().y + window_size.y*factY - text_size.height/2 + text_size.height*((float)(vectItems.size()+2*i) - (2*vectItems.size()-1));
		text.setPosition(x, y);
		menu.push_back(text);
	}
	selectedItemIndex = 0;
	menu[selectedItemIndex].setColor(Color::Black);
}

Menu::~Menu()
{}

void Menu::setTextItem(int index, String texte)
{

}

void Menu::moveUp()
{
	if(selectedItemIndex > 0)
	{
		menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex -= 1;
		menu[selectedItemIndex].setColor(Color::Black);
	}
}

void Menu::moveDown()
{
	if(selectedItemIndex < (int)menu.size()-1)
	{
		menu[selectedItemIndex].setColor(Color::White);
		selectedItemIndex += 1;
		menu[selectedItemIndex].setColor(Color::Black);
	}
}

int Menu::getSelectedItemIndex()
{
	return selectedItemIndex;
}

void Menu::draw(RenderWindow* window)
{
	for(unsigned int i=0; i<menu.size(); i++)
	{
		window->draw(menu[i]);
	}
}
