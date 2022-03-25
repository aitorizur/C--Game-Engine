//Codigo propiedad de Aitor Izurrategui

#include <Player.hpp>

void Player::InputControl()
{
	if (InputSystem::GetAction("up"))
	{
		rigidbody->velocity.y = speed;
		rigidbody->velocity.x = 0.0f;
		gameobject->transform->rotation.y = -1.57;
	}
	if (InputSystem::GetAction("down"))
	{
		rigidbody->velocity.y = -speed;
		rigidbody->velocity.x = 0.0f;
		gameobject->transform->rotation.y = 1.57;
	}
	if (InputSystem::GetAction("right"))
	{
		rigidbody->velocity.x = speed;
		rigidbody->velocity.y = 0.0f;
		gameobject->transform->rotation.y = 3.14;
	}
	if (InputSystem::GetAction("left"))
	{
		rigidbody->velocity.x = -speed;
		rigidbody->velocity.y = 0.0f;
		gameobject->transform->rotation.y = 0;
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