#include <PhysicsComponent.hpp>
#include <PhysicsSystem.hpp>

namespace engine
{
	PhysicsComponent::PhysicsComponent(Entity* entity) : Component(entity)
	{
		PhysicsSystem::AddPhysicComponent(this);
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(gameobject->transform->position.x, gameobject->transform->position.y);
		body = PhysicsSystem::b2world.CreateBody(&bodyDef);
	}
}