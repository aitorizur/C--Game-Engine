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
		gameobject->transform->position.x += 2;
	}
}