#ifndef GCPATHBUTTON_H
#define GCPATHBUTTON_H

#include "GCButton.h"



struct GCPathButton : GCButton
{
	GCPathButton();
	void renderImplementation(IGameObject& gameObject, sf::RenderWindow& window) override;
};

#endif // GCPATHBUTTON_H