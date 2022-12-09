#include "ICExampleButton.h"

#include <iostream>

ICExampleButton::ICExampleButton()
{
}

void ICExampleButton::processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent)
{
	std::cout << "Process input example button" << std::endl;
}
