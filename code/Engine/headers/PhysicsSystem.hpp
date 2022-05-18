//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <System.hpp>
#include <b2_world.h>
#include <b2_math.h>
#include <PhysicsComponent.hpp>

namespace engine
{
	class PhysicsSystem : public System
	{
		static std::list<PhysicsComponent*> physicsComponents;
		float timeStep = 1.0f / 50.0f;
		int velocityIterations = 6;
		int positionIterations = 2;

	public:

		b2Vec2 gravity {0.0f, -9.8f};
		static b2World b2world;

		PhysicsSystem() = default;
		~PhysicsSystem() override = default;

		static void AddPhysicComponent(PhysicsComponent* physicComponent)
		{
			physicsComponents.push_back(physicComponent);
		}

		void Initialize() override
		{
			b2world = *new b2World(gravity);
		}

		void Run(bool& shouldExit) override
		{
			UpdatePhysicObject();
			b2world.Step(timeStep, velocityIterations, positionIterations);
			UpdateTransforms();
		}

	private:

		void UpdatePhysicObject()
		{
			for (auto& currentPhysicComponent : physicsComponents)
			{
				b2Vec2 position(currentPhysicComponent->gameobject->transform->position.x, currentPhysicComponent->gameobject->transform->position.y);
				currentPhysicComponent->body->SetTransform(position, currentPhysicComponent->gameobject->transform->rotation.z);
			}
		}

		void UpdateTransforms()
		{
			for (auto& currentPhysicComponent : physicsComponents)
			{
				currentPhysicComponent->gameobject->transform->position.x = currentPhysicComponent->body->GetPosition().x;
				currentPhysicComponent->gameobject->transform->position.y = currentPhysicComponent->body->GetPosition().y;
				currentPhysicComponent->gameobject->transform->rotation.z = currentPhysicComponent->body->GetAngle();
			}
		}
	};
}