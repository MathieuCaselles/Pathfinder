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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			button.setButtonState(BUTTON_PRESSED);
		}
	}

}
