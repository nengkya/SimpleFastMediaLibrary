#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(333, 333), "HaGa IT Solution");
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Cyan);

    while (window.isOpen()) {
	sf::Event event;

	while (window.pollEvent(event)) {	
	    if (event.type == sf::Event::Closed) {
		window.close();
	    }
	
	/* clear maximize strech */
	window.clear();
	
	/* draw to buffer, not screen */
	window.draw(circle);
	window.display();
	}
    }
}
