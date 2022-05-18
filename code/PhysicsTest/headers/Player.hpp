//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Rigidbody.hpp>
#include <Renderer.hpp>
#include <Monobehaviour.hpp>
#include <memory>
#include <InputSystem.hpp>
#include <PositionResetElement.hpp>

using namespace engine;

class Player : public Monobehaviour, public PositionResetElement
{
	std::shared_ptr<Rigidbody> rigidbody;

	float speed = 10.0f;

	glm::vec3 initialPosition;

public:

	void Start() override
	{
		rigidbody.reset(gameobject->AddComponent<Rigidbody>());
		gameobject->AddComponent<Renderer>()->SetModel("../../assets/sphere.obj");
		gameobject->transform->rotation.x = 1.57;
		gameobject->transform->scale = glm::vec3(3.0f);
		initialPosition = gameobject->transform->position;
	}

	void Update() override
	{
		InputControl();
		LimitMovement();
	}

	void ResetPosition() override
	{
		rigidbody->velocity = glm::vec3(0.0f);
		gameobject->transform->position = initialPosition;
	}

	void InputControl();
	void LimitMovement();

	Player(Entity* entity) : Monobehaviour(entity) {}
	~Player() = default;
};
