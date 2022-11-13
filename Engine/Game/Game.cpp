#include "Game.h"



Game::~Game()
{
    // TODO delete scenes ?
}

void Game::Run()
{
    sf::Clock DeltaTimeClock;
    float deltaTime;

    while (m_pWindow->isOpen()) {

        deltaTime = DeltaTimeClock.restart().asSeconds();

        ProcessInput();
        Update(deltaTime);
        Render();
    }
}



// private
Game::Game()
    : m_pWindow(std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Pathfinder"))
{
    // TODO init scenes ?
    std::cout << "ça marche" << std::endl;
}


void Game::InitWindow()
{
    m_pWindow->setVerticalSyncEnabled(true);
}

void Game::ProcessInput()
{

    // TODO signal pattern
    sf::Event event;
    while (m_pWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_pWindow->close();
    }
}

void Game::Update(float deltaTime)
{
    // TODO update scenes
}

void Game::Render()
{
    m_pWindow->clear();

    // TODO render scenes

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    m_pWindow->draw(shape);

    m_pWindow->display();
}
