//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Rigidbody.hpp>
#include <Renderer.hpp>
#include <Monobehaviour.hpp>
#include <memory>
#include <InputSystem.hpp>

using namespace engine;

class Player : public Monobehaviour
{
	std::shared_ptr<Rigidbody> rigidbody;

	float speed = 10.0f;

	glm::vec3 initialPosition;

public:

	void Start() override
	{
		rigidbody.reset(gameobject->AddComponent<Rigidbody>());
		gameobject->AddComponent<Renderer>()->SetModel("../../assets/cube.obj");
		gameobject->transform->scale = glm::vec3(1.0f);
		initialPosition = gameobject->transform->position;
	}

	void Update() override;
	void InputControl();

	Player(Entity* entity) : Monobehaviour(entity) {}
	~Player() = default;
};
