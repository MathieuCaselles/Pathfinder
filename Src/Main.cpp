#include "../Engine/Game/Game.h"




int main()
{
    Game* game = Game::GetInstance();
    game->Run(sf::VideoMode(1920, 1080), "Pathfinder");

    return 0;
}