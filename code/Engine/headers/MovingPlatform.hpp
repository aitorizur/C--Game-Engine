//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Monobehaviour.hpp>
#include <Rigidbody.hpp>
#include <Renderer.hpp>
#include <Transform.hpp>

using namespace engine;

class MovingPlatform : public Monobehaviour
{
	std::shared_ptr<Rigidbody> rigidbody;
	bool isActive = false;

public:

	std::shared_ptr<Transform> playerTransform;

	MovingPlatform(Entity* entity) : Monobehaviour(entity) {}
	~MovingPlatform() = default;

	void Start() override;

	void Update() override
	{
		DetectStartMoving();
		Move();
	}

	void DetectStartMoving()
	{
		if (glm::distance(gameobject->transform->position, playerTransform->position) <= 3.0f && !isActive)
		{
			isActive = true;
		}
	}

	void Move()
	{
		if (isActive)
		{
			rigidbody->SetVelocity(0.0f, 0.0f, -3.0f);
			rigidbody->SetLinearFactor(0.0f, 0.0f, 1.0f);
		}
		else
		{
			rigidbody->SetVelocity(0.0f, 0.0f, 0.0f);
		}
	}
};
