#pragma once

#include <functional>
#include <string_view>
#include <imgui.h>

struct SDL_Renderer;
struct SDL_Window;

namespace BDSM
{
	class UI
	{
	public:

		struct IO
		{
			int menuSelect = 0;
			std::function<void(std::string_view)> contextSelect;
		};

		UI(SDL_Window* window, SDL_Renderer* renderer);

		void Draw();
		void DrawSDL();

		IO io;
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
	};
}