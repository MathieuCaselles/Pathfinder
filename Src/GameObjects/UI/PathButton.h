#ifndef PATHBUTTON_H
#define PATHBUTTON_H

#include "Button.h"
#include "../../Pathfinder/Header/Pathfinder.h"

class Arrow;

enum path_states { PASSABLE = 0, WALL, TRAVERSED, START, END, WAIT_TO_LINK, LINKED, CHEKCKPOINT };

class PathButton : public Button {
public:
	PathButton(float x, float y, float width, float height, std::function<void(Button* button)> const& onleftClick, std::function<void(Button* button)> const& onRightClick);
	~PathButton();

	void setPathState(path_states newPathState);
	const path_states getPathState();
	const path_states getPreviousPathState();
	std::vector<PathButton*>& getLinkedButtons();

	void setButtonState(button_states newState) override;

	void createNode(float x, float y);

	Node<DCSManhattan>* getNode();


	void linkPathButton(PathButton* pathButton);
	void removeLinkedPathButton(PathButton* pathButton);
	void removeAllLinkedPathButtons();

	void drawArrowToButtonPathLinked(PathButton* pathButton);

private:
	path_states m_pathState;
	path_states m_previousPathState;

	const sf::Color m_passableColor;
	const sf::Color m_wallColor;
	const sf::Color m_traversedColor;
	const sf::Color m_startColor;
	const sf::Color m_endColor;
	const sf::Color m_waitToLinkColor;
	const sf::Color m_linkedColor;
	const sf::Color m_checkpointColor;

	std::vector<PathButton*> m_linkedButtons;
	std::vector<Arrow*> m_arrows;

	Node<DCSManhattan>* p_node;

};

#endif //PATHBUTTON_H