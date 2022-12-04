#ifndef PCEXAMPLEBUTTON_H
#define PCEXAMPLEBUTTON_H

#include "../../../Engine/Components/PhysicsComponent.h"

class IGameObject;


struct PCExampleButton : IPhysicsComponent 
{
	PCExampleButton();
	void updateImplementation(const float& deltaTime, IGameObject& gameObject, IScene& scene) override;
};

#endif // PCEXAMPLEBUTTON_H