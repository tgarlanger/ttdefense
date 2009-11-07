//           AWG2dTile.cpp
//  Sun Nov  1 16:24:18 2009
//  Copyright  2009  Tony Garlanger
//  <tgarlanger@gmail.com>

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA

#include "AWG2dTile.h"

std::vector<AWG2dTile*> AWG2dTile::staticTileList;

AWG2dTile::AWG2dTile(SDL_Surface *sdlSurface)
{
    // Save the index of the surface
    m_sdlSurfaceTile = sdlSurface;

    // Now push this tile to the back
    staticTileList.push_back(this);
}

AWG2dTile::~AWG2dTile()
{
    // Nothing Needed, deletion of SDL_Surface is handled elsewhere
}