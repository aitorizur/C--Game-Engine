//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <memory>
#include <Light.hpp>
#include <list>
#include <Window.hpp>
#include <Render_Node.hpp>
#include <System.hpp>
#include <Renderer.hpp>
#include <Model.hpp>
#include <string>


#include <unordered_map>
#include <set>

#include <MessageDispatcher.hpp>

namespace engine
{
    /// <summary>
    /// Sistema que se encarga de la creación y actualización de la ventana y de el dibujo de los modelos. También se encarga de registrar los inputs.
    /// </summary>
    class RenderSystem : public System
    {
        std::shared_ptr<Window> window;

        static std::shared_ptr<glt::Render_Node> rendererNode;
        static std::list<Renderer*> renderers;
        static std::unordered_map<int, std::string> keys;

        static int nodeCounter;

    public:

        RenderSystem();
        ~RenderSystem();

        /// <summary>
        /// Anade un Renderer al ciclo de tareas para que se renderize
        /// </summary>
        static void AddRenderer(Renderer* givenRenderer, const std::shared_ptr<glt::Model> model)
        {
            renderers.push_back(givenRenderer);
            AddModel(model);
        }

        /// <summary>
        /// Anade un modelo a la escena de opengl
        /// </summary>
        static void AddModel(const std::shared_ptr<glt::Model> model)
        {
            rendererNode->add(std::to_string(nodeCounter), model);
            ++nodeCounter;
        }

        /// <summary>
        /// Asocia una accion a una tecla
        /// </summary>
        /// <param name="actionName">Nombre de la accion</param>
        /// <param name="key">Tecla asociada a la accion</param>
        static void AddKeyAction(const std::string& actionName, Keyboard::Key_Code key)
        {
            keys.emplace(std::make_pair(key, actionName));
        }

        void PriorRun(bool& shouldExit) override;
        void Run(bool & shouldExit) override;
        void WindowUpdate(bool & shouldExit);
    };

}