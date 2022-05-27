#include <Rigidbody2D.hpp>
#include <Rigidbody2DSystem.hpp>

namespace engine
{
	Rigidbody2D::Rigidbody2D(Entity* entity) : Component(entity)
	{
		b2BodyDef bodyDef;

		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(gameobject->transform->position.x, gameobject->transform->position.y);
		bodyDef.angle = gameobject->transform->GetEulerRotation().z;

		body = Rigidbody2DSystem::AddRigidbody2D(&bodyDef, this);

		b2PolygonShape boxShape;
		boxShape.SetAsBox(gameobject->transform->scale.x, gameobject->transform->scale.y);

		b2FixtureDef bodyFixture;

		bodyFixture.shape = &boxShape;
		bodyFixture.density = 1.0f;
		bodyFixture.restitution = 0.5f;
		bodyFixture.friction = 0.7f;

		fixture = body->CreateFixture(&bodyFixture);
	}
}
