#include <Rigidbody.hpp>
#include <RigidbodySystem.hpp>

namespace engine
{
	Rigidbody::Rigidbody(Entity* entity) : Component(entity)
	{
		shape = new btBoxShape(btVector3(gameobject->transform->scale.x, 
										 gameobject->transform->scale.y, 
										 gameobject->transform->scale.z));

		btTransform physicsTransform;
		physicsTransform.setIdentity();
		physicsTransform.setOrigin(btVector3(gameobject->transform->position.x,
											 gameobject->transform->position.y, 
											 gameobject->transform->position.z));

		btScalar initialMass = 1.0f;
		btVector3 initialInertia(0, 0, 0);
		shape->calculateLocalInertia(initialMass, initialInertia);

		btDefaultMotionState* motionState = new btDefaultMotionState(physicsTransform);
		btRigidBody::btRigidBodyConstructionInfo constructionInfo(initialMass, motionState, shape, initialInertia);

		body = new btRigidBody(constructionInfo);
		body->setActivationState(DISABLE_DEACTIVATION);
		RigidbodySystem::AddRigidbody(this);
	}

	void Rigidbody::SetShapeSphere()
	{
		body->setCollisionShape(new btSphereShape(gameobject->transform->scale.x));
	}

}