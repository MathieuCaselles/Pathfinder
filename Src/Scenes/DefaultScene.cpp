#include "DefaultScene.h"

#include <iostream>
#include "../GameObjects/UI/Button.h"
DefaultScene::DefaultScene(): IScene()
{
    initButtons();
}

DefaultScene::~DefaultScene()
{
}

void DefaultScene::initButtons()
{
    addGameObjects(new Button(500, 1000, 150, 50, "Départ",
        sf::Color(255, 0, 0), sf::Color(255, 75, 75), sf::Color(180, 0, 0),
        []() {  std::cout << "Mode ajout de point de départ." << std::endl; }));

    addGameObjects(new Button(700, 1000, 150, 50, "Arrivée",
        sf::Color(0, 255, 0), sf::Color(127, 255, 127), sf::Color(0, 150, 0),
        []() {  std::cout << "Mode ajout d'arrivée" << std::endl; }));

    addGameObjects(new Button(900, 1000, 150, 50, "Mur",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
        []() {  std::cout << "Mode ajout de mur" << std::endl; }));

    addGameObjects(new Button(1100, 1000, 150, 50, "Réinitialiser",
        sf::Color(0, 0, 200), sf::Color(50, 50, 200), sf::Color(0, 0, 150),
        []() {  std::cout << "Tout a été reset" << std::endl; }));

    addGameObjects(new Button(1300, 1000, 150, 50, "Calculer",
        sf::Color(255, 218, 0), sf::Color(255, 231, 91), sf::Color(192, 164, 0),
        []() {  std::cout << "Pathfinding lancé !" << std::endl; }));
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
