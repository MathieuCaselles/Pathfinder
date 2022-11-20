#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>


class IScene :
{
public:

    IScene();
    ~IScene();



    virtual void void processInput() = 0;
    void update(float deltaTime);
    void render();

};

#endif // SCENE_H