//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Monobehaviour.hpp>
#include <Rigidbody.hpp>
#include <Renderer.hpp>

using namespace engine;

class MovingPlatform : public Monobehaviour
{
	std::shared_ptr<Rigidbody> rigidbody;

public:

	MovingPlatform(Entity* entity) : Monobehaviour(entity) {}
	~MovingPlatform() = default;

	void Start() override
	{
		gameobject->transform->position.x = 20.0f;
		gameobject->transform->position.y = 5.0f;
		gameobject->transform->position.z = -30.0f;
		gameobject->transform->scale.x = 5.0f;
		gameobject->transform->scale.z = 5.0f;
		gameobject->AddComponent<Renderer>();
		rigidbody.reset(gameobject->AddComponent<Rigidbody>());
		rigidbody->SetGravity(0.0f);
		rigidbody->SetVelocity(-5.0f, 0.0f, 0.0f);
		rigidbody->SetLinearFactor(1.0f, 0.0f, 0.0f);
		rigidbody->SetAngularFactor(0.0f, 0.0f, 0.0f);
	}

	void Update() override
	{

	}
};
