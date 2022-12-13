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
	Button(float x, float y, float width, float height, std::function<void(Button* button)> const& callback);
	Button(float x, float y, float width, float height, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, std::function<void(Button* button)> const& callback);
	~Button();

	const int& getButtonState();
	virtual void setButtonState(int newState);

	const sf::RectangleShape& getShape();
	sf::RectangleShape& getEditableShape();

	const sf::Text getText();

	const sf::Color& getIdleColor();
	const sf::Color& getHoverColor();
	const sf::Color& getPressedColor();

	void useCallback();

protected:
	void initShape(float x, float y, float width, float height);

	int m_buttonState;

	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Font m_font;


	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_pressedColor;

	std::function<void(Button* button)> m_callback;
};


#endif // BUTTON_H

