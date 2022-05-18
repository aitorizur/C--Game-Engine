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
	}

	PlayerDirection(Entity* entity) : Monobehaviour(entity) {}
	~PlayerDirection() = default;
};