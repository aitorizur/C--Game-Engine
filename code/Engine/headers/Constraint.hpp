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

		/// <summary>
		/// Prepara el constraint entre dos objetos fisicos
		/// </summary>
		void SetConstraint(btRigidBody & rbA, btRigidBody& rbB, const btVector3 pivotInA, 
						   const btVector3 pivotInB, const btVector3 axisInA, const btVector3 axisInB)
		{
			hingeConstraint = new btHingeConstraint(rbA, rbB, pivotInA, pivotInB, axisInA, axisInB);
			RigidbodySystem::AddConstraint(hingeConstraint);
		}

		/// <summary>
		/// Da velocidad a un motor
		/// </summary>
		/// <param name="targetVelocity">Velocidad a alcanzar</param>
		/// <param name="maxMotorImpulse">Velocidad maxima</param>
		void EnableMotor(float targetVelocity, float maxMotorImpulse)
		{
			hingeConstraint->enableAngularMotor(true, targetVelocity, maxMotorImpulse);
		}

		/// <summary>
		/// Hace que el constraint no pueda rotar
		/// </summary>
		void SetStill()
		{
			hingeConstraint->setLimit(0.0f, 0.0f);
		}
	};
}