#include <SFML/Graphics.hpp>
/* g++ sfml1.cpp -lsfml-graphics -lsfml-window -lsfml-system */
int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 500), "HaGame");

    /* creating our shape */
    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(320, 240);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

    while (window.isOpen()){
	sf::Event event;    

	while (window.pollEvent(event)){
	    /* event.type is a union or struct ? */
	    if (event.type == sf::Event::Closed){
		window.close();	
	    }
	}

	window.draw(rectangle);
	window.display();
    }

}
