#ifndef DEFAULTSCENE_H
#define DEFAULTSCENE_H
#include "../../Engine/Scene/Scene.h"


class DefaultScene : public Scene
{
public:

    DefaultScene();
    virtual ~DefaultScene();


    virtual void processInput(sf::Event inputEvent) override;
    virtual void update(float deltaTime) override;
    virtual void render() override;

};

#endif // DEFAULTSCENE_H