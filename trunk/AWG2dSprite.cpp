//           AWG2dSprite.cpp
//  Sun Oct 18 17:14:38 2009
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

#include "AWG2dSprite.h"

AWG2dSprite::AWG2dSprite(void)
{
}

AWG2dSprite::~AWG2dSprite(void)
{
}

SDL_Surface *AWG2dSprite::Load(char *strFileName)
{
	SDL_Surface *sdlSurfaceTemp;
	SDL_Surface *sdlSurfaceReturn;

	if ((sdlSurfaceTemp = IMG_Load(strFileName)) == NULL)
	{
		printf("Error Loding Image: %s\n",strFileName);
		return NULL;
	}

	sdlSurfaceReturn = SDL_DisplayFormat(sdlSurfaceTemp);

	SDL_FreeSurface(sdlSurfaceTemp);

	return sdlSurfaceReturn;
}

bool AWG2dSprite::Draw(SDL_Surface *sdlSurfaceDest, SDL_Surface *sdlSurfaceSprite, int iX, int iY)
{
	if(sdlSurfaceDest == NULL || sdlSurfaceSprite == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = iX;
    DestR.y = iY;

    SDL_BlitSurface(sdlSurfaceSprite, NULL, sdlSurfaceDest, &DestR);

    return true;
}

bool AWG2dSprite::Draw(SDL_Surface *sdlSurfaceDest, SDL_Surface *sdlSurfaceSprite, int iX, int iY, int iX2, int iY2, int iW, int iH)
{
    if(sdlSurfaceDest == NULL || sdlSurfaceSprite == NULL)
	{
        return false;
    }

    SDL_Rect DestR;

    DestR.x = iX;
    DestR.y = iY;

    SDL_Rect SrcR;

    SrcR.x = iX2;
    SrcR.y = iY2;
    SrcR.w = iW;
    SrcR.h = iH;

    SDL_BlitSurface(sdlSurfaceSprite, &SrcR, sdlSurfaceDest, &DestR);

    return true;
}

bool AWG2dSprite::Transparent(SDL_Surface* sdlSurfaceDest, int iR, int iG, int iB)
{
	if(sdlSurfaceDest == NULL)
	{
        return false;
    }

    SDL_SetColorKey(sdlSurfaceDest,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(sdlSurfaceDest->format,iR,iG,iB));

    return true;
}