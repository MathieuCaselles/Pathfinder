#include "PathButton.h"



PathButton::PathButton(float x, float y, float width, float height, std::function<void(Button* button)> const& callback) : Button(x, y, width, height, callback), m_pathState(PASSABLE),
m_passableColor(sf::Color::White), m_wallColor(sf::Color(58, 58, 58)), m_traversedColor(sf::Color::Yellow)
{
	m_shape.setFillColor(m_passableColor);
	m_shape.setOutlineColor(sf::Color::Red);
	m_shape.setOutlineThickness(1);
}

PathButton::~PathButton()
{
}

void PathButton::setPathState(int newPathState) {
	m_pathState = newPathState;

	switch (m_pathState)
	{
	case PASSABLE:
		m_shape.setFillColor(m_passableColor);
		break;

	case WALL:
		m_shape.setFillColor(m_wallColor);
		break;

	case TRAVERSED:
		m_shape.setFillColor(m_traversedColor);
		break;

	default:
		m_shape.setFillColor(sf::Color::Red);
		break;
	}
}


void PathButton::setButtonState(int newState) {
	if (newState >= BUTTON_IDLE && newState <= BUTTON_PRESSED)
		m_buttonState = newState;
}

