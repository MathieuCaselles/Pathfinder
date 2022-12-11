#ifndef DEFAULTSCENE_H
#define DEFAULTSCENE_H
#include "../../Engine/Scene/Scene.h"
#include <SFML/Graphics.hpp>


class DefaultScene : public IScene
{
public:

    DefaultScene();
    ~DefaultScene();

    void initButtons();

    void processInput(sf::Event& inputEvent) override;
    void update(const float& deltaTime) override;
    void render() override;

};

#endif // DEFAULTSCENE_H