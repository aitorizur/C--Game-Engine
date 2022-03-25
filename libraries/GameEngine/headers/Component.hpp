//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <memory>

namespace engine
{
	class Entity;
	/// <summary>
	/// Clase que define el comportamiento de una entidad
	/// </summary>
	class Component
	{
	public:

		std::shared_ptr<Entity> gameobject;

		Component(Entity * entity)
		{
			gameobject.reset(entity);
		}

		virtual ~Component() = default;
	};
}