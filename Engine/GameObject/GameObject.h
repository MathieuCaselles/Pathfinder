#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class IScene;
namespace sf {
	class RenderWindow;
	class Event;
}

class IGameObject
{
public:
	virtual ~IGameObject() {};

	virtual void processInput(sf::Event& inputEvent) = 0;
	virtual void update(const float& deltaTime, IScene& scene) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
};

template<typename... MixinGameComponents>
class GameObject : public IGameObject, public MixinGameComponents...
{
public:
	void processInput(sf::Event& inputEvent) override
	{
		this->processInputImplementation(*this, inputEvent);
	}

	void update(const float& deltaTime, IScene& scene) override
	{
		this->updateImplementation(deltaTime, *this, scene);
	}

	void render(sf::RenderWindow& window) override
	{
		this->renderImplementation(*this, window);
	}

};

#endif // GAMEOBJECT_H