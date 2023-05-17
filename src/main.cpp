#include <iostream>

#include "imgui.h"
#include "../include/imgui_impl_sdl2.h"
#include "../include/imgui_impl_sdlrenderer.h"
#include <stdio.h>
#include <SDL.h>

#include "../include/application.h"

#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

using namespace BDSM;


int main(int argc, char** argv)
{
    Application app("Test");
    app.Run();
    return 0;
}