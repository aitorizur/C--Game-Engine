//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Renderer.hpp>
#include <Monobehaviour.hpp>

using namespace engine;

class Wall : public Monobehaviour
{

public:

	void Start() override
	{
		gameobject->AddComponent<Renderer>()->SetModel("../../assets/cube.obj");
		Rigidbody * rb = gameobject->AddComponent<Rigidbody>();
		rb->SetStatic();
	}

	Wall(Entity* entity) : Monobehaviour(entity) {}
	~Wall() = default;
};