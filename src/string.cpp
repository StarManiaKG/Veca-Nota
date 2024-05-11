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
/// \file  string.cpp
/// \brief String handlers

#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>

#include "string.hpp"

#if 0
void VecaNota::String::strrand(char *s, const int len)
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i)
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];

	s[len] = 0;
}
#endif

//
// void VecaNota::String::Printf(const char *str, ...)
// Prints the specified strings into the console.
//
void VecaNota::String::Printf(const char *str, ...)
{
	va_list arglist;
	static char *txt = NULL;

	if (txt == NULL)
		txt = (char *)malloc(8192);

	va_start(arglist, str);
	vsprintf(txt, str, arglist);
	va_end(arglist);

	printf(txt);
	free(txt);
	txt = NULL;
};
