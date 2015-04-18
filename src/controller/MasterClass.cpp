#include "controller/MasterClass.h"


MasterClass::MasterClass()
:state(MAINMENU), previousState(MAINMENU), game(NULL)
{
	window = new RenderWindow(VideoMode::getDesktopMode(), "Metal Slug !!!", Style::None);
    window->setFramerateLimit(50);
    window->setKeyRepeatEnabled(false);
    window->setVerticalSyncEnabled(true);
    window->setMouseCursorVisible(false);
}


MasterClass::~MasterClass()
{
	delete window;
}


void MasterClass::initGame()
{
	//window = new RenderWindow();
	game = new Game();
    game->setConfig(&config);
    game->applyConfig(window);
    game->init();
    previousState = state;
	state = GAME;
}


void MasterClass::playApp()
{
	while (window->isOpen() && state != EXIT)
    {
        switch(state)
        {
        	case MAINMENU :
        		playMainMenu();
        		break;
        		
        	case NEWGAME :
        		initGame();
        		break;
        	
        	case GAME :
        		playGame();
        		break;
        		
        	case SETTINGS :
        		playSettings();
        		break;
        		
        	case HIGHSCORES :
        		previousState = state;
				state = MAINMENU;
        		break;
        	
        	default :
        		break;
        }
    }
    window->close();
}

void MasterClass::playMainMenu()
{
	if(game != NULL)
	{
		delete game;
		game = NULL;
	}
		
	window->setView(window->getDefaultView());
	Clock clock;
	Vector2u window_size = window->getSize();
	
    // Chargement de l'image du menu principal
    sf::Texture texture;
    texture.loadFromFile("res/tex/decor/menu_metal_slug2.png");
    Vector2u texture_size = texture.getSize();
    sf::Sprite sprite(texture);
    sprite.scale((float)window_size.x/texture_size.x, (float)window_size.y/texture_size.y);
    
    // Création d'un EnemiView pour une petite animation
    Int2 rebel_siren_position((int)window_size.x*0.875, (int)window_size.y*0.722);
    EnemyView rebel_siren(rebel_siren_position, Enemy::REBEL, false);
    rebel_siren.changeAnimation(EnemyView::REBEL_SIREN);
    
    // Création du menu principal
    Font font;
    font.loadFromFile("res/font/arcade.ttf");
    vector<String> vectItems;
    vectItems.push_back("Nouvelle partie");
    const int newGame = 0;
    vectItems.push_back("Reglages");
    const int settings = 1;
    vectItems.push_back("Quitter");
    const int exit = 2;
    Menu menu(vectItems, window, font, Menu::TOPRIGHTHANDCORNER, (unsigned int)window_size.y*0.0444);
    
    // Chargement et lecture de la musique du menu principal
    Music music;
    music.openFromFile("res/snd/level/Main_Theme_From_Metal_Slug.ogg");
    music.setVolume(config.musicsVolume);
    music.setLoop(true);
    music.play();
    
    while (window->isOpen() && state == MAINMENU)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
        	if (event.type == Event::KeyPressed)
        	{
        		switch(event.key.code)
        		{
        			case Keyboard::Up :
				    	menu.moveUp();
				    	break;
				    	
				    case Keyboard::Down :
				    	menu.moveDown();
				    	break;
				    	
				    case Keyboard::Return :
				    	switch(menu.getSelectedItemIndex())
				    	{
				    		case newGame :
				    			previousState = state;
								state = NEWGAME;
				    			break;
				    		
				    		case settings :
				    			previousState = state;
								state = SETTINGS;
				    			break;
				    		
				    		case exit :
				    			previousState = state;
								state = EXIT;
				    			break;
				    		
				    		default :
				    			break;
				    	}
				    	break;
				    	
				    	default :
				    		break;
        		}
			}
        }
        int t = clock.restart().asMilliseconds();
        rebel_siren.animate(t);
        window->clear();
        window->draw(sprite);
        menu.draw(window);
        rebel_siren.display(window);
        window->display();
    }
}

