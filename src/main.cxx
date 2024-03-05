#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>

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

void move() {
  for (int i = snakeSize; i > 0; i--) {
    s[i].x = s[i - 1].x;
    s[i].y = s[i - 1].y;
  }

  switch (direction) {
    case SnakeDirection::UP:
      s[0].y -= 1;
      break;
    case SnakeDirection::DOWN:
      s[0].y += 1;
      break;
    case SnakeDirection::LEFT:
      s[0].x -= 1;
      break;
    case SnakeDirection::RIGHT:
      s[0].x += 1;
      break;
  }

  if ((s[0].x == apple.x) && (s[0].y == apple.y)) {
    snakeSize++;
    snakeSpeed++;
    apple.x = rand() % SIZE;
    apple.y = rand() % SIZE;
  }

  for (int i = 1; i < snakeSize; i++) {
    if (s[0].x == s[i].x && s[0].y == s[i].y) {
      snakeSize = 1;
      snakeSpeed = 1;
      s[0].x = 0;
      s[0].y = 0;
      direction = SnakeDirection::RIGHT;

      printf("Game Over\n");
      exit(1);
    }
  }

  if (s[0].x > SIZE) s[0].x = 0;
  else if (s[0].x < 0) s[0].x = SIZE;
  else if (s[0].y > SIZE) s[0].y = 0;
  else if (s[0].y < 0) s[0].y = SIZE;
}

int main(int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Snake");

    sf::Clock ticker;

    sf::RectangleShape snakeShape(sf::Vector2f(SIZE, SIZE));
    snakeShape.setFillColor(sf::Color::Green);

    sf::RectangleShape appleShape(sf::Vector2f(SIZE, SIZE));
    appleShape.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
          if (e.type == sf::Event::Closed) window.close();
          else if (e.type == sf::Event::KeyPressed) {
            switch (e.key.code) {
              case sf::Keyboard::Up:
                direction = SnakeDirection::UP;
                printf("UP\n");
                break;
              case sf::Keyboard::Down:
                direction = SnakeDirection::DOWN;
                printf("DOWN\n");
                break;
              case sf::Keyboard::Left:
                direction = SnakeDirection::LEFT;
                printf("LEFT\n");
                break;
              case sf::Keyboard::Right:
                direction = SnakeDirection::RIGHT;
                printf("RIGHT\n");
                break;
            }
          }
        }

        window.clear();

        if (ticker.getElapsedTime().asMilliseconds() > 100) {
          move();
          ticker.restart();
        }

        for (int i = 0; i < snakeSize; i++) {
          snakeShape.setPosition(s[i].x * SIZE, s[i].y * SIZE);
          window.draw(snakeShape);
        }

        appleShape.setPosition(apple.x * SIZE, apple.y * SIZE);
        window.draw(appleShape);

        window.display();
    }
    return 0;
}
