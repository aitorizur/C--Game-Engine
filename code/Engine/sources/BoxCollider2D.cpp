#include <BoxCollider2D.hpp>
#include <PhysicsSystem.hpp>
#include <b2_polygon_shape.h>

namespace engine
{
	BoxCollider2D::BoxCollider2D(Entity * entity) : Component(entity)
	{
		b2PolygonShape box;
		box.SetAsBox(gameobject->transform->scale.x * 0.5f, gameobject->transform->scale.y * 0.5f);
		fixture = gameobject->GetComponent<PhysicsComponent>()->body->CreateFixture(&box, 0.5f);
	}
}