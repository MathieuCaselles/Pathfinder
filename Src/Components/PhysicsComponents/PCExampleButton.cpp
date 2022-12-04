#include <iostream>
#include "PCExampleButton.h"

PCExampleButton::PCExampleButton()
{
}

void PCExampleButton::updateImplementation(const float& deltaTime, IGameObject& gameObject, IScene& scene)
{
	std::cout << "Physics update example button" << std::endl;
}
