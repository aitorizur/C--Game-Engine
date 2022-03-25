#include <Rigidbody.hpp>
#include <RigidbodySystem.hpp>

namespace engine
{
	Rigidbody::Rigidbody(Entity* entity) : Component(entity)
	{
		RigidbodySystem::AddRigidbody(this);
	}
}