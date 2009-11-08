/**
 * \file    AWG2dTile.cpp
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Nov  1 16:24:18 2009
 *
 * \section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 * 
 * \section DESCRIPTION
 *
 * The AWG2dTile class represents the image on an AWG2dMap.
 */

#include "AWG2dTile.h"
#include "AWG2dSprite.h"

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

void AWG2dTile::Render(SDL_Surface *sdlSurfaceDisplay)
{
    AWG2dSprite::Draw(sdlSurfaceDisplay,m_sdlSurfaceTile,m_iX,m_iY);
}