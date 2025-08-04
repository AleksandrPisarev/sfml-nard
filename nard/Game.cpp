#include "Game.h"
Game::Game() : window(sf::VideoMode(800, 800), "Nard")
{
    if (!bgTextur.loadFromFile("board.jpg")) {
        std::cout << "file not loaded";
    }
    bgSprite.setTexture(bgTextur);
    bgSprite.setPosition(sf::Vector2f(40.f, 40.f));
    startPosition();
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
        if (event.type == sf::Event::Closed) window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left) {
                movePlayer();
            }
        }
    }
}

void Game::update()
{
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < field[i].size(); j++) {
            if (field[i][j].getColor() == sf::Color::Red) field[i][j].off();
        }
    }
    if (activeChip >= 0) field[activeChip][field[activeChip].size() - 1].on();
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

void Game::startPosition()
{
    for (int i = 0; i < 15; i++) {
        Chip chip(sf::Color::Red);
        chip.move(0, field[0].size());
        field[0].push_back(chip);
    }

    for (int i = 0; i < 15; i++) {
        Chip chip(sf::Color::Black);
        chip.move(12, field[12].size());
        field[12].push_back(chip);
    }
}

void Game::movePlayer()
{
    double distance;
    ////////// ��������� ���� ���� �� ��������� �� ����� //////////
    if (activeChip < 0) { // activChip ���������� ������� ���������� �������� �� ����� ��� ��� ���� �� ����� �������� ��� ��������� �������� ������� ������� Field
        // ���������� activeChip = -1
        for (int i = 0; i < 24; i++) {
            if ((field[i].size() != 0) && (field[i][field[i].size() - 1].getColor() == sf::Color::Red)) {
                // ���������� ������� ���������� ���������� �� ����� ����� �� ������ ����� ���� ���������� ������ ������� �����
                // ������ ���� ����� �� ����� � ��� ����� ��������
                distance = sqrt(pow((event.mouseButton.x - field[i][field[i].size() - 1].getPosition().x), 2) + pow((event.mouseButton.y - field[i][field[i].size() - 1].getPosition().y), 2));
                if (distance <= 13) {
                    activeChip = i;
                    break;
                }
            }
        }
    }
    ////////// ��������� ���� ���� �� �� ����� ���� ���������� ����������� ����� //////////
    else {
        for (int i = 0; i < 24; i++) {
            if (i != activeChip) {
                // ���������� ������� ���������� ���������� �� ����� ����� �� ������ ���� ����� ���� ���� ����������� �����
                // ����������� ������ fieldCoord ������ Chip ��� ����� ������ ����� Game ������������� ���� fieldCoord �����������
                distance = sqrt(pow((event.mouseButton.x - Chip::fieldCoord[i].x), 2) + pow((event.mouseButton.y - Chip::fieldCoord[i].y), 2));
                if (distance <= 13) {
                    field[activeChip][field[activeChip].size() - 1].move(i, field[i].size());
                    field[i].push_back(field[activeChip][field[activeChip].size() - 1]);
                    field[activeChip].pop_back();
                    break;
                }
            }
        }
        activeChip = -1;
    }
}