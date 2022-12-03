#ifndef SCENE_H
#define SCENE_H

class Scene 
{
public:

    Scene();
    virtual ~Scene();

    virtual const sf::Vector2i getMousePositionScreen();
    virtual const sf::Vector2i getMousePositionWindow();
    virtual const sf::Vector2f getMousePositionView();

    virtual void processInput(sf::Event inputEvent) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& m_window;
};

#endif // SCENE_H