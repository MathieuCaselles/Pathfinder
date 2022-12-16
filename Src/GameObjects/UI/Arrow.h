#ifndef ARROW_H
#define ARROW_H

#include "../../Components/InputComponents/ICVoid.h"
#include "../../Components/PhysicsComponents/PCVoid.h"
#include "../../Components/GraphicsComponents/UI/GCArrow.h"
#include "../../../Engine/GameObject/GameObject.h"

class Arrow : public GameObject<ICVoid, PCVoid, GCArrow> {
public:
	Arrow(float x, float y, float width, float height, float rotation);



private:

	sf::RectangleShape m_shape;
};

#endif ARROW_H