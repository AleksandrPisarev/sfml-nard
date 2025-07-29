#include "Game.h"
Game::Game() : window(sf::VideoMode(800, 600), "SFML window")
{

}

void Game::run()
{
    while (window.isOpen())
    {
         processEvent();
         update();
         render();
    }
}

void Game::processEvent()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update()
{

}

void Game::render()
{
    window.clear();
    window.display();
}