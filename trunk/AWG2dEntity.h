/***************************************************************************
 *            AWG2dEntity.h
 *
 *  Sun Oct 18 21:21:40 2009
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

#include "AWG2dAnimation.h"
#include "AWG2dSprite.h"

class AWG2dEntity
{
protected:
	AWG2dAnimation m_awgAnimControl;
	SDL_Surface *m_sdlSurfaceEntity;

	int m_iScrollRate;

public:
	AWG2dEntity(void);
	~AWG2dEntity(void);

	virtual bool Load(char *strFile, int iWidth, int iHeight, int iMaxFrames);
	virtual void Loop();
	virtual void Render(SDL_Surface *sdlSurfaceDisplay);
	virtual void Cleanup();

	virtual void SetScrollRate(const int iScrollRate);

	float m_fX;
	float m_fY;
	int m_iWidth;
	int m_iHeight;
	int m_iAnimState;

	static std::vector<AWG2dEntity*> staticEntityList;
};