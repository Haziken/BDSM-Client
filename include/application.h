#pragma once 

#include <memory>
#include <string_view>

#include <imgui.h>

#include "./window.h"
#include "./ui.h"
#include "./imgui_impl_sdl2.h"
#include "./imgui_impl_sdlrenderer.h"

namespace BDSM
{
	class Application
	{
	public:
		Application(std::string_view title, ImVec2 windowSize = { 1280, 720 });

		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		void Run();

	private:

		void Draw();

		std::shared_ptr<Window> m_window;
		std::shared_ptr<UI> m_ui;

	};
}