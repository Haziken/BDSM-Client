#pragma once

#include <SDL.h>
#include <string_view>
#include <iostream>

#include <imgui.h>

namespace BDSM
{
	class Window
	{
	public:
		Window(std::string_view title, ImVec2 windowSize);

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		SDL_Color backgroundColor = { 60,60,60,255 };

		void Draw();

		~Window();
	};
}