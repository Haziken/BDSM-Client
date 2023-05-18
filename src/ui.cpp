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

bool ButtonCenteredOnLine(const char* label, float alignment = 0.5f)
{
	ImGuiStyle& style = ImGui::GetStyle();

	float size = 150;
	float avail = ImGui::GetContentRegionAvail().x;

	float off = (avail - size) * alignment;
	if (off > 0.0f)
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

	return ImGui::Button(label, {150, 0});
}

void AlignForWidth(float width, float alignment = 0.5f)
{
	ImGuiStyle& style = ImGui::GetStyle();
	float avail = ImGui::GetContentRegionAvail().x;
	float off = (avail - width) * alignment;
	if (off > 0.0f)
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
}

void BDSM::UI::Draw()
{
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGuiIO& io1 = ImGui::GetIO();

	ImGui::Begin("t", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove);
	ImGui::SetWindowPos({ io1.DisplaySize.x / 2 - 250, io1.DisplaySize.y / 2 - 250 });
	if (!io.menuSelect)
	{
		AlignForWidth(ImGui::CalcTextSize("Menu").x);
		ImGui::Text("Menu");

		if (ButtonCenteredOnLine("Level")) io.menuSelect = 2;
		if (ButtonCenteredOnLine("Result table")) io.menuSelect = 1;

		if (ButtonCenteredOnLine("Exit")) exit(0);
	}
	if(io.menuSelect == 1)
	{
		AlignForWidth(ImGui::CalcTextSize("Result table").x);
		ImGui::Text("Result table");

		ImGui::SetCursorPosY(50);
		ImGui::BeginTable("1", 2, 0, {400, 0});
		ImGui::EndTable();

		ImGui::SetCursorPosY(450);

		if (ButtonCenteredOnLine("Exit")) io.menuSelect = 0;

	}
	if (io.menuSelect == 2)
	{
		AlignForWidth(ImGui::CalcTextSize("Level").x);
		ImGui::Text("Level");

		if (ButtonCenteredOnLine("Level 1"));
		if (ButtonCenteredOnLine("Level 2"));
		if (ButtonCenteredOnLine("Level 3"));

		if (ButtonCenteredOnLine("Exit")) io.menuSelect = 0;
	}
	ImGui::End();

}

void BDSM::UI::DrawSDL()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGui::Render();
	SDL_RenderSetScale(m_renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
}
