#include <SFML/Graphics.hpp>
#include "../Game/Game.h"
#include "Scene.h"

Scene::Scene(): m_window(*Game::GetInstance()->getWindow())
{
}

Scene::~Scene()
{
}


const sf::Vector2i Scene::getMousePositionScreen()
{
	return sf::Mouse::getPosition();
}

const sf::Vector2i Scene::getMousePositionWindow()
{
	return sf::Mouse::getPosition(m_window);
}

const sf::Vector2f Scene::getMousePositionView()
{
	return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
}
