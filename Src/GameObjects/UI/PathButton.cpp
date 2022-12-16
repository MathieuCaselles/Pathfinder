#include "PathButton.h"
#include "Arrow.h"
#include "../../../Tools/MathUtils.h"

PathButton::PathButton(float x, float y, float width, float height, std::function<void(Button* button)> const& onLeftClick, std::function<void(Button* button)> const& onRightClick) : Button(x, y, width, height, onLeftClick, onRightClick),
m_pathState(PASSABLE), m_previousPathState(PASSABLE), m_passableColor(sf::Color::White), m_wallColor(sf::Color(58, 58, 58)), m_traversedColor(sf::Color::Yellow), m_startColor(sf::Color::Red),
m_endColor(sf::Color::Green), m_waitToLinkColor(sf::Color(184, 134, 255)), m_linkedColor(sf::Color(105, 0, 255)), m_checkpointColor(sf::Color(255, 170, 0)), p_node(nullptr)
{
	m_shape.setFillColor(m_passableColor);
	m_shape.setOutlineColor(sf::Color::Red);
	m_shape.setOutlineThickness(1);
}

PathButton::~PathButton()
{
}

void PathButton::setPathState(path_states newPathState) {
	m_previousPathState = m_pathState;
	m_pathState = newPathState;

	if (m_previousPathState == LINKED && m_pathState != LINKED && m_pathState != WAIT_TO_LINK)
	{
		removeAllLinkedPathButtons();
		m_previousPathState = getPreviousPathState(); // To avoid switching back to LINK when the linked buttonsPaths have been unlinked
	}


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

	case WAIT_TO_LINK:
		m_shape.setFillColor(m_waitToLinkColor);
		break;

	case LINKED:
		m_shape.setFillColor(m_linkedColor);
		break;

	case CHEKCKPOINT:
		m_shape.setFillColor(m_checkpointColor);
		break;

	default:
		m_shape.setFillColor(sf::Color::Magenta);
		break;
	}

}

const path_states PathButton::getPathState()
{
	return m_pathState;
}

const path_states PathButton::getPreviousPathState()
{
	if (m_previousPathState != WALL && m_previousPathState != PASSABLE && m_previousPathState != CHEKCKPOINT)
		m_previousPathState = PASSABLE;
	return m_previousPathState;
}

std::vector<PathButton*>& PathButton::getLinkedButtons()
{
	return m_linkedButtons;
}


void PathButton::setButtonState(button_states newState) {
	m_buttonState = newState;
}

void PathButton::createNode(float x, float y)
{
	p_node = new Node<DCSManhattan>(this, x, y);
}

void PathButton::deleteNote()
{
	delete p_node;
	p_node = nullptr;
}

Node<DCSManhattan>* PathButton::getNode()
{
	return p_node;
}

void PathButton::linkPathButton(PathButton* pathButton)
{
	if (pathButton == nullptr || pathButton == this)
	{
		return;
	}

	auto it = std::find(m_linkedButtons.begin(), m_linkedButtons.end(), pathButton);
	if (it != m_linkedButtons.end())
		return; // duplicates prohibited

	m_linkedButtons.push_back(pathButton);
}

void PathButton::removeLinkedPathButton(PathButton* pathButton)
{

	auto it = std::find(m_linkedButtons.begin(), m_linkedButtons.end(), pathButton);
	if (it == m_linkedButtons.end())
		return; // not found

	m_linkedButtons.erase(it);


	if (m_linkedButtons.empty())
		setPathState(PASSABLE);

}

void PathButton::removeAllLinkedPathButtons()
{
	for (PathButton* linkedPathButton : m_linkedButtons)
	{
		linkedPathButton->removeLinkedPathButton(this);
	}

	m_linkedButtons.clear();
}

void PathButton::drawArrowToButtonPathLinked(PathButton* pathButton)
{

	const sf::Vector2f shapeStart = m_shape.getPosition();
	const sf::Vector2f shapeEnd = pathButton->getShape().getPosition();
	const float length = getDistanceBetween2Points(Vector2f(shapeStart.x, shapeStart.y), Vector2f(shapeEnd.x, shapeEnd.y));
	Arrow* arrow = new Arrow(shapeStart.x, shapeStart.y, length, 5, 0);

	m_arrows.push_back(arrow);
}

