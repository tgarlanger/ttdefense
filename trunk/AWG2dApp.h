/***************************************************************************
 *            AWG2dApp.h
 *
 *  Sun Oct 18 16:57:07 2009
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

#include <vector>

#include "AWG2dSprite.h"
#include "AWG2dConsts.h"
#include "AWG2dEvent.h"
#include "AWG2dAnimation.h"
#include "AWG2dEntity.h"
 
class AWG2dApp : public AWG2dEvent
{
private:
	bool m_bRunning;
	bool m_bDebugMode;

	SDL_Surface *m_sdlSurfaceDisplay;
	SDL_Surface *m_sdlSurfaceTest;

	SDL_Surface *m_sdlSurfaceBackground;

	std::vector<SDL_Surface*> m_sdlSpriteArray;

	bool HandleArgs();

	AWG2dAnimation yoshi;

	AWG2dEntity Entity1;
	
public:
	AWG2dApp(void);

	~AWG2dApp(void);

	int Run(void);

	bool Init(void);

	void OnEvent(SDL_Event* Event);

	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

	void Render(void);

	void Loop(void);

	void CleanUp(void);
};