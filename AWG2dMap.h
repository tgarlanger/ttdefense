/**
 * \file    AWG2dMap.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Nov  1 16:01:16 2009
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
 * The AWG2dMap class represents the playing area of the game.
 */

#pragma once

#include "AWG2dTile.h"

#include <SDL/SDL.h>
#include <vector>

/**
 * \class AWG2dMap AWG2dMap.h "AWG2dMap.h"
 * \brief AWG2dMap represents the map viewed on screen
 *
 * Class is made up of a 2d array of integers which contains the indexes into
 * a list of Tiles
 *
 * \see AWG2dTile
 */
class AWG2dMap
{
private:
    int m_iRows; /**< Number of rows in the map */
    int m_iCols; /**< Number of columns in the map */

    /**
     * 2d Array of integers representing indexes into Tile list
     */
    std::vector< std::vector<int> > m_veciMap;

    /**
     * List of available tiles
     */
    std::vector<AWG2dTile *> m_vectileTiles;

public:
    /**
     * Default constructor
     */
    AWG2dMap();

    /**
     * Destructor
     */
    ~AWG2dMap();

    /**
     * Load a map from a file
     *
     * \param[in] strFile string representing the file to open
     * \param[out] sdlSpriteList list of global sprites
     * \return wether or not the load was successful
     */
    bool Load(char *strFile, std::vector<SDL_Surface*> & sdlSpriteList);

    /**
     * Draws the AWG2dMap to the screen
     *
     * \param[out] sdlSurfaceDisplay SDL_Surfacce to render to
     * \return nothing
     */
    void Render(SDL_Surface *sdlSurfaceDisplay);

    /**
     * Gets the number of rows in the map
     *
     * \return number of rows in the map
     */
    int GetRows();

    /**
     * Gets the number of columns in the map
     *
     * \return number of columns in the map
     */
    int GetCols();

    /**
     * Gets the value at (iRow,iCol) in the map
     *
     * \param[in] iRow Row "coordinate"
     * \param[in] iCol Column "coordinate"
     * \return value at (iRow,iCol)
     */
    int GetAt(int iRow, int iCol);
};