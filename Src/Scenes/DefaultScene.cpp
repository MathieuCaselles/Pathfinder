#include <SFML/Graphics.hpp>
#include "DefaultScene.h"

DefaultScene::DefaultScene(): Scene()
{
}

DefaultScene::~DefaultScene()
{
}
void DefaultScene::processInput(sf::Event inputEvent)
{
}

void DefaultScene::update(float deltaTime)
{
}

void DefaultScene::render()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    m_window.draw(shape);
}
