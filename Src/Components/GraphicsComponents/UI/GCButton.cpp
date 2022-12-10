#include "GCButton.h"

#include "../../../GameObjects/UI/Button.h"


GCButton::GCButton()
{
}

void GCButton::renderImplementation(IGameObject& gameObject, sf::RenderWindow& window)
{
	Button& button = reinterpret_cast<Button&>(gameObject);

	window.draw(button.getShape());
	window.draw(button.getText());
}
