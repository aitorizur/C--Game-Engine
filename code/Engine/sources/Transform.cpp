#include <Transform.hpp>

namespace engine
{
	Transform::Transform(Entity * entity) : Component(entity)
	{
		parent = nullptr;

		position = glm::vec3(0, 0, 0);
		scale = glm::vec3(1, 1, 1);
		rotation = glm::vec3(0, 0, 0);
	}
}

