#include <SFML/Graphics.hpp>

#define SIZE 25
#define SCREEN_WIDTH SIZE * SIZE
#define SCREEN_HEIGHT SIZE * SIZE

int snakeSize = 1;

enum SnakeDirection {
  UP, DOWN, LEFT, RIGHT // UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
} snakeDirection;

SnakeDirection direction = SnakeDirection::RIGHT;
int snakeSpeed = 1;

struct Snake {
  int x, y;
} s[100];

struct Apple {
  int x, y;
} apple;

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Snake");

    sf::RectangleShape snakeShape(sf::Vector2f(SIZE, SIZE));
    snakeShape.setFillColor(sf::Color::Green);

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


        snakeShape.setPosition(s[0].x * SIZE, s[0].y * SIZE);
        window.draw(snakeShape);

        window.display();
    }
    return 0;
}
