#include "ICButton.h"

#include "../../../GameObjects/UI/Button.h"
#include "../../../Scenes/DefaultScene.h"

ICButton::ICButton()
{
}

void ICButton::processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent, IScene& scene)
{
	Button& button = reinterpret_cast<Button&>(gameObject);


	button.setButtonState(BUTTON_IDLE);

	sf::RectangleShape& buttonShape = button.getEditableShape();

	if (buttonShape.getGlobalBounds().contains(scene.getMousePositionView()))
	{
		button.setButtonState(BUTTON_HOVER);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			button.setButtonState(BUTTON_PRESSED);
		}
	}

	switch (button.getButtonState())
	{
	case BUTTON_IDLE:
		buttonShape.setFillColor(button.getIdleColor());
		break;

	case BUTTON_HOVER:
		buttonShape.setFillColor(button.getHoverColor());
		break;

	case BUTTON_PRESSED:
		buttonShape.setFillColor(button.getPressedColor());
		break;

	default:
		buttonShape.setFillColor(sf::Color::Red);
		break;
	}
}
