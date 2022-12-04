#ifndef ICEXAMPLEBUTTON_H
#define ICEXAMPLEBUTTON_H

#include "../../../Engine/Components/InputComponent.h"

class IGameObject;


struct ICExampleButton : IInputComponent 
{
	ICExampleButton();
	void processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent) override;
};

#endif // ICEXAMPLEBUTTON_H