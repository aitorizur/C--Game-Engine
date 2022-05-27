//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <list>
#include <Task.hpp>
#include <RigidbodySystem.hpp>
#include <Rigidbody2DSystem.hpp>
#include <RenderSystem.hpp>
#include <TimeSystem.hpp>
#include <MonobehaviourSystem.hpp>
#include <InputSystem.hpp>
#include <MessageDispatcher.hpp>

namespace engine
{
	/// <summary>
	/// Debe crearse a principio de main ya que inicializa todos los sistemas necesarios. Su función de ejecución debe ser lo ultimo en llamarse en main
	/// </summary>
	class Kernel
	{
		std::list<Task*> tasks;
		bool shouldContinue = true;

		MessageDispatcher messageDispatcher;

		TimeSystem timeSystem;
		MonobehaviourSystem monobehaviourSystem;
		Rigidbody2DSystem rigidbody2DSystem;
		RigidbodySystem rigidbodySystem;
		RenderSystem renderSystem;
		InputSystem inputSystem;

	public:

		Kernel();
		~Kernel() = default;

		/// <summary>
		/// Ejecucion del bucle principal del juego. Aquí se ejecutan los sistemas en el orden correcto
		/// </summary>
		void Execute();
	};
}