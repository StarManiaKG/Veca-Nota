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
//#include <windows.h>
#if !defined (main)
//#define SDLMAIN
#endif
#endif

#ifdef SDLMAIN
#include "SDL_main.h"
#elif defined(FORCESDLMAIN)
extern int SDL_main(int argc, char *argv[]);
#endif

//
// int SDL_main(int argc, char **argv)
// int main(int argc, char **argv)
//
// Extremely self-explanitory.
//
#ifdef FORCESDLMAIN
int SDL_main(int argc, char **argv)
#else
#ifdef _WIN32
int WinMain(int argc, char **argv)
#else
int main(int argc, char **argv)
#endif
#endif
{
	int exit = false;

	VecaNota::Renderer VN_SDL_Renderer;
	VecaNota::String VN_StringLib;

	if (VN_SDL_Renderer.CreateWindow(SDL_INIT_VIDEO, SDL_RENDERER_SOFTWARE))
		return 1;

	//for (;;)
	while (true)
	{
		VN_StringLib.Printf("Hello World! %s\n", "This is STAR Speaking!");

		while (SDL_PollEvent(&VN_SDL_Renderer.Events))
		{
			switch (VN_SDL_Renderer.Events.type)
			{
#if 0
				case SDL_WINDOWEVENT:
				{
					if (VN_SDL_Renderer.Events.window.event & SDL_WINDOWEVENT_CLOSE)
					{
						exit = true;
						break;
					}
				}
#endif

				case SDL_QUIT:
				case SDL_APP_TERMINATING:
					exit = true;
					break;

				default:
					break;
			}
		}

		if (exit)
		{
			SDL_DestroyWindow(VN_SDL_Renderer.Window);
			SDL_Quit();

			break;
		}
	}

	return 0;
}
