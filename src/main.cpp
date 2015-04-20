#include <iostream>
#include <vector>

#include <controller/MasterClass.h>
#include <controller/Menu.h>


using namespace std;


int main()
{
	
	MasterClass mc;
	mc.playApp();
	
	
	/*
	// Create the main window
    sf::RenderWindow window(VideoMode::getDesktopMode(), "Metal Slug !!!", Style::None);
    window.setFramerateLimit(50);
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(false);
    
    Vector2u window_size = window.getSize();
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("res/tex/decor/menu_metal_slug2.png"))
        return EXIT_FAILURE;
    Vector2u texture_size = texture.getSize();
    sf::Sprite sprite(texture);
    sprite.scale((float)window_size.x/texture_size.x, (float)window_size.y/texture_size.y);
    cout << "scale x : " << (float)window_size.x/texture_size.x << " et scale y : " << (float)window_size.y/texture_size.y << endl;
    
    Clock clock;
    
    Int2 rebel_siren_position((int)window_size.x*0.875, (int)window_size.y*0.722);
    EnemyView rebel_siren(rebel_siren_position, Enemy::REBEL, false);
    rebel_siren.changeAnimation(EnemyView::REBEL_SIREN);
    
    // Create a menu to display
    Font font;
    font.loadFromFile("res/font/arcade.ttf");
    vector<String> vectItems;
    vectItems.push_back("Nouvelle partie");
    const int nouvellePartie = 0;
    vectItems.push_back("Reglages");
    const int reglages = 1;
    vectItems.push_back("Quitter");
    const int quitter = 2;
    Menu menu(vectItems, &window, font, Menu::TOPRIGHTHANDCORNER, (unsigned int)window_size.y*0.0444);
    
    // Load and create sound
    Music music;
    music.openFromFile("res/snd/level/Main_Theme_From_Metal_Slug.ogg");
    music.setLoop(true);
    music.play();
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Up)
            	menu.moveUp();
            else if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Down)
            	menu.moveDown();
            else if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Return)
            {
            	switch(menu.getSelectedItemIndex())
            	{
            		case nouvellePartie :
            			// state = NEWGAME
            			break;
            		
            		case reglages :
            			// state = SETTINGS
            			break;
            		
            		case quitter :
            			window.close();
            			break;
            	}
            }
        }
        int t = clock.restart().asMilliseconds();
        rebel_siren.animate(t);
        
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        
        menu.draw(&window);
        
        rebel_siren.display(&window);
        
        // Update the window
        window.display();
    }
	*/
	
	return 0;
}
