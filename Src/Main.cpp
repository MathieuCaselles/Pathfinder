#include <SFML/Graphics.hpp>
#include "../Engine/Game/Game.h"
#include "Scenes/DefaultScene.h"
#include "Scenes/SceneEnum.h"

#include "Pathfinder/Header/Pathfinder.h"

int main()
{
    /*
    Node<DCSManhattan> startNode;
    Node<DCSManhattan> aNode;
    Node<DCSManhattan> bNode;
    Node<DCSManhattan> cNode;
    Node<DCSManhattan> goalNode;

    startNode.addNeighbor(&aNode);
    aNode.addNeighbor(&bNode);
    bNode.addNeighbor(&cNode);
    cNode.addNeighbor(&goalNode);

    std::vector<Node<DCSManhattan>*>* rL = pathfinder<DCSManhattan>(startNode, goalNode);
    */
    
    Game* game = Game::GetInstance();
    game->addScenes(new DefaultScene());
    game->setCurrentScene(ScenesEnum::DEFAULT_SCENE);

    game->run(sf::VideoMode(1920, 1080), "Pathfinder", sf::Style::Fullscreen);
    
    return 0;
}

// PAS OUBLIER LE DELETE DU RESULT
// DEMANDER POUR LA MAGIE NOIRE