//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Rigidbody.hpp>
#include <Renderer.hpp>
#include <Monobehaviour.hpp>
#include <memory>
#include <InputSystem.hpp>
#include <Constraint.hpp>

using namespace engine;

class Player : public Monobehaviour
{

	float speed = 4.0f;

	glm::vec3 initialPosition;
	
	Constraint* RLConstraint;
	Constraint* FRConstraint;
	Constraint* RRConstraint;
	Constraint* FLConstraint;
	Constraint* catapultConstraint;

public:

	std::shared_ptr<Rigidbody> rigidbody;
	Scene* scene = nullptr;

private:

	void CreateBody()
	{
		gameobject->transform->scale.x = 2.0f;
		gameobject->transform->scale.z = 3.0f;
		gameobject->transform->scale.y = 0.5f;
		initialPosition = gameobject->transform->position;
		gameobject->AddComponent<Renderer>();
		rigidbody.reset(gameobject->AddComponent<Rigidbody>());
		rigidbody->SetMass(10.0f);
	}

	void CreateWheels();
	void CreateCatapult();

public:

	Player(Entity* entity) : Monobehaviour(entity) {}
	~Player() = default;

	void Start() override
	{
		CreateBody();
		CreateWheels();
		CreateCatapult();
	}

	void Update() override;
	void InputControl();
};
