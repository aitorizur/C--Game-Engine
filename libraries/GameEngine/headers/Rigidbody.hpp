//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <glm/glm.hpp>

namespace engine
{
	/// <summary>
	/// Contiene la informacion necesaria para manejar los cuerpos rigidos
	/// </summary>
	class Rigidbody : public Component
	{
	public:
		glm::vec3 velocity = glm::vec3(0, 0, 0);
		glm::vec3 angularVelocity = glm::vec3(0, 0, 0);

		Rigidbody(Entity* entity);
		~Rigidbody() = default;
	};
}