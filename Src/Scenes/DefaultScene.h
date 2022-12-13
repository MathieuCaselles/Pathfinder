#ifndef DEFAULTSCENE_H
#define DEFAULTSCENE_H
#include "../../Engine/Scene/Scene.h"
#include <SFML/Graphics.hpp>

class PathButton;

class DefaultScene : public IScene
{
public:

    DefaultScene();
    ~DefaultScene();


    void processInput(sf::Event& inputEvent) override;
    void update(const float& deltaTime) override;
    void render() override;

private:
    void initButtons();
    void initPathButtons();

    std::vector<std::vector<PathButton*>> m_pathButtons;

};

#endif // DEFAULTSCENE_H