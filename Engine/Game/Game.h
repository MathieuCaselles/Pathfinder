#ifndef GAME_H
#define GAME_H

#include "../../Tools/DesignPatterns/Singleton.h"
#include <SFML/Graphics.hpp>
#include <memory>


class Game : public Singleton<Game>
{
    friend class Singleton<Game>;

public:
    std::unique_ptr<sf::RenderWindow> m_pWindow;
    static const sf::VideoMode g_videoMode;
    static const std::string g_windowTitle;

    ~Game();
    void Run();

private:
    Game();

    void InitWindow();

    void ProcessInput();
    void Update(float deltaTime);
    void Render();

};

#endif // GAME_H