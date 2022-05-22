//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <glm/glm.hpp>
#include <btBulletDynamicsCommon.h>
#include <memory>

namespace engine
{
	/// <summary>
	/// Contiene la informacion necesaria para manejar los cuerpos rigidos
	/// </summary>
	class Rigidbody : public Component
	{
		btCollisionShape* shape;

	public:

		btRigidBody* body;

		Rigidbody(Entity* entity);
		~Rigidbody() = default;

		void SetStatic()
		{
			body->setMassProps(0, btVector3(0, 0, 0));
		}

		void SetMass(const float value)
		{
			body->setMassProps(value, btVector3(1.0f, 1.0f, 1.0f));
		}

		void SetShapeSphere();

		void SetGravity(const float value)
		{
			body->setGravity(btVector3(0.0f, value, 0.0f));
		}

		void SetVelocity(const float x, const float y, const float z)
		{
			body->setLinearVelocity(btVector3(x, y, z));
		}

		void SetLinearFactor(const float x, const float y, const float z)
		{
			body->setLinearFactor(btVector3(x, y, z));
		}

		void SetAngularVelocity(const float x, const float y, const float z)
		{
			body->setAngularVelocity(btVector3(x, y, z));
		}

		void SetAngularFactor(const float x, const float y, const float z)
		{
			body->setAngularFactor(btVector3(x, y, z));
		}

		void SetFriction(float value)
		{
			body->setFriction(value);
		}
	};
}