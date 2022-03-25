//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <System.hpp>
#include <MessageObserver.hpp>
#include <unordered_map>
#include <Keyboard.hpp>
#include <RenderSystem.hpp>
#include <MessageDispatcher.hpp>

namespace engine
{
	/// <summary>
	/// Sistema que corre en el kernel. Utilizado para añadir acciones relacionadas a teclas
	/// </summary>
	class InputSystem : public System, public MessageObserver
	{

		static std::unordered_map<std::string, bool> actions;

	public:

		InputSystem()
		{
			MessageDispatcher::AddObserver("input", this);
		}

		~InputSystem() override = default;

		void Run(bool& shouldExit) override
		{
			ResetMap();
		}

		/// <summary>
		/// Resetea los booleanos asociados a las acciones cada frame para que se puedan volver a setear a true al pulsar teclas
		/// </summary>
		void ResetMap()
		{
			for (auto& currentAction : actions)
			{
				currentAction.second = false;
			}
		}

		void handle(const Message & message) override
		{
			auto iterator = actions.find(message.action);
			if (iterator != actions.end())
			{
				iterator->second = true;
			}
		}

		/// <summary>
		/// Devuelve un booleano en funcion de si la tecla asociada a la accion ha sido pulsada o no ese frame
		/// </summary>
		/// <param name="actionName">Nombre de la accion previamente asignada</param>
		/// <returns></returns>
		static bool GetAction(const std::string & actionName)
		{
			auto iterator = actions.find(actionName);
			if (iterator != actions.end())
			{
				return iterator->second;
			}
			else
			{
				return false;
			}
		}

		/// <summary>
		/// Añade una accion asociada a una tecla
		/// </summary>
		/// <param name="actionName">Nombre de la accion a asginar</param>
		/// <param name="key">Tecla asignada a la accion</param>
		static void AddAction(const std::string & actionName, Keyboard::Key_Code key)
		{
			actions.emplace(std::make_pair(actionName, false));
			RenderSystem::AddKeyAction(actionName, key);
		}
	};
}