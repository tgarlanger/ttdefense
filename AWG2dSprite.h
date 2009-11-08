/**
 * \file    AWG2dSprite.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Oct 18 17:14:38 2009
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
 * The AWG2dSprite class is static class for drawing SDL_Surfaces.
 */

#pragma once

#include <SDL/SDL_image.h>

/**
 * \class AWG2dSprite AWG2dSprite.h "AWG2dSprite.h"
 * \brief AWG2dSprite static class for drawing SDL_Surfaces
 *
 * Class is used for a drawing an SDL_Surface to the screen
 */
class AWG2dSprite
{
private:

public:

	AWG2dSprite(void);

	~AWG2dSprite(void);

	static SDL_Surface *Load(char *strFileName);
	static bool Draw(SDL_Surface *sdlSurfaceDest, SDL_Surface *sdlSurfaceSprite, int iX, int iY);
	static bool Draw(SDL_Surface *sdlSurfaceDest, SDL_Surface *sdlSurfaceSprite, int iX, int iY, int iX2, int iY2, int iW, int iH);
	static bool Transparent(SDL_Surface* sdlSurfaceDest, int iR, int iG, int iB);
};