//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <btBulletDynamicsCommon.h>
#include <RigidbodySystem.hpp>

namespace engine
{
	class Constraint : public Component
	{
		 btHingeConstraint * hingeConstraint;

	public:

		Constraint(Entity * entity);
		~Constraint() override = default;

		void SetConstraint(btRigidBody & rbA, btRigidBody& rbB, const btVector3 pivotInA, 
						   const btVector3 pivotInB, const btVector3 axisInA, const btVector3 axisInB)
		{
			hingeConstraint = new btHingeConstraint(rbA, rbB, pivotInA, pivotInB, axisInA, axisInB);
			RigidbodySystem::AddConstraint(hingeConstraint);
		}

		void EnableMotor(float targetVelocity, float maxMotorImpulse)
		{
			hingeConstraint->enableAngularMotor(true, targetVelocity, maxMotorImpulse);
		}

	};
}