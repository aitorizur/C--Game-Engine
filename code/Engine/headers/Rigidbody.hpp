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

		/// <summary>
		/// Hace el cuerpo fisico estatico
		/// </summary>
		void SetStatic()
		{
			body->setMassProps(0, btVector3(0, 0, 0));
		}

		/// <summary>
		/// Cambia la masa del cuerpo fisico
		/// </summary>
		/// <param name="value"></param>
		void SetMass(const float value)
		{
			body->setMassProps(value, btVector3(1.0f, 1.0f, 1.0f));
		}

		/// <summary>
		/// Le da una colision de esfera al cuerpo rigido
		/// </summary>
		void SetShapeSphere();

		/// <summary>
		/// Cambia la gravedad al cuerpo rigido
		/// </summary>
		/// <param name="value">Nuevo valor de gravedad</param>
		void SetGravity(const float value)
		{
			body->setGravity(btVector3(0.0f, value, 0.0f));
		}

		/// <summary>
		/// Setea la velocidad lineal del cuerpo rigido
		/// </summary>
		/// <param name="x">Velocidad en x</param>
		/// <param name="y">Velocidad en y</param>
		/// <param name="z">Velocidad en z</param>
		void SetVelocity(const float x, const float y, const float z)
		{
			body->setLinearVelocity(btVector3(x, y, z));
		}

		/// <summary>
		/// Limita o libera los ojos de movimiento lineal
		/// </summary>
		/// <param name="x">Valor en x</param>
		/// <param name="y">Valor en y</param>
		/// <param name="z">Valor en z</param>
		void SetLinearFactor(const float x, const float y, const float z)
		{
			body->setLinearFactor(btVector3(x, y, z));
		}

		/// <summary>
		/// Setea la velocidad angular del cuerpo rigido
		/// </summary>
		/// <param name="x">Velocidad en x</param>
		/// <param name="y">Velocidad en y</param>
		/// <param name="z">Velocidad en z</param>
		void SetAngularVelocity(const float x, const float y, const float z)
		{
			body->setAngularVelocity(btVector3(x, y, z));
		}

		/// <summary>
		/// Limita o libera los ojos de movimiento angular
		/// </summary>
		/// <param name="x">Valor en x</param>
		/// <param name="y">Valor en y</param>
		/// <param name="z">Valor en z</param>
		void SetAngularFactor(const float x, const float y, const float z)
		{
			body->setAngularFactor(btVector3(x, y, z));
		}

		/// <summary>
		/// Cambia la fricción de un cuerop rigido
		/// </summary>
		/// <param name="value">Nuevo valor de friccion</param>
		void SetFriction(float value)
		{
			body->setFriction(value);
		}
	};
}