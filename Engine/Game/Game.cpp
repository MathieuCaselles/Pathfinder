#include "Game.h"



Game::~Game()
{
    // TODO delete scenes ?
}

void Game::Run(sf::VideoMode videoMode, std::string windowTitle)
{
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



// private
Game::Game()
    : m_window(sf::RenderWindow())
{
    // TODO init scenes ?
    std::cout << "ça marche" << std::endl;
}


void Game::initWindow(sf::VideoMode videoMode, std::string windowTitle)
{
    m_window.create(videoMode, windowTitle);
    m_window.setVerticalSyncEnabled(true);
}

void Game::processInput()
{

    // TODO signal pattern
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::update(float deltaTime)
{
    // TODO update scenes
}

void Game::render()
{
    m_window.clear();

    // TODO render scenes

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    m_window.draw(shape);

    m_window.display();
}
