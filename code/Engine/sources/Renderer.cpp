#include <Renderer.hpp>
#include <RenderSystem.hpp>

namespace engine
{
	Renderer::Renderer(Entity* entity) : Component(entity)
	{
		model.reset(new glt::Model_Obj("cube.obj"));

		if (gameobject->transform->parent != nullptr)
		{
			model->set_parent(gameobject->transform->parent->gameobject->GetComponent<Renderer>()->model.get());
		}

		RenderSystem::AddRenderer(this, model);
	}

	void Renderer::SetModel(const std::string objRef)
	{
		model->set_visible(false);
		model.reset(new glt::Model_Obj(objRef));
		RenderSystem::AddModel(model);
	}
}