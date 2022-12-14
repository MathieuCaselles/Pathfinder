#ifndef DEFAULTSCENE_H
#define DEFAULTSCENE_H
#include "../../Engine/Scene/Scene.h"
#include <SFML/Graphics.hpp>

class PathButton;
enum path_states;

class DefaultScene : public IScene
{
public:

    DefaultScene();
    ~DefaultScene();


    void processInput(sf::Event& inputEvent) override;
    void update(const float& deltaTime) override;
    void render() override;

    void applyPathButtonState(PathButton* pathButton);

private:
    void initButtons();
    void initPathButtons();

    void resetPathButtons();
    void clearPathFound();
    void clearNodes();


    void generateGraph();


    PathButton* p_startingPath;
    PathButton* p_arrivalPath;

    PathButton* p_pathToLink;

    path_states m_pathStateToApply;

    int m_gridSize;

    std::vector<std::vector<PathButton*>> m_pathButtons;

};

#endif // DEFAULTSCENE_H