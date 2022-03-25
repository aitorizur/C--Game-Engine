//Codigo propiedad de Aitor Izurrategui

#pragma once
#include <Entity.hpp>
#include <Transform.hpp>
#include <memory>

namespace engine
{
	/// <summary>
	/// Clase que guarda puntero a todas las entidades creadas dentro de ella
	/// </summary>
	class Scene
	{
		std::list<std::unique_ptr<Entity>> entities;

	public:
		Scene() = default;
		~Scene() = default;

		/// <summary>
		/// Crea una entidad dentro del contexto de la escena
		/// </summary>
		/// <returns>Devuelve puntero a la entidad creada</returns>
		Entity* CreateEntity()
		{
			entities.push_back(std::unique_ptr<Entity>(new Entity(this)));
			return entities.back().get();
		}

		/// <summary>
		/// Crea una entidad dentro del contexto de la escena
		/// </summary>
		/// <param name="transform">Transform del padre de la entidad</param>
		/// <returns>Devuelve puntero a la entidad creada</returns>
		Entity* CreateEntity(Transform * transform)
		{
			entities.push_back(std::unique_ptr<Entity>(new Entity(this, transform)));
			return entities.back().get();
		}
	};
}