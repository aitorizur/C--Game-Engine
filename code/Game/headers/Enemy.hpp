//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Renderer.hpp>
#include <Monobehaviour.hpp>
#include <Player.hpp>
#include <memory>
#include <Rigidbody.hpp>
#include <PositionResetElement.hpp>
#include <MessageDispatcher.hpp>

using namespace engine;

class Enemy : public Monobehaviour, public PositionResetElement
{
	std::shared_ptr<Entity> player;
	std::shared_ptr<Rigidbody> rigidbody;

	float speed = 5.0f;
	float maxPlayerDistance = 2.0f;

	glm::vec3 initialPosition;

public:

	void Setup(Entity* givenPlayer)
	{
		player.reset(givenPlayer);
	}

	void Start() override
	{
		gameobject->AddComponent<Renderer>()->SetModel("../../assets/sphere.obj");
		rigidbody.reset(gameobject->AddComponent<Rigidbody>());
		initialPosition = gameobject->transform->position;
	}

	void ResetPosition() override
	{
		gameobject->transform->position = initialPosition;
	}

	void Update() override
	{
		UpdateDirection();
		CheckCollision();
	}

	void UpdateDirection()
	{
		glm::vec3 direction(player->transform->position - gameobject->transform->position);
		rigidbody->velocity = NormalizedVector(direction) * speed;
	}

	void CheckCollision()
	{
		glm::vec3 distance = player->transform->position - gameobject->transform->position;
		if (Magnitude(distance) < maxPlayerDistance)
		{
			MessageDispatcher::Send(Message("gamereset", ""));
		}
	}

	float Magnitude(const glm::vec3 & givenVector)
	{
		return std::sqrt(std::pow(givenVector.x, 2) + std::pow(givenVector.y, 2) + std::pow(givenVector.z, 2));
	}

	glm::vec3 NormalizedVector(const glm::vec3& givenVector)
	{
		return givenVector / Magnitude(givenVector);
	}

	Enemy(Entity* entity) : Monobehaviour(entity) {}
	~Enemy() = default;
};