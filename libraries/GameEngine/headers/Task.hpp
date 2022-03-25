//Codigo propiedad de Aitor Izurrategui

#pragma once

namespace engine
{
	/// <summary>
	/// Tarea ejecutada por el kernel
	/// </summary>
	class Task
	{
	public:
		Task() = default;
		virtual ~Task() = default;

		/// <summary>
		/// Utilizada para inicializar tareas en caso necesario
		/// </summary>
		void virtual Initialize() {}
		/// <summary>
		/// Funcion con prioridad de la tarea a ejecutar
		/// </summary>
		/// <param name="shouldExit">Booleano que setear a false para detener el programa</param>
		void virtual PriorRun(bool& shouldExit) {}

		/// <summary>
		/// Funcion de la tarea a ejecutar
		/// </summary>
		/// <param name="shouldExit">Booleano que setear a false para detener el programa</param>
		void virtual Run(bool& shouldExit) {}
	};
}