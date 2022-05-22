//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <System.hpp>
#include <Rigidbody.hpp>
#include <memory>
#include <list>
#include <Entity.hpp>
#include <TimeSystem.hpp>
#include <btBulletDynamicsCommon.h>
#include <memory>

namespace engine
{
	/// <summary>
	/// Gestiona la actualización de todos los cuerpos rigidos de la escena
	/// </summary>
	class RigidbodySystem : public System
	{
		static std::list<Rigidbody*> rigidbodies;
		static btDiscreteDynamicsWorld* dynamicsWorld;

	public:

		RigidbodySystem();
		~RigidbodySystem() = default;

		/// <summary>
		/// Anade un rigidbody a la lista de rigidbodies a actualizar. Tambien anade los cuerpos fisicos al mundo
		/// </summary>
		/// <param name="rigidbody">Puntero a rigidbody a actualizar</param>
		static void AddRigidbody(Rigidbody* rigidbody)
		{
			rigidbodies.push_back(rigidbody);
			dynamicsWorld->addRigidBody(rigidbody->body);
		}

		/// <summary>
		/// Anade un Constraint al mundo
		/// </summary>
		/// <param name="constraint">Punto al constraint a actualizar</param>
		static void AddConstraint(btHingeConstraint* constraint)
		{
			dynamicsWorld->addConstraint(constraint);
		}

		void Run(bool& shouldExit) override;
		void UpdatePhysicWorld(float step);
	};
}
