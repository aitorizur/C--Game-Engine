//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <System.hpp>
#include <sdl.h>

namespace engine
{
	class TimeSystem : public System
	{
	public:

		float currentFrameTime;
		float lastFrameTime;

		/// <summary>
		/// Tiempo en segundos que ha transcurrido desde el ultimo frame
		/// </summary>
		static float deltaTime;

		TimeSystem () = default;
		~TimeSystem () override = default;

		void Initialize() override
		{
			lastFrameTime = 0.0f;
			currentFrameTime = 0.0f;
			deltaTime = 0.0f;
		}
		void Run(bool& shouldExit) override
		{
			currentFrameTime = SDL_GetTicks();
			deltaTime = (currentFrameTime - lastFrameTime) * 0.001f;
			lastFrameTime = SDL_GetTicks();
		}
	};
}