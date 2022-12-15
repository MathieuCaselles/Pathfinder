#ifndef BUTTON_H
#define BUTTON_H

#include <functional>

#include "../../Components/InputComponents/UI/ICButton.h"
#include "../../Components/PhysicsComponents/UI/PCButton.h"
#include "../../Components/GraphicsComponents/UI/GCButton.h"
#include "../../../Engine/GameObject/GameObject.h"


enum button_states { BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_PRESSED };


class Button: public GameObject<ICButton, PCButton, GCButton> {
public:
	Button(float x, float y, float width, float height, std::function<void(Button* button)> const& onLeftClick);
	Button(float x, float y, float width, float height, std::function<void(Button* button)> const& onLeftClick, std::function<void(Button* button)> const& onRightClick);
	Button(float x, float y, float width, float height, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, std::function<void(Button* button)> const& onLeftClick);
	~Button();

	const int& getButtonState();
	virtual void setButtonState(button_states newState);

	const sf::RectangleShape& getShape();
	sf::RectangleShape& getEditableShape();

	const sf::Text getText();

	const sf::Color& getIdleColor();
	const sf::Color& getHoverColor();
	const sf::Color& getPressedColor();

	void useOnLeftClick();
	void useOnRightClick();

protected:
	void initShape(float x, float y, float width, float height);

	button_states m_buttonState;

	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Font m_font;


	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_pressedColor;

	std::function<void(Button* button)> m_callbackOnLeftClick;
	std::function<void(Button* button)> m_callbackOnRightClick;
};


#endif // BUTTON_H

