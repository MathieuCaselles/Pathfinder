#ifndef GAME_H
#define GAME_H

#include "../../Tools/DesignPatterns/Singleton.h"
#include <SFML/Graphics.hpp>

class IScene;

class Game : public Singleton<Game>
{
    friend class Singleton<Game>;

public:

    ~Game();
    void run(sf::VideoMode videoMode = sf::VideoMode(1920, 1080), std::string windowTitle = "SFML", sf::Uint32 style = sf::Style::Default);

    sf::RenderWindow* getWindow();

    template <typename... Args>
    void addScenes(Args... scenes);

    void setCurrentScene(const size_t index);

    void clearScenes();

private:
    Game();
    Game(const Game&) = delete;
    // methods
    void initWindow(sf::VideoMode videoMode = sf::VideoMode(1920, 1080), std::string windowTitle = "SFML", sf::Uint32 style = sf::Style::Default);

    void processInput();
    void update(const float& deltaTime);
    void render();


    // attributes
    sf::RenderWindow m_window;

    std::vector<IScene*> m_scenes;
    IScene* m_pCurrentScene;
};

#endif // GAME_H

template<typename ...Args>
inline void Game::addScenes(Args ...scenes)
{
    (m_scenes.push_back(scenes), ...);
}
