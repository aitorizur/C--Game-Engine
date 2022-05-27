//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <System.hpp>
#include <memory>
#include <list>
#include <box2d.h>
#include <Rigidbody2D.hpp>
#include <TimeSystem.hpp>

namespace engine
{
	/// <summary>
	/// Gestiona la actualización de todos los cuerpos rigidos de la escena
	/// </summary>
	class Rigidbody2DSystem : public System
	{
		static std::list<Rigidbody2D*> rigidbodies2D;
		static std::unique_ptr<b2World> dynamics2DWorld;

	public:

		Rigidbody2DSystem()
		{
			dynamics2DWorld.reset(new b2World(b2Vec2(0.0f, -9.8f)));
		}

		~Rigidbody2DSystem() = default;

		static b2Body * AddRigidbody2D(const b2BodyDef * bodyDef, Rigidbody2D * rigidbody2D)
		{
			rigidbodies2D.push_back(rigidbody2D);
			b2Body * newBody = dynamics2DWorld->CreateBody(bodyDef);
			return newBody;
		}


		void Run(bool& shouldExit) override;
		
	};
}
