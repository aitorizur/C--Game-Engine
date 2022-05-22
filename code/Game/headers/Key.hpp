//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <Monobehaviour.hpp>
#include <Renderer.hpp>
#include <MovingDoor.hpp>

using namespace engine;

class Key : public Monobehaviour
{
	float distanceToConsiderReach = 4.0f;
	std::shared_ptr<Renderer> renderer;

public:

	Transform* playerTransform = nullptr;
	MovingDoor* movingDoor = nullptr;

	Key(Entity* entity) : Monobehaviour(entity) {}
	~Key() = default;

private:

	void Start() override
	{
		gameobject->AddComponent<Renderer>()->SetModel("../../assets/sphere.obj");
	}

	void Update() override
	{
		if (glm::distance(playerTransform->position, gameobject->transform->position) <= distanceToConsiderReach)
		{
			movingDoor->SetActive();
			gameobject->transform->position.x = 100.0f;
		}
	}
};
