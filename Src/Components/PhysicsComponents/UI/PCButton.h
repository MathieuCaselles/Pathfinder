#ifndef PCEXAMPLEBUTTON_H
#define PCEXAMPLEBUTTON_H

#include "../../../../Engine/Components/PhysicsComponent.h"

class IGameObject;


struct PCButton : IPhysicsComponent
{
	PCButton();
	void updateImplementation(const float& deltaTime, IGameObject& gameObject, IScene& scene) override;

private:
	bool m_callbackIsCalled;
};

#endif // PCEXAMPLEBUTTON_H