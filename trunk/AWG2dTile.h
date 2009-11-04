/***************************************************************************
 *            AWG2dTile.h
 *
 *  Sun Nov  1 16:24:18 2009
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

#include <SDL/SDL.h>
#include <vector>

class AWG2dTile
{
private:
	SDL_Surface *m_sdlSurfaceTile;

public:
	AWG2dTile();

	~AWG2dTile();

	void Render(SDL_Surface *sdlSurfaceDisplay);
	
	static std::vector<AWG2dTile*> staticTileList;
};