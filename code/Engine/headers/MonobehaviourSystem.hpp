//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <list>
#include <System.hpp>
#include <Entity.hpp>
#include <Monobehaviour.hpp>

namespace engine
{
	/// <summary>
	/// Sistema encargado de iterar entre todos los updates de los monobheaviours
	/// </summary>
	class MonobehaviourSystem : public System
	{
		static std::list<Monobehaviour*> monobehaviours;

	public:

		/// <summary>
		/// Anade un monobehacviour a las tareas que ejecutar en bucle
		/// </summary>
		/// <param name="monobehaviour">Monobehaviour a anadir</param>
		static void AddMonobehaviour(Monobehaviour* monobehaviour)
		{
			monobehaviours.push_back(monobehaviour);
		}

		void Initialize() override
		{
			for (auto& currentMonobehaviour : monobehaviours)
			{
				currentMonobehaviour->Start();
			}
		}

		void Run(bool& shouldExit) override
		{
			for (auto& currentMonobehaviour : monobehaviours)
			{
				currentMonobehaviour->Update();
			}
		}

		MonobehaviourSystem() = default;
		~MonobehaviourSystem() = default;
	};
}