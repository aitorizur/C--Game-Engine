//Codigo propiedad de Aitor Izurrategui

#include <Player.hpp>

void Player::Update()
{
	InputControl();
}

void Player::InputControl()
{
	if (InputSystem::GetAction("up"))
	{
		gameobject->transform->rotation.z += 0.2f;
	}
}