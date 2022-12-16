#include "Arrow.h"

Arrow::Arrow(float x, float y, float width, float height, float rotation)
{
	m_shape.setPosition(sf::Vector2f(x, y));
	m_shape.setSize(sf::Vector2f(width, height));
	m_shape.setRotation(rotation);
	m_shape.setFillColor(sf::Color(105, 0, 255));
}
