//Codigo propiedad de Aitor Izurrategui

#include <MovingPlatform.hpp>

using namespace engine;

void MovingPlatform::Start()
{
	gameobject->transform->position.x = -10.0f;
	gameobject->transform->position.y = -10.0f;
	gameobject->transform->position.z = -15.0f;
	gameobject->transform->scale.x = 5.0f;
	gameobject->transform->scale.z = 5.0f;
	gameobject->AddComponent<Renderer>();
	rigidbody.reset(gameobject->AddComponent<Rigidbody>());
	rigidbody->SetLinearFactor(0.0f, 0.0f, 0.0f);
	rigidbody->SetAngularFactor(0.0f, 0.0f, 0.0f);
}