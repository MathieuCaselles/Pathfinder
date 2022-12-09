#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H
#include <SFML/Graphics.hpp>

class IGameObject;


struct IGraphicsComponent
{
    virtual ~IGraphicsComponent() = default;
    virtual void renderImplementation(IGameObject& gameObject, sf::RenderWindow& window) = 0;
};


#endif // GRAPHICSCOMPONENT_H