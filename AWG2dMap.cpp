//           AWG2dMap.cpp
//  Sun Nov  1 16:01:16 2009
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

#include <fstream>

#include "AWG2dMap.h"

AWG2dMap::AWG2dMap()
{
}

AWG2dMap::~AWG2dMap()
{
}

bool AWG2dMap::Load(char *strfile, const std::vector<SDL_Surface*> &sdlSpritelist)
{
	// Step 1:	open file
	std::ifstream infile;

	infile.open(strfile);

	if (!infile)
	{
		printf("Error opening file: %s\n",strfile);
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

	// Step 3:	Read Tiles
	//			1) Sprite index
	//			2) File path
	//			3) read temp SDL Surface
	//			4) Push it to the back of the vector
	//			5) save address of last item to AWG2dTile
	char *strTemp = new char[256];
	int iIndex;
	SDL_Surface *sdlTemp = NULL;
	
	for ( int i = 0; i < iNumTiles; i++ )
	{
		// 1) Sprite index
		infile >> iIndex;
		
		if ( iIndex < 0 )
		{
			printf("Invalid Sprite Index: %d In Map File: %s\n",iIndex,strfile);
			return false;
		}

		// 2) File Path
		infile.getline(strTemp,256);

		if ( strlen(strTemp) < 5 )
		{
			printf("File Path Too Short: %s\n",strTemp);
			false;
		}

		// 3) Read temp SDL_Surface;
		
	}

	// Step 4:	Read number of rows

	// Step 5:	Read number of columns

	// Step 6:	Resize map

	// Step 7:	Read each individual cell
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
	return m_iMap[iRow][iCol];
}
