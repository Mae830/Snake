#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include "Apple.h"
#include "Grass.h"
#include "Board.h"
#include "Snake.h"

bool crash = false;

void moveSnake(sf::CircleShape & circle, sf::Vector2f & nMove, sf::Vector2f& cMove) {
    sf::Vector2f currPos = circle.getPosition();
    sf::Vector2f newPos = circle.getPosition();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        nMove = { -0.5, 0 };
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        nMove = { 0.5, 0 };
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        nMove = { 0, -0.5 };
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        nMove = { 0, 0.5 };
    }
    newPos = newPos + nMove;
    
    // check if new position is on a border
    if (newPos.x < 0 || newPos.x >= 450 || newPos.y < 0 || newPos.y >= 450) {
        // if on a border or not on a checkerboard pattern, keep previous position
        cMove = { 0, 0 };
    }else if ((int)currPos.x % 50 == 0 && (int)currPos.y % 50 == 0) {
        cMove = nMove;
    }
    circle.move(cMove);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        circle.setPosition(0, 0);
        cMove = { 0, 0 };
        nMove = { 0, 0 };
    }
    
}

void CheckUserInput(Snake& snake, sf::RenderWindow& window) {
    while (!crash)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            snake.SetNextMovement(1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            snake.SetNextMovement(2);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            snake.SetNextMovement(3);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            snake.SetNextMovement(4);
        }
    }
    if (crash) 
    {
        snake.SetNextMovement(0);
        snake.Stop();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    Board board(0);
    Snake snake;
    bool grow;
    
    Apple apple(board.getdimensions()[0], board.getdimensions()[1]);

    std::thread thread_obj(&CheckUserInput, std::ref(snake), std::ref(window));

    while (window.isOpen())
    {
        grow = false;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (snake.GetHead()->getPosition() == apple.GetShape()->getPosition()) {
            apple.SetApplePos(board.getdimensions()[0], board.getdimensions()[1]);
            grow = true;
        }

        window.clear();
        for (int i = 0; i < board.getdimensions()[0]; i++) {
            for (int j = 0; j < board.getdimensions()[1]; j++) {
                window.draw(board.getPlot(i, j).draw());
            }
        }

        //Draw Snake
        while (!snake.AtEnd()) {
            window.draw(*snake.GetShape());
        }
        window.draw(*snake.GetShape());

        //Draw Apple
        window.draw(*apple.GetShape());

        if (grow) {
            snake.Grow();
        }
        snake.MoveSnake(crash);
        if (grow) {
            snake.Attach();
        }

  
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    thread_obj.join();
    snake.DeleteSnake();
    return 0;
}