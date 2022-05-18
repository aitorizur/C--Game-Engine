#include <CircleCollider2D.hpp>
#include <PhysicsSystem.hpp>
#include <b2_circle_shape.h>

namespace engine
{
	CircleCollider2D::CircleCollider2D(Entity* entity) : Component(entity)
	{
		b2CircleShape circle;
		circle.m_radius = gameobject->transform->scale.x * 0.5f;
		fixture = gameobject->GetComponent<PhysicsComponent>()->body->CreateFixture(&circle, 0.5f);
	}
}