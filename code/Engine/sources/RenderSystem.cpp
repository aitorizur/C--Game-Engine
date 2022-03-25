// This is free code released into the public domain.
// Drafted by Ángel in January 2019.
// angel.rodriguez@esne.edu

#include <Transform.hpp>
#include <RenderSystem.hpp>
#include <Entity.hpp>

namespace engine
{
    std::shared_ptr<glt::Render_Node> RenderSystem::rendererNode;
    std::list<Renderer*> RenderSystem::renderers;
    std::unordered_map<int, std::string> RenderSystem::keys;

    int RenderSystem::nodeCounter;

    RenderSystem::RenderSystem()
    {
        window.reset(new Window("Game", 1280, 720));

        window->enable_vsync();

        // Se crea el render node de OpenGL Toolkit:
        rendererNode.reset(new glt::Render_Node());

        std::shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1));
        std::shared_ptr< glt::Light  > light(new glt::Light);

        rendererNode->add("camera", camera);
        rendererNode->add("light", light);

        rendererNode->get("camera")->translate(glm::vec3(0.f, 0.f, 20.f));
        rendererNode->get("light")->translate(glm::vec3(10.f, 10.f, 10.f));
    }

    RenderSystem::~RenderSystem()
    {
        // En este caso es necesario definir explícitamente el destructor en el archivo
        // de implementación (CPP) para que el compilador pueda destruir el Render_Node
        // pese a que no hay código explícito.
    }

    void RenderSystem::PriorRun(bool& shouldExit)
    {
        Window::Event event;

        while (window->poll(event))
        {
            switch (event.type)
            {
                case Window::Event::CLOSE:
                {
                    shouldExit = false;
                    break;
                }

                case Window::Event::KEY_PRESSED:
                {
                    auto key = keys.find(event.data.keyboard.key_code);
                    if (key != keys.end())
                    {
                        MessageDispatcher::Send(Message("input", key->second));
                    }
                }
            }
        }
    }

    void RenderSystem::Run(bool & shouldExit)
    {
        
        WindowUpdate(shouldExit);

        //Se actualiza las posiciones de los elementos a renderizar
        for (auto & currentRenderer : renderers)
        {
            Transform * currentTransform = currentRenderer->gameobject->transform.get();

            currentRenderer->model->reset_transformation();
            currentRenderer->model->translate(currentTransform->position);
            currentRenderer->model->rotate_around_x(currentTransform->rotation.x);
            currentRenderer->model->rotate_around_y(currentTransform->rotation.y);
            currentRenderer->model->rotate_around_z(currentTransform->rotation.z); 
            currentRenderer->model->scale(currentTransform->scale.x, currentTransform->scale.y, currentTransform->scale.z);
        }

        // Se renderiza la escena y se intercambian los buffers de la ventana para
        // hacer visible lo que se ha renderizado:

        window->clear();
        rendererNode->render();
        window->swap_buffers();
    }

    void RenderSystem::WindowUpdate(bool & shouldExit)
    {
        // Se ajusta el viewport por si el tamaño de la ventana ha cambiado:

        GLsizei width = GLsizei(window->get_width());
        GLsizei height = GLsizei(window->get_height());

        rendererNode->get_active_camera()->set_aspect_ratio(float(width) / height);

        glViewport(0, 0, width, height);
    }

}
