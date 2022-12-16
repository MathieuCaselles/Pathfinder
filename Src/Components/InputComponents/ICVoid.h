#ifndef ICVOID_H
#define ICVOID_H

#include "../../../Engine/Components/InputComponent.h"

class IGameObject;


struct ICVoid : IInputComponent
{
	ICVoid();
	void processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent, IScene& scene) override;
};

#endif // ICVOID_H