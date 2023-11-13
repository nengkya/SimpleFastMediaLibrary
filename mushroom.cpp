#include <SFML/Graphics.hpp>
/* g++ mushroom.cpp -lsfml-graphics -lsfml-window -lsfml-system */
int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 500), "mushroom");

    /* sf::Texture stores pixels that can be drawn, with a sprite for example */
    sf::Texture mushroomTexture;
    mushroomTexture.loadFromFile("mushroom.jpeg");

    /* sf::sprite draw texture*/
    sf::Sprite mushroomSprite(mushroomTexture);
    sf::Vector2u mushroomSize = mushroomTexture.getSize();
    mushroomSprite.setOrigin(mushroomSize.x / 2, mushroomSize.y / 2);
    sf::Vector2f mushroomIncrement(0.4f, 0.4);

    while (window.isOpen()){
	sf::Event event;    

	while (window.pollEvent(event)){
	    /* event.type is a union or struct ? */
	    if (event.type == sf::Event::Closed){
		window.close();	
	    }
	}

	if (
	    (mushroomSprite.getPosition().x + (mushroomSize.x / 2) > window.getSize().x &&
	     mushroomIncrement.x > 0)
	    ||
	    (mushroomSprite.getPosition().x - (mushroomSize.x / 2) < 0 && mushroomIncrement.x < 0)
	   ){
	    /* reverse x axist direction */
	    mushroomIncrement.x = - mushroomIncrement.x;
	}

	if (
	    (mushroomSprite.getPosition().y + (mushroomSize.y / 2) > window.getSize().y &&
	    mushroomIncrement.y > 0)
	    ||
	    (mushroomSprite.getPosition().y - (mushroomSize.y / 2) < 0 && mushroomIncrement.y < 0)
	   )
	   {
	    mushroomIncrement.y = - mushroomIncrement.y;
	}

	mushroomSprite.setPosition(mushroomSprite.getPosition() + mushroomIncrement);

	/*
	 dark grey
	 sf::Color(R, G, B, A);
	*/
	window.clear(sf::Color(16, 16, 16, 255));
	window.draw(mushroomSprite);
	window.display();
    }

}
