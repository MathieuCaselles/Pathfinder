#include "Button.h"

Button::Button(float x, float y, float width, float height, std::function<void(Button* button)> const& onLeftClick) :
	m_buttonState(BUTTON_IDLE), m_idleColor(sf::Color::White), m_hoverColor(sf::Color::White), m_pressedColor(sf::Color::White), m_callbackOnLeftClick(onLeftClick), m_callbackOnRightClick(nullptr)
{
	initShape(x, y, width, height);
}

Button::Button(float x, float y, float width, float height, std::function<void(Button* button)> const& onLeftClick , std::function<void(Button* button)> const& onRightClick) :
	m_buttonState(BUTTON_IDLE), m_idleColor(sf::Color::White), m_hoverColor(sf::Color::White), m_pressedColor(sf::Color::White), m_callbackOnLeftClick(onLeftClick), m_callbackOnRightClick(onRightClick)
{
	initShape(x, y, width, height);
}

Button::Button(float x, float y, float width, float height, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, std::function<void(Button* button)> const& onLeftClick) :
	m_buttonState(BUTTON_IDLE), m_idleColor(idleColor), m_hoverColor(hoverColor), m_pressedColor(activeColor), m_callbackOnLeftClick(onLeftClick), m_callbackOnRightClick(nullptr)
{

	initShape(x, y, width, height);


	if (!m_font.loadFromFile("../../../Assets/Fonts/MinecraftFont.ttf")) {
		throw("ERROR::BUTTTON::COULD NOT LOAD FONT");
	}

	m_text.setFont(m_font);

	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(20);

	const float centerXOfButtons = m_shape.getPosition().x + m_shape.getGlobalBounds().width / 2.f - m_text.getGlobalBounds().width / 2.f;
	const float centerYOfButtons = m_shape.getPosition().y + m_shape.getGlobalBounds().height / 2.f - m_text.getGlobalBounds().height / 1.5f;

	m_text.setPosition(centerXOfButtons, centerYOfButtons);

}


Button::~Button()
{
}

const int& Button::getButtonState()
{
	return m_buttonState;
}

void Button::setButtonState(button_states newState)
{
	m_buttonState = newState;

	switch (m_buttonState)
	{
	case BUTTON_IDLE:
		m_shape.setFillColor(m_idleColor);
		break;

	case BUTTON_HOVER:
		m_shape.setFillColor(m_hoverColor);
		break;

	case BUTTON_PRESSED:
		m_shape.setFillColor(m_pressedColor);
		break;

	default:
		m_shape.setFillColor(sf::Color::Red);
		break;
	}
}

const sf::RectangleShape& Button::getShape()
{
	return m_shape;
}

sf::RectangleShape& Button::getEditableShape()
{
	return m_shape;
}

const sf::Text Button::getText()
{
	return m_text;
}

const sf::Color& Button::getIdleColor()
{
	return m_idleColor;
}

const sf::Color& Button::getHoverColor()
{
	return m_hoverColor;
}

const sf::Color& Button::getPressedColor()
{
	return m_pressedColor;
}

void Button::useOnLeftClick()
{
	m_callbackOnLeftClick(this);
}

void Button::useOnRightClick()
{
	if (m_callbackOnRightClick!= nullptr)
	{
		m_callbackOnRightClick(this);
	}
}

void Button::initShape(float x, float y, float width, float height)
{
	m_shape.setPosition(sf::Vector2f(x, y));
	m_shape.setSize(sf::Vector2f(width, height));
	m_shape.setFillColor(m_idleColor);
}


