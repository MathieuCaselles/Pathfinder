#ifndef PATHBUTTON_H
#define PATHBUTTON_H

#include "Button.h"

enum path_states { PASSABLE = 0, WALL, TRAVERSED };

class PathButton : public Button {
public:
	PathButton(float x, float y, float width, float height, std::function<void(Button* button)> const& callback);
	~PathButton();

	void setPathState(int newPathState);

	void setButtonState(int newState) override;

private:
	int m_pathState;

	const sf::Color m_passableColor;
	const sf::Color m_wallColor;
	const sf::Color m_traversedColor;

};

#endif //PATHBUTTON_H