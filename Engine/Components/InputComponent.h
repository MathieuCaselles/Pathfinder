#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#include <SFML/Graphics.hpp>

class IGameObject;
class IScene;

struct IInputComponent
{
    virtual ~IInputComponent() = default;
    virtual void processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent, IScene& scene) = 0;
};


#endif // INPUTCOMPONENT_H