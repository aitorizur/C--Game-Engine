//Codigo propiedad de Aitor Izurrategui

#include <Player.hpp>

void Player::InputControl()
{
	if (InputSystem::GetAction("up"))
	{
		rigidbody->velocity.y = speed;
		rigidbody->velocity.x = 0.0f;
	}
	if (InputSystem::GetAction("down"))
	{
		rigidbody->velocity.y = -speed;
		rigidbody->velocity.x = 0.0f;
	}
	if (InputSystem::GetAction("right"))
	{
		rigidbody->velocity.x = speed;
		rigidbody->velocity.y = 0.0f;
	}
	if (InputSystem::GetAction("left"))
	{
		rigidbody->velocity.x = -speed;
		rigidbody->velocity.y = 0.0f;
	}
}

void Player::LimitMovement()
{
	if (gameobject->transform->position.x > 20.0f)
	{
		gameobject->transform->position.x = 20.0f;
	}
	if (gameobject->transform->position.x < -20.0f)
	{
		gameobject->transform->position.x = -20.0f;
	}
	if (gameobject->transform->position.y > 11.0f)
	{
		gameobject->transform->position.y = 11.0f;
	}
	if (gameobject->transform->position.y < -11.0f)
	{
		gameobject->transform->position.y = -11.0f;
	}
}