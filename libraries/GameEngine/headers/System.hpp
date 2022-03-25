//Codigo propiedad de Aitor Izurrategui

#pragma once
#include <Task.hpp>
#include <Scene.hpp>

namespace engine
{
	/// <summary>
	/// Tarea que guarda un puntero a la escena donde esta creada
	/// </summary>
	class System : public Task
	{
		Scene * scene;

	public:
		System() = default;
		virtual ~System() = default;
	};
}