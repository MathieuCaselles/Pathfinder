#ifndef EXAMPLEBUTTON_H
#define EXAMPLEBUTTON_H

#include "../Components/InputComponents/ICExampleButton.h"
#include "../Components/PhysicsComponents/PCExampleButton.h"
#include "../Components/GraphicsComponents/GCExampleButton.h"
#include "../../Engine/GameObject/GameObject.h"


class ExampleButton: public GameObject<ICExampleButton, PCExampleButton, GCExampleButton> {

public:
	ExampleButton();
	~ExampleButton();
};


#endif // EXAMPLEBUTTON_H

