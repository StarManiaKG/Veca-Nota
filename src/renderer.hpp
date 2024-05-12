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
/// \file  renderer.hpp
/// \brief Renderer headers

#ifndef __renderer_hpp__
#define __renderer_hpp__

#pragma once

#include <SDL.h>
#include "SDL_video.h"
#include "SDL_render.h"

namespace VecaNota
{
	class Renderer
	{
	public:
		SDL_Window *Window;
		SDL_Renderer *Rendering;
		SDL_Event Events;

		int CreateWindow(int initflags, int windowflags);

	private:
		int icoSurface;
	};
};

#endif // __renderer_hpp__
