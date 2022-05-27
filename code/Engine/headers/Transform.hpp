//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <glm/glm.hpp>
#include <Component.hpp>
#include<glm/gtc/quaternion.hpp>

namespace engine
{
	/// <summary>
	/// Componente que almacena la informacion necesaria para actualizar la transformacion de una entidad. Siempre hay incluido en un transform en cada entidad.
	/// </summary>
	class Transform : public Component
	{
	public:

		Transform* parent;

		glm::vec3 position;
		glm::vec3 scale;
		glm::quat rotation;

		Transform(Entity* entity);
		~Transform() override = default;

		const glm::vec3 GetEulerRotation()
		{
			return glm::eulerAngles(rotation);
		}
	};
}