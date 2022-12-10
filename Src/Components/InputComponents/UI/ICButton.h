#ifndef ICEXAMPLEBUTTON_H
#define ICEXAMPLEBUTTON_H

#include "../../../../Engine/Components/InputComponent.h"

class IGameObject;


struct ICButton : IInputComponent 
{
	ICButton();
	void processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent) override;

private: 
	bool m_callbackIsCalled;
};

#endif // ICEXAMPLEBUTTON_H