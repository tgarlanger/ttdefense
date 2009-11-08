/**
 * \file    AWG2dTile.h
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
 * The AWG2dTile class represents an image on an AWG2dMap.
 */

#pragma once

#include <SDL/SDL.h>
#include <vector>

/**
 * \class AWG2dTile AWG2dTile.h "AWG2dTile.h"
 * \brief AWG2dTile class represents an image on an AWG2dMap
 *
 * Class is really nothing much more than a pointer to an SDL_Surface
 * in the global SDL_Surface list
 *
 * \see AWG2dMap
 */
class AWG2dTile
{
private:
    SDL_Surface *m_sdlSurfaceTile; /**< Pointer to the SDL_Surface */

    int m_iX; /**< The X coordinate */
    int m_iY; /**< The Y coordinate */
public:
    /**
     * Default Constructor
     * Probably Not Needed
     */
    AWG2dTile();

    /**
     * Parameterized Constructor
     *
     * \param[in] sdlSurface    Pointer to a SDL_Surface in the global list
     */
    AWG2dTile(SDL_Surface *sdlSurface);

    /**
     * Destructor
     */
    ~AWG2dTile();

    /**
     * Draws the AWG2dTile to the screen at (m_iX,m_iY)
     *
     * \param[out] sdlSurfaceDisplay SDL_Surfacce to render to
     * \return nothing
     */
    void Render(SDL_Surface *sdlSurfaceDisplay);

    /**
     * Static vector of all the Tiles
     */
    static std::vector<AWG2dTile*> staticTileList;
};