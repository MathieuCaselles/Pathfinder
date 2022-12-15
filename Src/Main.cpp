#include <SFML/Graphics.hpp>
#include "../Engine/Game/Game.h"
#include "Scenes/DefaultScene.h"
#include "Scenes/SceneEnum.h"
int main()
{
    Game* game = Game::GetInstance();
    game->addScenes(new DefaultScene());
    game->setCurrentScene(ScenesEnum::DEFAULT_SCENE);

    game->run(sf::VideoMode(1920, 1080), "Pathfinder", sf::Style::Fullscreen);

    return 0;
}