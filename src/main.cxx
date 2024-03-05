#include <SFML/Graphics.hpp>

#define SIZE 20
#define SCREEN_WIDTH SIZE * SIZE
#define SCREEN_HEIGHT SIZE * SIZE



int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Snake");

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
          if (e.type == sf::Event::Closed) window.close();
        }

        window.display();
    }
    return 0;
}
