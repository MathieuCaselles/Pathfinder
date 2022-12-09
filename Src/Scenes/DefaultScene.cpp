#include "DefaultScene.h"

#include "../GameObjects/ExampleButton.h"
DefaultScene::DefaultScene(): IScene()
{
    addGameObjects(new ExampleButton);
}

DefaultScene::~DefaultScene()
{
}

void DefaultScene::processInput(sf::Event& inputEvent)
{
}

void DefaultScene::update(const float& deltaTime)
{
}

void DefaultScene::render()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    m_window.draw(shape);
}
