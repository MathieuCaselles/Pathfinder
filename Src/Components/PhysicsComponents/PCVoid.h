#ifndef PCVOID_H
#define PCVOID_H

#include "../../../Engine/Components/PhysicsComponent.h"

class IGameObject;


struct PCVoid : IPhysicsComponent
{
	PCVoid();
	void updateImplementation(const float& deltaTime, IGameObject& gameObject, IScene& scene) override;

private:
	bool m_callbackIsCalled;
};

#endif // PCVOID_H