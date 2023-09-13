#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(333, 333), "HaGa IT Solution");
    while (window.isOpen()) {
	sf::Event event;
	while (window.pollEvent(event)) {	
	    if (event.type == sf::Event::Closed) {
		window.close();
	    }
	}
    }
}
