#ifndef ICEXAMPLEBUTTON_H
#define ICEXAMPLEBUTTON_H

#include "../../../../Engine/Components/InputComponent.h"

class IGameObject;


struct ICButton : IInputComponent 
{
	ICButton();
	void processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent, IScene& scene) override;
};

#endif // ICEXAMPLEBUTTON_H