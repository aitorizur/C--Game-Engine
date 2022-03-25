//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <Entity.hpp>
#include <glm/glm.hpp>

namespace engine
{
	/// <summary>
	/// Clase de la que derivar para programar componentes
	/// </summary>
	class Monobehaviour : public Component
	{
	public:

		Monobehaviour(Entity* entity);
		~Monobehaviour() = default;

		/// <summary>
		/// Ejecutada al crear la entidad
		/// </summary>
		virtual void Start() {}
		/// <summary>
		/// Ejecutada cada frame en el que el objeto existe en la escena
		/// </summary>
		virtual void Update() {}
	};
}