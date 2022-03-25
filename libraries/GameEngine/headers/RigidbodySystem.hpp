//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <System.hpp>
#include <Rigidbody.hpp>
#include <memory>
#include <list>
#include <Entity.hpp>
#include <TimeSystem.hpp>

namespace engine
{
	/// <summary>
	/// Gestiona la actualización de todos los cuerpos rigidos de la escena
	/// </summary>
	class RigidbodySystem : public System
	{
		static std::list<Rigidbody*> rigidbodies;

	public:

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

		RigidbodySystem() = default;
		~RigidbodySystem() = default;
	};
}
