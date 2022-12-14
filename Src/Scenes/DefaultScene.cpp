#include "DefaultScene.h"

#include "../GameObjects/UI/PathButton.h"
DefaultScene::DefaultScene() : IScene(), m_startingPath(nullptr), m_arrivalPath(nullptr), m_pathStateToApply(WALL)
{
    initButtons();
    initPathButtons();
}

DefaultScene::~DefaultScene()
{
}

void DefaultScene::initButtons()
{
    addGameObjects(new Button(200, 1000, 150, 50, "Départ",
        sf::Color(255, 0, 0), sf::Color(255, 75, 75), sf::Color(180, 0, 0),
        [&](Button* button) { m_pathStateToApply = START; }));

    addGameObjects(new Button(400, 1000, 150, 50, "Arrivée",
        sf::Color(0, 255, 0), sf::Color(127, 255, 127), sf::Color(0, 150, 0),
        [&](Button* button) { m_pathStateToApply = END; }));

    addGameObjects(new Button(600, 1000, 150, 50, "Mur",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
        [&](Button* button) { m_pathStateToApply = WALL; }));

    addGameObjects(new Button(800, 1000, 150, 50, "Chemin",
        sf::Color(200, 200, 200), sf::Color(225, 225, 225), sf::Color(175, 175, 175),
        [&](Button* button) { m_pathStateToApply = PASSABLE; }));


    addGameObjects(new Button(1000, 1000, 150, 50, "Réinitialiser",
        sf::Color(0, 0, 200), sf::Color(50, 50, 200), sf::Color(0, 0, 150),
        [&](Button* button) {  resetPathButtons(); }));

    addGameObjects(new Button(1200, 1000, 150, 50, "Réinitialiser",
        sf::Color(0, 0, 200), sf::Color(50, 50, 200), sf::Color(0, 0, 150),
        [&](Button* button) {  resetPathButtons(); }));

    addGameObjects(new Button(1400, 1000, 150, 50, "Calculer",
        sf::Color(255, 218, 0), sf::Color(255, 231, 91), sf::Color(192, 164, 0),
        [&](Button* button) {  /*TODO*/; }));

}

void DefaultScene::initPathButtons()
{
    const int gridSize = 25;
    const int heightButton = 900 / gridSize;
    const int widthButton = heightButton * 1.5f;
    const int marginLeft = 300; // to center the grid
    m_pathButtons.resize(gridSize);
    std::fill(m_pathButtons.begin(), m_pathButtons.end(), std::vector<PathButton*>());

    for (size_t column = 0; column < gridSize; ++column)
    {

        for (size_t row = 0; row < gridSize; ++row)
        {
            m_pathButtons[column].push_back(new PathButton(column * widthButton + marginLeft, row * heightButton + 50, widthButton, heightButton, 
                [&](Button* pathButton) {
                    applyPathButtonState(reinterpret_cast<PathButton*>(pathButton));
                },
                [&](Button* pathButton) {
                    applyPathButtonState(reinterpret_cast<PathButton*>(pathButton));
                }));
        }
    }
}

void DefaultScene::resetPathButtons()
{

    for (auto& vectorOfPathButtons : m_pathButtons)
    {
        for (auto* pathButton : vectorOfPathButtons)
        {
            pathButton->setPathState(PASSABLE);
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

void DefaultScene::applyPathButtonState(PathButton* pathButton)
{
    pathButton->setPathState(m_pathStateToApply);

    switch (m_pathStateToApply)
    {
    case START:
        if (m_startingPath != nullptr)
        {
            m_startingPath->setPathState(PASSABLE);
        };
        m_startingPath = pathButton;
        break;

    case END:
        if (m_arrivalPath != nullptr)
        {
            m_arrivalPath->setPathState(PASSABLE);
        };
        m_arrivalPath = pathButton;
        break;
    default:
        break;
    }
}
