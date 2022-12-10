#include "DefaultScene.h"

#include <iostream>
#include "../GameObjects/UI/Button.h"
DefaultScene::DefaultScene(): IScene()
{
    addGameObjects(new Button(1500, 400, 150, 50, "Yolo",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
        []() {  std::cout << "callback activé ! " << std::endl; }));
}

DefaultScene::~DefaultScene()
{
}

void DefaultScene::processInput(sf::Event& inputEvent)
{
    IScene::processInput(inputEvent);
}

void DefaultScene::update(const float& deltaTime)
{
    IScene::update(deltaTime);
}

void DefaultScene::render()
{
    IScene::render();
}
