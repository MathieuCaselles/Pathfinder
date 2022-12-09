#include "GCExampleButton.h"

#include <iostream>

GCExampleButton::GCExampleButton()
{
}

void GCExampleButton::renderImplementation(IGameObject& gameObject, sf::RenderWindow& window)
{
	std::cout << "Render example button" << std::endl;
}
