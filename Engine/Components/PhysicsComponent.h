#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

class IGameObject;

class IScene;


struct IPhysicsComponent
{
    virtual ~IPhysicsComponent() = default;
    virtual void updateImplementation(const float& deltaTime, IGameObject& gameObject, IScene& scene) = 0;
};


#endif // PHYSICSCOMPONENT_H