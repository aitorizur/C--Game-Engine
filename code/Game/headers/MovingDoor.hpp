//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <Monobehaviour.hpp>
#include <Rigidbody.hpp>
#include <TimeSystem.hpp>
#include <Renderer.hpp>

using namespace engine;

class MovingDoor : public Monobehaviour
{
	float distance = 0.0f;
	float speed = 5.0f;
	std::shared_ptr<Rigidbody> rigidbody;
	bool active = false;

public:

	glm::vec3 direction = glm::vec3(0.0f);
	float maxDistance = 10.0f;

	MovingDoor(Entity* entity) : Monobehaviour(entity) {}
	~MovingDoor() = default;

private:

	void Start() override
	{
		gameobject->AddComponent<Renderer>();
		rigidbody.reset(gameobject->AddComponent<Rigidbody>());
		rigidbody->SetLinearFactor(0.0f, 0.0f, 0.0f);
		rigidbody->SetAngularFactor(0.0f, 0.0f, 0.0f);
	}

	void Update() override
	{
		if (active)
		{
			rigidbody->SetLinearFactor(1.0f, 0.0f, 0.0f);
			rigidbody->SetVelocity(direction.x * speed, direction.y * speed, direction.z * speed);
			CheckOpen();
		}
		else
		{
			rigidbody->SetLinearFactor(0.0f, 0.0f, 0.0f);
			rigidbody->SetVelocity(0.0f, 0.0f, 0.0f);
		}
	}

	void CheckOpen()
	{
		distance += TimeSystem::deltaTime * direction.x * speed;
		if (distance >= maxDistance)
		{
			active = false;
		}
	}

public:

	void SetActive()
	{
		active = true;
	}
};