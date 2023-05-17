#include "../include/ui.h"

#include <SDL.h>
#include "../include/imgui_impl_sdl2.h"
#include "../include/imgui_impl_sdlrenderer.h"

BDSM::UI::UI(SDL_Window* window, SDL_Renderer* renderer) : m_window(window), m_renderer(renderer)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer_Init(renderer);
}

void BDSM::UI::Draw()
{
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Test");

	ImGui::Text("TEST");

	ImGui::End();
}

void BDSM::UI::DrawSDL()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGui::Render();
	SDL_RenderSetScale(m_renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
}
