#include <Rigidbody2DSystem.hpp>

namespace engine
{
	std::list<Rigidbody2D*> Rigidbody2DSystem::rigidbodies2D;
	std::unique_ptr<b2World> Rigidbody2DSystem::dynamics2DWorld;

	void Rigidbody2DSystem::Run(bool& shouldExit)
	{
		for (auto& currentRigidbody2D : rigidbodies2D)
		{
			Transform* transform = currentRigidbody2D->gameobject->transform.get();

			currentRigidbody2D->body->SetTransform(b2Vec2(transform->position.x, transform->position.y), transform->GetEulerRotation().z);
		}

		dynamics2DWorld->Step(TimeSystem::deltaTime, 8, 4);

		for (auto& currentRigidbody2D : rigidbodies2D)
		{
			b2Vec2 position = currentRigidbody2D->body->GetPosition();
			float rotation = currentRigidbody2D->body->GetAngle();

			currentRigidbody2D->gameobject->transform->position = glm::vec3(position.x, position.y, currentRigidbody2D->gameobject->transform->position.z);
			currentRigidbody2D->gameobject->transform->rotation = glm::quat(glm::vec3(currentRigidbody2D->gameobject->transform->GetEulerRotation().x,
				currentRigidbody2D->gameobject->transform->GetEulerRotation().y,
				rotation));
		}
	}
}