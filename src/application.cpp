#include "../include/application.h"

BDSM::Application::Application(std::string_view title, ImVec2 windowSize) : m_window(std::make_shared<Window>(title, windowSize)), m_ui(std::make_shared<UI>(m_window.get()->window, m_window.get()->renderer))
{}

void BDSM::Application::Run()
{
	bool done = false;
	SDL_Event e;
	while (!done)
	{
		while (SDL_PollEvent(&e))
		{
			ImGui_ImplSDL2_ProcessEvent(&e);
			if (e.type == SDL_QUIT)
				done = true;
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE && e.window.windowID == SDL_GetWindowID(m_window.get()->window))
				done = true;
		}

		Draw();
		m_ui.get()->Draw();
		m_ui.get()->DrawSDL();
		m_window.get()->Draw();
	}

}

void BDSM::Application::Draw()
{

}
