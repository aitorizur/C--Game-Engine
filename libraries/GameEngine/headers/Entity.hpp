//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <memory>
#include <list>
#include <Transform.hpp>

namespace engine
{
	class Scene;
	/// <summary>
	/// Clase que representa una entidad en una escena
	/// </summary>
	class Entity
	{
	public:
		
		std::shared_ptr<Scene> scene;
		std::shared_ptr<Transform> transform;

	private:

		std::list<std::shared_ptr<Component>> components;

	public:

		Entity(Scene * givenScene)
		{
			scene.reset(givenScene);
			transform.reset(AddComponent<Transform>());
		};

		Entity(Scene * givenScene, Transform * givenParent)
		{
			scene.reset(givenScene);
			transform.reset(AddComponent<Transform>());
			transform->parent = givenParent;
		};

		virtual ~Entity() = default;

		/// <summary>
		/// Añade componentes a una entidad
		/// </summary>
		/// <typeparam name="T">Tipo del componente a crear</typeparam>
		/// <returns>Retorna un puntero al componente creado</returns>
		template<typename T>
		T * AddComponent()
		{
			T * component = new T(this);
			components.push_back(std::shared_ptr<T>(component));
			return component;
		}

		/// <summary>
		/// Retorna el componente de una entidad si es que existe. Si no devuelve nullptr
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template<typename T>
		T * GetComponent()
		{
			for (auto & currentComponent : components)
			{
				if (dynamic_cast<T*>(currentComponent.get()) != nullptr)
				{
					return dynamic_cast<T*>(currentComponent.get());
				}
			}

			return nullptr;
		}
	};
}