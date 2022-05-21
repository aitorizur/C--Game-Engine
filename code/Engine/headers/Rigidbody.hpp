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

	public:

		btRigidBody * body;
		btCollisionShape * shape;

		Rigidbody(Entity* entity);
		~Rigidbody() = default;

		void SetStatic()
		{
			body->setMassProps(0, btVector3(0, 0, 0));
		}

		void SetMass(const float value)
		{
			body->setMassProps(value, btVector3(0, 0, 0));
		}

		void SetShapeSphere();
	};
}