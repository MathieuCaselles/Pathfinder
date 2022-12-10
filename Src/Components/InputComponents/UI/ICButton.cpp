#include "ICButton.h"

#include "../../../GameObjects/UI/Button.h"

ICButton::ICButton(): m_callbackIsCalled(false)
{
}

void ICButton::processInputImplementation(IGameObject& gameObject, sf::Event& inputEvent)
{
	Button& button = reinterpret_cast<Button&>(gameObject);

	if (button.getButtonState() == BUTTON_PRESSED && !m_callbackIsCalled)
	{
		button.useCallback();
		m_callbackIsCalled = true;
	}
	else if (button.getButtonState() != BUTTON_PRESSED && m_callbackIsCalled) {
		m_callbackIsCalled = false;
	}
}
