#include <cassert>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Scene/Scene.h"
#include "Game.h"


Game::~Game()
{
    clearScenes();
}

void Game::run(sf::VideoMode videoMode, std::string windowTitle)
{
    assert(("m_pCurrentScene is nullptr", m_pCurrentScene != nullptr));

    initWindow(videoMode, windowTitle);

    sf::Clock DeltaTimeClock;
    float deltaTime;

    while (m_window.isOpen()) {

        deltaTime = DeltaTimeClock.restart().asSeconds();

        processInput();
        update(deltaTime);
        render();
    }
}

sf::RenderWindow* Game::getWindow()
{
    return &m_window;
}



void Game::setCurrentScene(const size_t index)
{
    m_pCurrentScene = m_scenes.at(index);
}

void Game::clearScenes()
{
    for (IScene* pScene : m_scenes)
    {
        delete pScene;
    }
    m_scenes.clear();
}



// private
Game::Game()
    : m_window(sf::RenderWindow()), m_pCurrentScene(nullptr)
{
}


void Game::initWindow(sf::VideoMode videoMode, std::string windowTitle)
{
    m_window.create(videoMode, windowTitle);
    m_window.setVerticalSyncEnabled(true);
}

void Game::processInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();

        m_pCurrentScene->processInput(event);
    }
}

void Game::update(const float& deltaTime)
{
    m_pCurrentScene->update(deltaTime);
}

void Game::render()
{
    m_window.clear();
    m_pCurrentScene->render();
    m_window.display();
}
