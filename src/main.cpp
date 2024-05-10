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
/// \file  main.cpp
/// \brief Main source file

#include "renderer.hpp"
#include "string.hpp"

#ifdef _WIN32
int WinMain()
#else
int main()
#endif
{
	VecaNota::Renderer VN_SDL_Renderer;
	VecaNota::String VN_StringLib;

	if (VN_SDL_Renderer.CreateWindow())
		return 1;

	VN_StringLib.Printf("Hello World! %s\n", "This is STAR Speaking!");

	SDL_Quit();
	return 0;
}
