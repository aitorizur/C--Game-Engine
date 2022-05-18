//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Transform.hpp>
#include <Entity.hpp>
#include <b2_fixture.h>

namespace engine
{
	class BoxCollider2D : public Component
	{
	public:
		b2Fixture * fixture;

		BoxCollider2D(Entity* entity);
		~BoxCollider2D() = default;
	};
}
