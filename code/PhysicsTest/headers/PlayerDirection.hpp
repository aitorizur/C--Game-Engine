//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Renderer.hpp>
#include <Monobehaviour.hpp>

using namespace engine;

class PlayerDirection : public Monobehaviour
{

public:

	void Start() override
	{
		gameobject->AddComponent<Renderer>();
		gameobject->transform->position.x = -0.35f;
		gameobject->transform->scale = glm::vec3(0.2f);
	}

	PlayerDirection(Entity* entity) : Monobehaviour(entity) {}
	~PlayerDirection() = default;
};