#ifndef EXAMPLEBUTTON_H
#define EXAMPLEBUTTON_H
#include "../../Engine/GameObject/GameObject.h"

#include "../Components/InputComponents/ICExampleButton.h"
#include "../Components/PhysicsComponents/PCExampleButton.h"
#include "../Components/GraphicsComponents/GCExampleButton.h"


class ExampleButton: public GameObject<ICExampleButton, PCExampleButton, GCExampleButton> {

public:
	ExampleButton();
	~ExampleButton();
};


#endif // EXAMPLEBUTTON_H