void MasterClass::playSettings()
{
	Vector2u window_size = window->getSize();
	Image img = window->capture();
	Texture texture;
	texture.loadFromImage(img);
	Vector2u texture_size = texture.getSize();
	Sprite sprite(texture);
	sprite.setColor(sf::Color(255, 255, 255, 128));
	sprite.scale((float)window_size.x/texture_size.x, (float)window_size.y/texture_size.y);
	View view = window->getView();
	sprite.setPosition(view.getCenter().x - (float)window_size.x/2, 0);
	
    Font font;
    font.loadFromFile("res/font/arcade.ttf");
    vector<String> vectItems;
    vectItems.push_back("Reprendre");
    const int resume = 0;
    vectItems.push_back("<- Volume musique +>");
    const int musicsVolume = 1;
    vectItems.push_back("<- Volume bruitages +>");
    const int soundEffectsVolume = 2;
    vectItems.push_back("Menu principal");
    const int mainMenu = 3;
    Menu menu(vectItems, window, font, Menu::CENTER, (unsigned int)window_size.y*0.0444);
	
	SoundBuffer buffer;
	Sound s;
	buffer.loadFromFile("res/snd/enemy/rebel/death1.wav");
	s.setBuffer(buffer);
	
	Music music;
    music.openFromFile("res/snd/level/The_Military_System.ogg");
    music.setVolume(config.musicsVolume);
    music.setLoop(true);
    music.play();
	
	while (window->isOpen() && state == SETTINGS)
	{
		sf::Event event;
		while(window->pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
        	{
        		switch(event.key.code)
        		{
        			case Keyboard::Escape :
						state = previousState;
						break;
						
					case Keyboard::Up :
				    	menu.moveUp();
				    	break;
				    	
				    case Keyboard::Down :
				    	menu.moveDown();
				    	break;
				    	
				    case Keyboard::Return :
				    	switch(menu.getSelectedItemIndex())
				    	{
				    		case resume :
				    			state = previousState;
				    			break;
				    		
				    		case mainMenu :
				    			previousState = state;
								state = MAINMENU;
				    			break;
				    		
				    		default :
				    			break;
				    	}
				    	break;
					
					case Keyboard::Left :
						switch(menu.getSelectedItemIndex())
				    	{
				    		case musicsVolume :
				    			config.musicsVolume -= 10;
								if(config.musicsVolume < 0)
									config.musicsVolume = 0;
								music.setVolume(config.musicsVolume);
				    			break;
				    		
				    		case soundEffectsVolume :
				    			config.soundEffectsVolume -= 10;
								if(config.soundEffectsVolume < 0)
									config.soundEffectsVolume = 0;
								s.setVolume(config.soundEffectsVolume);
								s.play();
				    			break;
				    		
				    		default :
				    			break;
				    	}
				    	break;
						
					case Keyboard::Right :
						switch(menu.getSelectedItemIndex())
				    	{
				    		case musicsVolume :
				    			config.musicsVolume += 10;
								if(config.musicsVolume > 100)
									config.musicsVolume = 100;
								music.setVolume(config.musicsVolume);
				    			break;
				    		
				    		case soundEffectsVolume :
				    			config.soundEffectsVolume += 10;
								if(config.soundEffectsVolume > 100)
									config.soundEffectsVolume = 100;
								s.setVolume(config.soundEffectsVolume);
								s.play();
				    			break;
				    		
				    		default :
				    			break;
				    	}
				    	break;
						
					default :
						break;
        		}
			}
		}
		window->clear();
		window->draw(sprite);
        menu.draw(window);
		window->display();
	}
}


// Modifier le volume des musiques et des bruitages du game
// 		-> Créer méthode setVolume(float, float)
//		-> Créer méthode pause() : pour mettre la musique du game/level en pause (peut etre plus...)
//		-> Créer méthode play() : pour (re)lancer musique (peut etre plus...)
void MasterClass::playGame()
{
    Clock clock;
    game->updateVolume();
    game->resume();
	while (window->isOpen() && state == GAME)
    {
    	game->checkKeyPressed();
    	Event event;
    	while(window->pollEvent(event))
    	{
    		if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    		{
    			game->pause();
    			previousState = state;
				state = SETTINGS;
			}
    		else
    			game->checkKeyboardEvents(event, window);
    	}
        game->update(clock.restart());
        game->checkCollisions();

        window->clear();
        game->display(window);

        window->display();
    }
}
