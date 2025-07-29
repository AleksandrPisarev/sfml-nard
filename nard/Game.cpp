#include "Game.h"
Game::Game() : window(sf::VideoMode(800, 800), "Nard")
{
    if (!bgTextur.loadFromFile("board.jpg")) {

        }
    bgSprite.setTexture(bgTextur);
    bgSprite.setPosition(sf::Vector2f(40.f, 40.f));
    for (int i = 0; i < 24; i++) {
        Chip chip;
        chip.setPosition(fieldCoord[i]);
        field[i].push_back(chip);
    }
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
    window.draw(bgSprite);
    for (int i = 0; i < 24; i++) {
        for (auto el : field[i]) {
            el.render(window);
        }
    }
    window.display();
}