#include "PathButton.h"


PathButton::PathButton(float x, float y, float width, float height, std::function<void(Button* button)> const& onLeftClick, std::function<void(Button* button)> const& onRightClick) : Button(x, y, width, height, onLeftClick, onRightClick), m_pathState(PASSABLE),
m_passableColor(sf::Color::White), m_wallColor(sf::Color(58, 58, 58)), m_traversedColor(sf::Color::Yellow), m_startColor(sf::Color::Red), m_endColor(sf::Color::Green)
{
	m_shape.setFillColor(m_passableColor);
	m_shape.setOutlineColor(sf::Color::Red);
	m_shape.setOutlineThickness(1);
}

PathButton::~PathButton()
{
}

void PathButton::setPathState(path_states newPathState) {
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

	case START:
		m_shape.setFillColor(m_startColor);
		break;

	case END:
		m_shape.setFillColor(m_endColor);
		break;


	default:
		m_shape.setFillColor(sf::Color::Magenta);
		break;
	}
}


void PathButton::setButtonState(button_states newState) {
	m_buttonState = newState;
}

void PathButton::linkPathButton(PathButton* pathButton)
{
	if (pathButton == nullptr || pathButton == this)
	{
		return;
	}
}

