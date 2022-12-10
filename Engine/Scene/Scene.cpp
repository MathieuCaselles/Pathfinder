#include "Scene.h"

#include "../Game/Game.h"
#include "../GameObject/GameObject.h"

IScene::IScene(): m_window(*Game::GetInstance()->getWindow())
{
}

IScene::~IScene()
{
	clearGameObjects();
}


const sf::Vector2i IScene::getMousePositionScreen()
{
	return sf::Mouse::getPosition();
}

const sf::Vector2i IScene::getMousePositionWindow()
{
	return sf::Mouse::getPosition(m_window);
}

const sf::Vector2f IScene::getMousePositionView()
{
	return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
}

void IScene::processInput(sf::Event& inputEvent)
{
	for (IGameObject* pGameObject : m_gameObjects)
	{
		pGameObject->processInput(inputEvent, *this);
	}
}

void IScene::update(const float& deltaTime)
{
	for (IGameObject* pGameObject : m_gameObjects)
	{
		pGameObject->update(deltaTime, *this);
	}
}

void IScene::render()
{
	for (IGameObject* pGameObject : m_gameObjects)
	{
		pGameObject->render(m_window);
	}
}




IGameObject* IScene::getGameObject(const size_t index)
{
	return m_gameObjects.at(index);
}

std::vector<IGameObject*>& IScene::getGameObjects()
{
	return m_gameObjects;
}

void IScene::clearGameObjects()
{
	for (IGameObject* pGameObject : m_gameObjects)
	{
		delete pGameObject;
	}
	m_gameObjects.clear();
}
