#include <SFML/Graphics.hpp>

#define SIZE 25
#define SCREEN_WIDTH SIZE * SIZE
#define SCREEN_HEIGHT SIZE * SIZE

struct Apple {
  int x, y;
} apple;

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Snake");

    sf::RectangleShape appleShape(sf::Vector2f(SIZE, SIZE));
    appleShape.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
          if (e.type == sf::Event::Closed) window.close();
        }

        window.clear();

        appleShape.setPosition(apple.x * SIZE, apple.y * SIZE);
        window.draw(appleShape);

        window.display();
    }
    return 0;
}
