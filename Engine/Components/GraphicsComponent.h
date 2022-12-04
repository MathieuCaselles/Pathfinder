#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

class IGameObject;

namespace sf {
    class RenderWindow;
}


struct IGraphicsComponent
{
    virtual ~IGraphicsComponent() = default;
    virtual void renderImplementation(IGameObject& gameObject, sf::RenderWindow& window) = 0;
};


#endif // GRAPHICSCOMPONENT_H