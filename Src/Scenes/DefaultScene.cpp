#include "DefaultScene.h"
#include <iostream>
#include "../GameObjects/UI/PathButton.h"

DefaultScene::DefaultScene() : IScene(), p_startingPath(nullptr), p_arrivalPath(nullptr), p_pathToLink(nullptr), m_pathStateToApply(WALL), m_gridSize(30)
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

    addGameObjects(new Button(1450, 1020, 150, 50, "Reset Chemin",
        sf::Color(0, 0, 200), sf::Color(50, 50, 200), sf::Color(0, 0, 150),
        [&](Button* button) {  clearPathFound(); }));

    addGameObjects(new Button(1650, 1020, 150, 50, "Calculer",
        sf::Color(255, 218, 0), sf::Color(255, 231, 91), sf::Color(192, 164, 0),
        [&](Button* button) {

            generateGraph();

            std::vector<Node<DCSManhattan>*>* result = pathfinder<DCSManhattan>(*p_startingPath->getNode(), *p_arrivalPath->getNode());

            if (result != nullptr)
            {
                for (Node<DCSManhattan>* node : *result)
                {
                    PathButton* tile = node->getTile();
                    if (tile->getPathState() == PASSABLE)
                    {
                        tile->setPathState(TRAVERSED);
                    }

                }
            }

            delete result;
            result = nullptr;

            clearNodes();
       
        }));

}

void DefaultScene::initPathButtons()
{
    const int heightButton = 1000 / m_gridSize;
    const int widthButton = 1920 / m_gridSize;

    m_pathButtons.resize(m_gridSize);
    std::fill(m_pathButtons.begin(), m_pathButtons.end(), std::vector<PathButton*>());

    for (size_t y = 0; y < m_gridSize; ++y)
    {

        for (size_t x = 0; x < m_gridSize; ++x)
        {
            m_pathButtons[y].push_back(new PathButton(x * widthButton, y * heightButton, widthButton, heightButton,
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

void DefaultScene::clearPathFound()
{
    for (auto& vectorOfPathButtons : m_pathButtons)
    {
        for (auto* pathButton : vectorOfPathButtons)
        {
            if (pathButton->getPathState() == TRAVERSED)
            {
                pathButton->setPathState(PASSABLE);
            }
        }
    }
}

void DefaultScene::clearNodes()
{
    for (auto& vectorOfPathButtons : m_pathButtons)
    {
        for (auto* pathButton : vectorOfPathButtons)
        {
            pathButton->deleteNote();
        }
    }
}

void DefaultScene::generateGraph()
{
    for (size_t y = 0; y < m_gridSize; ++y)
    {
        for (size_t x = 0; x < m_gridSize; ++x)
        {
            PathButton* pathButton = m_pathButtons.at(y).at(x);

            if (pathButton->getPathState() != WALL)
            {
                pathButton->createNode(x, y);
            }
        }
    }

    for (size_t y = 0; y < m_gridSize; ++y)
    {
        for (size_t x = 0; x < m_gridSize; ++x)
        {
            PathButton* pathButton = m_pathButtons.at(y).at(x);
            Node<DCSManhattan>* node = pathButton->getNode();

            if (node == nullptr)
            {
                continue;
            }

            if (x > 0) // Add left
            {
                node->addNeighbor(m_pathButtons.at(y).at(x - 1)->getNode());
            }
            if (x < m_gridSize - 1) // Add right 
            {
                node->addNeighbor(m_pathButtons.at(y).at(x + 1)->getNode());
            }
            if (y > 0)// Add top 
            {
                node->addNeighbor(m_pathButtons.at(y - 1).at(x)->getNode());
            }
            if (y < m_gridSize - 1)// Add bottom 
            {
                node->addNeighbor(m_pathButtons.at(y + 1).at(x)->getNode());
            }
            if (x > 0 && y > 0) // add top-left
            {
                node->addNeighbor(m_pathButtons.at(y - 1).at(x - 1)->getNode());
            }
            if (x < m_gridSize - 1 && y > 0) // add top-right
            {
                node->addNeighbor(m_pathButtons.at(y - 1).at(x + 1)->getNode());
            }
            if (x < m_gridSize - 1 && y < m_gridSize - 1) // add bottom-right
            {
                node->addNeighbor(m_pathButtons.at(y + 1).at(x + 1)->getNode());
            }
            if (x > 0 && y < m_gridSize - 1) // add bottom-left
            {
                node->addNeighbor(m_pathButtons.at(y + 1).at(x - 1)->getNode());
            }


            if (pathButton->getPathState() == LINKED)
            {
                for (PathButton* pathButtonLinked : pathButton->getLinkedButtons())
                {
                    node->addNeighbor(pathButtonLinked->getNode());
                }
            }
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
