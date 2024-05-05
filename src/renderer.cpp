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

int Renderer::CreateWindow(void)
{
	if ((SDL_Init(SDL_INIT_VIDEO) != 0) || (SDL_Init(SDL_INIT_EVERYTHING) != 0))
	{
		String::Printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create a window //
	Renderer::window = SDL_CreateWindow("Veca-Nova", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			320, 200, SDL_RENDERER_SOFTWARE);

	if (Renderer::window == NULL)
	{
		String::Printf("Couldn't create window: %s\n", SDL_GetError());
		return SDL_FALSE;
	}

#if 0
	// Set a Window Icon //	
	if (Renderer::window && icoSurface)
		SDL_SetWindowIcon(window, icoSurface);
#endif

	// Set a Renderer //
	Renderer::rendering = SDL_CreateRenderer(Renderer::window, -1, SDL_RENDERER_SOFTWARE);
	if (Renderer::rendering == NULL)
	{
		String::Printf("Couldn't create rendering context: %s\n", SDL_GetError());
		return 1;
	}
	SDL_RenderSetLogicalSize(Renderer::rendering, 320, 200);

	return 0;
}
