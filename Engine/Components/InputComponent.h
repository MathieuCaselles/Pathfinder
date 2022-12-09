#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#include <SFML/Graphics.hpp>

class IGameObject;

struct IInputComponent
{
    virtual ~IInputComponent() = default;
    virtual void processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent) = 0;
};


#endif // INPUTCOMPONENT_H