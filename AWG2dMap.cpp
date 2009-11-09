/**
 * \file    AWG2dMap.cpp
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
 * The AWG2dMap class represents the playing area of the game.
 */

#include <fstream>

#include "AWG2dMap.h"
#include "AWG2dTile.h"
#include "AWG2dSprite.h"

AWG2dMap::AWG2dMap()
{
}

AWG2dMap::~AWG2dMap()
{
}

bool AWG2dMap::Load(char *strFile, std::vector<SDL_Surface*> &sdlSpriteList)
{
    // Step 1:	open file
    std::ifstream infile;

    infile.open(strFile);

    if (!infile || infile.fail())
    {
        printf("Error opening file: %s\n",strFile);
        return false;
    }

    // Step 2:	Read number of tiles
    int iNumTiles;

    infile >> iNumTiles;

    if ( iNumTiles < 1 )
    {
        printf("Invalid Number of Tiles: %d\n",iNumTiles);
        return false;
    }

    // Step 3:  Read Tiles
    //	1) Sprite index
    //	2) File path
    //	3) read temp SDL Surface
    //	4) Push it to the back of the vector
    //	5) save address of last item to AWG2dTile
    char strTemp[256];
    int iIndex;
    SDL_Surface *sdlTemp = NULL;
    AWG2dTile *tileTemp = NULL;
    int iRows;
    int iCols;

    for ( int i = 0; i < iNumTiles; i++ )
    {
        // 1) Sprite index
        infile >> iIndex;

        if ( iIndex < 0 )
        {
            printf("Invalid Sprite Index: %d In Map File: %s\n",iIndex,strFile);
            return false;
        }

        char d = infile.get();

        printf("%c",d);

        // 2) File Path
        infile.getline(strTemp,256);

        if ( strlen(strTemp) < 5 )
        {
            printf("File Path Too Short: %s\n",strTemp);
            false;
        }

        // 3) Read temp SDL_Surface;
        sdlTemp = AWG2dSprite::Load(strTemp);

        // 4) Push it to the back of the vector
        sdlSpriteList.push_back(sdlTemp);

        // 5) save address of last item to AWG2dTile
        tileTemp = new AWG2dTile(sdlSpriteList.back());

        //AWG2dTile::staticTileList.push_back(tileTemp);
    }

    // Step 4:	Read number of rows
    infile >> iRows;

    // Step 5:	Read number of columns
    infile >> iCols;

    // Step 6:	Resize map
    m_veciMap.resize(iRows);

    for (int i = 0; i < iRows; i++)
    {
        m_veciMap[i].resize(iCols,0);
    }

    // Step 7:	Read each individual cell
    for (int j = 0; j < iRows; j++)
    {
        for (int k = 0; k < iCols; k++)
        {
            infile >> m_veciMap[j][k];
        }
    }
}

void AWG2dMap::Render(SDL_Surface *sdlSurfaceDisplay)
{
}

int AWG2dMap::GetRows()
{
    return m_iRows;
}

int AWG2dMap::GetCols()
{
    return m_iCols;
}

int AWG2dMap::GetAt(int iRow, int iCol)
{
    return m_veciMap[iRow][iCol];
}
