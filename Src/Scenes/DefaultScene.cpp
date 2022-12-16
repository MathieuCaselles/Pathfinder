#include "DefaultScene.h"

#include "../GameObjects/UI/PathButton.h"

DefaultScene::DefaultScene() : IScene(), p_startingPath(nullptr), p_arrivalPath(nullptr), p_pathToLink(nullptr), m_pathStateToApply(WALL)
{
    initButtons();
    initPathButtons();
}

DefaultScene::~DefaultScene()
{
}

void DefaultScene::initButtons()
{
    addGameObjects(new Button(450, 1020, 150, 50, "Départ",
        sf::Color(255, 0, 0), sf::Color(255, 75, 75), sf::Color(180, 0, 0),
        [&](Button* button) { m_pathStateToApply = START; }));

    addGameObjects(new Button(650, 1020, 150, 50, "Arrivée",
        sf::Color(0, 255, 0), sf::Color(127, 255, 127), sf::Color(0, 150, 0),
        [&](Button* button) { m_pathStateToApply = END; }));

    addGameObjects(new Button(850, 1020, 150, 50, "Mur/Chemin",
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
        [&](Button* button) { m_pathStateToApply = PASSABLE; }));

    addGameObjects(new Button(1050, 1020, 150, 50, "Checkpoint",
        sf::Color(255, 170, 0), sf::Color(255, 220, 75), sf::Color(180, 100, 0),
        [&](Button* button) { m_pathStateToApply = CHEKCKPOINT; }));

    addGameObjects(new Button(1250, 1020, 150, 50, "Réinitialiser",
        sf::Color(0, 0, 200), sf::Color(50, 50, 200), sf::Color(0, 0, 150),
        [&](Button* button) {  resetPathButtons(); }));

    addGameObjects(new Button(1450, 1020, 150, 50, "Calculer",
        sf::Color(255, 218, 0), sf::Color(255, 231, 91), sf::Color(192, 164, 0),
        [&](Button* button) {  /*TODO*/; }));

}

void DefaultScene::initPathButtons()
{
    const int gridSize = 30;
    const int heightButton = 1000 / gridSize;
    const int widthButton = 1920 / gridSize;

    m_pathButtons.resize(gridSize);
    std::fill(m_pathButtons.begin(), m_pathButtons.end(), std::vector<PathButton*>());

    for (size_t column = 0; column < gridSize; ++column)
    {

        for (size_t row = 0; row < gridSize; ++row)
        {
            m_pathButtons[column].push_back(new PathButton(column * widthButton, row * heightButton, widthButton, heightButton,
                [&](Button* pathButton) {
                    applyPathButtonState(reinterpret_cast<PathButton*>(pathButton));
                },
                [&](Button* pathButton) {
                    if (p_pathToLink != nullptr)
                    {
                        p_pathToLink->setPathState(p_pathToLink->getPreviousPathState());
                    }
                    PathButton* pPathButton = reinterpret_cast<PathButton*>(pathButton);
                    pPathButton->setPathState(WAIT_TO_LINK);
                    p_pathToLink = pPathButton;
                    m_pathStateToApply = LINKED;
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

    if (inputEvent.key.code == sf::Keyboard::Escape)
        m_window.close();

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

    switch (m_pathStateToApply)
    {
    case START:
        if (p_startingPath != nullptr)
        {
            p_startingPath->setPathState(p_startingPath->getPreviousPathState());
        };
        p_startingPath = pathButton;
        pathButton->setPathState(m_pathStateToApply);
        break;

    case END:
        if (p_arrivalPath != nullptr)
        {
            p_arrivalPath->setPathState(p_arrivalPath->getPreviousPathState());
        };
        p_arrivalPath = pathButton;
        pathButton->setPathState(m_pathStateToApply);
        break;

    case PASSABLE:
    case WALL:
        pathButton->setPathState(pathButton->getPathState() == PASSABLE ? WALL : PASSABLE);
        break;

    case LINKED:
        p_pathToLink->linkPathButton(pathButton);
        p_pathToLink->setPathState(m_pathStateToApply);
        pathButton->setPathState(m_pathStateToApply);
        p_pathToLink = nullptr;
        break;

    case CHEKCKPOINT:
        pathButton->setPathState(m_pathStateToApply);
        break;


    default:
        break;
    }
    m_pathStateToApply = PASSABLE;
}
