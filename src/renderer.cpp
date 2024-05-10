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

SDL_Window *Window = NULL;
SDL_Renderer *Rendering = NULL;

using namespace VecaNota;

int Renderer::CreateWindow(void)
{
	int flags = SDL_RENDERER_SOFTWARE|SDL_WINDOW_MINIMIZED;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		String::Printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create a window
	Window = SDL_CreateWindow("Veca-Nova",
							SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							320, 200, flags);

	if (Window == NULL)
	{
		String::Printf("Couldn't create window: %s\n", SDL_GetError());
		return 1;
	}

#if 0
	// Set a Window Icon	
	if (Window && icoSurface)
		SDL_SetWindowIcon(window, icoSurface);
#endif

	// Set a Renderer
	Rendering = SDL_CreateRenderer(Window,
							-1, SDL_RENDERER_SOFTWARE);

	if (Rendering == NULL)
	{
		String::Printf("Couldn't create rendering context: %s\n", SDL_GetError());
		return 1;
	}
	SDL_RenderSetLogicalSize(Rendering, 320, 200);

	return 0;
}
