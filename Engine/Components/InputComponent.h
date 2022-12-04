#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

class IGameObject;

namespace sf {
    class Event;
}


struct IInputComponent
{
    virtual ~IInputComponent() = default;
    virtual void processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent) = 0;
};


#endif // INPUTCOMPONENT_H