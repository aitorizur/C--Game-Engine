//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Component.hpp>
#include <memory>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <Entity.hpp>
#include <Render_Node.hpp>

namespace engine
{
	/// <summary>
	/// Componente encargado de almacenar la informacion necesaria para rendear un objeto en la escena
	/// </summary>
	class Renderer : public Component
	{
	public:
		std::shared_ptr< glt::Model  > model;

		/// <summary>
		/// Reemplaza el modelo base del objeto por el obj en la ruta especificada
		/// </summary>
		/// <param name="objRef">Ruta donde se encuentra el modelo obj</param>
		void SetModel(const std::string objRef);

		Renderer(Entity* entity);
		~Renderer() override = default;
	};
}