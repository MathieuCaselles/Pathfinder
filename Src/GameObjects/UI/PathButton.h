#ifndef PATHBUTTON_H
#define PATHBUTTON_H

#include "Button.h"

enum path_states { PASSABLE = 0, WALL, TRAVERSED, START, END };

class PathButton : public Button {
public:
	PathButton(float x, float y, float width, float height, std::function<void(Button* button)> const& onleftClick, std::function<void(Button* button)> const& onRightClick);
	~PathButton();

	void setPathState(path_states newPathState);

	void setButtonState(button_states newState) override;

	void linkPathButton(PathButton* pathButton);

private:
	path_states m_pathState;

	const sf::Color m_passableColor;
	const sf::Color m_wallColor;
	const sf::Color m_traversedColor;
	const sf::Color m_startColor;
	const sf::Color m_endColor;

	std::vector<PathButton*> linkedButtons;

};

#endif //PATHBUTTON_H