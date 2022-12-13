#include "DefaultScene.h"

#include <iostream>
#include "../GameObjects/UI/PathButton.h"
DefaultScene::DefaultScene(): IScene()
{
    initButtons();
    initPathButtons();
}

DefaultScene::~DefaultScene()
{
}

void DefaultScene::initButtons()
{
    addGameObjects(new Button(500, 1000, 150, 50, "Départ",
        sf::Color(255, 0, 0), sf::Color(255, 75, 75), sf::Color(180, 0, 0),
        [](Button* button) {  std::cout << "Mode ajout de point de départ." << std::endl; }));

    addGameObjects(new Button(700, 1000, 150, 50, "Arrivée",
        sf::Color(0, 255, 0), sf::Color(127, 255, 127), sf::Color(0, 150, 0),
        [](Button* button) {  std::cout << "Mode ajout d'arrivée" << std::endl; }));

    addGameObjects(new Button(900, 1000, 150, 50, "Mur",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
        [](Button* button) {  std::cout << "Mode ajout de mur" << std::endl; }));

    addGameObjects(new Button(1100, 1000, 150, 50, "Réinitialiser",
        sf::Color(0, 0, 200), sf::Color(50, 50, 200), sf::Color(0, 0, 150),
        [](Button* button) {  std::cout << "Tout a été reset" << std::endl; }));

    addGameObjects(new Button(1300, 1000, 150, 50, "Calculer",
        sf::Color(255, 218, 0), sf::Color(255, 231, 91), sf::Color(192, 164, 0),
        [](Button* button) {  std::cout << "Pathfinding lancé !" << std::endl; }));
}

void DefaultScene::initPathButtons()
{
    const int gridSize = 3;
    const int sizeButton = 900 / gridSize;
    m_pathButtons.resize(gridSize);
    std::fill(m_pathButtons.begin(), m_pathButtons.end(), std::vector<PathButton*>());

    for (size_t column = 0; column < gridSize; ++column)
    {

        for (size_t row = 0; row < gridSize; ++row)
        {
            m_pathButtons[column].push_back(new PathButton(column * sizeButton + 500, row * sizeButton + 50, sizeButton, sizeButton, [](Button* pathButton) { reinterpret_cast<PathButton*>(pathButton)->setPathState(WALL);  }));
        }
    }
}

void DefaultScene::processInput(sf::Event& inputEvent)
{
    IScene::processInput(inputEvent);

    for (std::vector<PathButton*>& pPathButtonVector : m_pathButtons)
    {
        for (PathButton* pPathButton : pPathButtonVector)
        {
            pPathButton->processInput(inputEvent, *this);
        }
    }
}

void DefaultScene::update(const float& deltaTime)
{
    IScene::update(deltaTime);
    for (std::vector<PathButton*>& pPathButtonVector : m_pathButtons)
    {
        for (PathButton* pPathButton : pPathButtonVector)
        {
            pPathButton->update(deltaTime, *this);
        }
    }
}

void DefaultScene::render()
{
    IScene::render();
    for (std::vector<PathButton*>& pPathButtonVector : m_pathButtons)
    {
        for (PathButton* pPathButton : pPathButtonVector)
        {
            pPathButton->render(m_window);
        }
    }
}
