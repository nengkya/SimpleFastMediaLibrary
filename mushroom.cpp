#include <SFML/Graphics.hpp>
/* g++ mushroom.cpp -lsfml-graphics -lsfml-window -lsfml-system */
int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 500), "mushroom");

    /* sf::Texture stores pixels that can be drawn, with a sprite for example */
    sf::Texture mushroomTexture;
    mushroomTexture.loadFromFile("mushroom.jpeg");

    /* sf::sprite draw texture*/
    sf::Sprite mushroom(mushroomTexture);

    /*
    rectangle.setPosition(320, 240);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
    */
    while (window.isOpen()){
	sf::Event event;    

	while (window.pollEvent(event)){
	    /* event.type is a union or struct ? */
	    if (event.type == sf::Event::Closed){
		window.close();	
	    }
	}

	window.draw(mushroom);
	window.display();
    }

}
