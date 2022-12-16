#ifndef GCVOID_H
#define GCVOID_H

#include "../../../Engine/Components/GraphicsComponent.h"

class IGameObject;


struct GCVoid : IGraphicsComponent
{
	GCVoid();
	void renderImplementation(IGameObject& gameObject, sf::RenderWindow& window) override;
};

#endif // GCVOID_H