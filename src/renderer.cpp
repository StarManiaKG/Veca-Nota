// VECA-NOTA
//-----------------------------------------------------------------------------
//
// Copyright (C) 2024 by StarManiaKG
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License or 'LICENSE' file for more details.
//
//-----------------------------------------------------------------------------
/// \file  renderer.cpp
/// \brief Renderer and SDL info

#include <iostream>

#include "renderer.hpp"
#include "string.hpp"

using namespace VecaNota;

//
// int Renderer::CreateWindow(int initflags, int windowflags, int rendererflags)
// Creates a new screen window, based on the given 'initflags', 'windowflags', and 'rendererflags'.
//
int Renderer::CreateWindow(int initflags, int windowflags, int rendererflags)
{
	VecaNota::Renderer VN_SDL_Renderer;
	VecaNota::String VN_StringLib;

	if (SDL_Init(initflags) != 0)
	{
		VN_StringLib.Printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create a window
	VN_SDL_Renderer.Window = SDL_CreateWindow("Veca-Nova",
							SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							320, 200, windowflags);

	if (VN_SDL_Renderer.Window == NULL)
	{
		VN_StringLib.Printf("Couldn't create window: %s\n", SDL_GetError());
		return 1;
	}

#if 0
	// Set a Window Icon	
	if (VN_SDL_Renderer.Window && VN_SDL_Renderer.icoSurface)
		SDL_SetWindowIcon(window, VN_SDL_Renderer.icoSurface);
#endif

	// Set a Renderer
	VN_SDL_Renderer.Rendering = SDL_CreateRenderer(VN_SDL_Renderer.Window, -1, rendererflags);
	if (VN_SDL_Renderer.Rendering == NULL)
	{
		VN_StringLib.Printf("Couldn't create rendering context: %s\n", SDL_GetError());
		return 1;
	}

	SDL_RenderSetLogicalSize(VN_SDL_Renderer.Rendering, 320, 200);
	return 0;
}
