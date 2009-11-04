/***************************************************************************
 *            AWG2dMap.h
 *
 *  Sun Nov  1 16:01:16 2009
 *  Copyright  2009  Tony Garlanger
 *  <tgarlanger@gmail.com>
 ****************************************************************************/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#pragma once

#include "AWG2dTile.h"

#include <SDL/SDL.h>
#include <vector>

class AWG2dMap
{
private:
	int m_iRows;
	int m_iCols;

	std::vector< std::vector<int> > m_iMap;

public:
	AWG2dMap();

	~AWG2dMap();

	bool Load(char *strfile, const std::vector<SDL_Surface*> &sdlSpritelist);

	void Render(SDL_Surface *sdlSurfaceDisplay);

	int GetRows();

	int GetCols();

	int GetAt(int iRow, int iCol);
};