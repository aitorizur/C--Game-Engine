//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <Entity.hpp>
#include <box2d.h>

namespace engine
{
	/// <summary>
	/// Contiene la informacion necesaria para manejar los cuerpos rigidos en 2D
	/// </summary>
	class Rigidbody2D : public Component
	{
		b2Fixture* fixture;

	public:

		b2Body* body;

		Rigidbody2D(Entity* entity);
		~Rigidbody2D() = default;

		void SetStatic()
		{
			body->SetType(b2_staticBody);
		}

		void SetLinearVelocity(const float xVelocity, const float yVelocity)
		{
			body->SetLinearVelocity(b2Vec2(xVelocity, yVelocity));
		}

		void SetAngularVelocity(const float angularVelocity)
		{
			body->SetAngularVelocity(angularVelocity);
		}

		void SetCircularShape()
		{
			body->DestroyFixture(fixture);

			b2CircleShape circleShape;
			circleShape.m_radius = gameobject->transform->scale.x;

			b2FixtureDef newBodyFixture;
			newBodyFixture.shape = &circleShape;
			newBodyFixture.density = 1.0f;
			newBodyFixture.restitution = 0.5f;
			newBodyFixture.friction = 0.7f;

			fixture = body->CreateFixture(&newBodyFixture);
		}
	};
}
