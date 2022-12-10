#include "Button.h"

#include <iostream>

Button::Button(float x, float y, float width, float height, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, std::function<void()> const& callback) :
	m_buttonState(BUTTON_IDLE), m_idleColor(idleColor), m_hoverColor(hoverColor), m_pressedColor(activeColor), m_callback(callback)
{

	m_shape.setPosition(sf::Vector2f(x, y));
	m_shape.setSize(sf::Vector2f(width, height));


	if (!m_font.loadFromFile("../../../Assets/Fonts/MinecraftFont.ttf")) {
		std::cout << "wtf" << std::endl;
		throw("ERROR::BUTTTON::COULD NOT LOAD FONT");
	}

	m_text.setFont(m_font);

	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(20);

	const float centerXOfButtons = m_shape.getPosition().x + m_shape.getGlobalBounds().width / 2.f - m_text.getGlobalBounds().width / 2.f;
	const float centerYOfButtons = m_shape.getPosition().y + m_shape.getGlobalBounds().height / 2.f - m_text.getGlobalBounds().height / 1.5f;

	m_text.setPosition(centerXOfButtons, centerYOfButtons);

	m_shape.setFillColor(m_idleColor);
}


Button::~Button()
{
}

const int& Button::getButtonState()
{
	return m_buttonState;
}

void Button::setButtonState(int newState)
{
	if (newState >= BUTTON_IDLE && newState <= BUTTON_PRESSED)
		m_buttonState = newState;
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

void Button::useCallback()
{
	m_callback();
}



