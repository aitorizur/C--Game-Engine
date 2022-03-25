#include <Monobehaviour.hpp>
#include <MonobehaviourSystem.hpp>

namespace engine
{
	Monobehaviour::Monobehaviour(Entity* entity) : Component(entity)
	{
		MonobehaviourSystem::AddMonobehaviour(this);
	}
}