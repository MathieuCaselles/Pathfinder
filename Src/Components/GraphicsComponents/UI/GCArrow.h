#ifndef GCARROW_H
#define GCARROW_H

#include "../../../../Engine/Components/GraphicsComponent.h"

class IGameObject;


struct GCArrow : IGraphicsComponent
{
	GCArrow();
	void renderImplementation(IGameObject& gameObject, sf::RenderWindow& window) override;
};

#endif // GCARROW_H