#ifndef GAME_H
#define GAME_H

#include "../../Tools/DesignPatterns/Singleton.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Game : public Singleton<Game>
{
    friend class Singleton<Game>;

public:
    sf::RenderWindow m_window;

    ~Game();
    void Run(sf::VideoMode videoMode = sf::VideoMode(1920, 1080), std::string windowTitle = "SFML");

private:
    Game();

    void initWindow(sf::VideoMode videoMode = sf::VideoMode(1920, 1080), std::string windowTitle = "SFML");

    void processInput();
    void update(float deltaTime);
    void render();

};

#endif // GAME_H