#ifndef GCEXAMPLEBUTTON_H
#define GCEXAMPLEBUTTON_H

#include "../../../Engine/Components/GraphicsComponent.h"

class IGameObject;


struct GCExampleButton : IGraphicsComponent 
{
	GCExampleButton();
	void renderImplementation(IGameObject& gameObject, sf::RenderWindow& window) override;
};

#endif // GCEXAMPLEBUTTON_H