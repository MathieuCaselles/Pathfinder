#ifndef GCEXAMPLEBUTTON_H
#define GCEXAMPLEBUTTON_H

#include "../../../../Engine/Components/GraphicsComponent.h"

class IGameObject;


struct GCButton : IGraphicsComponent 
{
	GCButton();
	virtual void renderImplementation(IGameObject& gameObject, sf::RenderWindow& window) override;
};

#endif // GCEXAMPLEBUTTON_H