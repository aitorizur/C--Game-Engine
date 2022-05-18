//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <Entity.hpp>
#include <b2_fixture.h>

namespace engine
{
	class CircleCollider2D : public Component
	{
	public:
		b2Fixture* fixture;

		CircleCollider2D(Entity* entity);
		~CircleCollider2D() = default;
	};
}