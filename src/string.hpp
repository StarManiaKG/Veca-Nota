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
/// \file  string.hpp
/// \brief String headers

#ifndef __string_hpp__
#define __string_hpp__

#pragma once

namespace VecaNota
{
	class String
	{
	public:
		static void Printf(const char *str, ...);
	};
};

#endif // __string_hpp__
