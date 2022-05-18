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
		std::shared_ptr<btDiscreteDynamicsWorld> dynamicsWorld;

	public:

		RigidbodySystem()
		{
			btDefaultCollisionConfiguration collisionConfiguration;
			btCollisionDispatcher collisionDispatcher(&collisionConfiguration);
			btDbvtBroadphase overlappingPairCache;
			btSequentialImpulseConstraintSolver constraintSolver;

			dynamicsWorld.reset(new btDiscreteDynamicsWorld(&collisionDispatcher, 
														&overlappingPairCache, 
														&constraintSolver, 
														&collisionConfiguration));

			dynamicsWorld->setGravity(btVector3(0, -9.8, 0));
		}

		/// <summary>
		/// Anade un rigidbody a la lista de rigidbodies a actualizar
		/// </summary>
		/// <param name="rigidbody">Puntero a rigidbody a actualizar</param>
		static void AddRigidbody(Rigidbody* rigidbody)
		{
			rigidbodies.push_back(rigidbody);
		}

		void Run(bool& shouldExit) override
		{
			for (auto& currentRigidbody : rigidbodies)
			{
				Transform* currentTransform = currentRigidbody->gameobject->transform.get();
				currentTransform->position += currentRigidbody->velocity * TimeSystem::deltaTime;
				currentTransform->rotation += currentRigidbody->angularVelocity * TimeSystem::deltaTime;
			}
		}

		~RigidbodySystem() = default;
	};
}
