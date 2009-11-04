//           AWG2dEntity.cpp
//  Sun Oct 18 21:21:40 2009
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

#include "AWG2dEntity.h"

std::vector<AWG2dEntity*> AWG2dEntity::staticEntityList;

AWG2dEntity::AWG2dEntity(void)
	:m_sdlSurfaceEntity(NULL),
	m_fX(0.0f),
	m_fY(0.0f),
	m_iWidth(0),
	m_iHeight(0),
	m_iAnimState(0)
{
	
}

AWG2dEntity::~AWG2dEntity(void)
{
}

bool AWG2dEntity::Load(char *strFile, int iWidth, int iHeight, int iMaxFrames)
{
	if((m_sdlSurfaceEntity = AWG2dSprite::Load(strFile)) == NULL)
	{
        return false;
    }

    AWG2dSprite::Transparent(m_sdlSurfaceEntity, 255, 0, 255);

    this->m_iWidth = iWidth;
    this->m_iHeight = iHeight;

    m_awgAnimControl.SetMaxFrames(iMaxFrames);

    return true;
}

void AWG2dEntity::Loop()
{
	m_awgAnimControl.Animate();

	if ( (m_awgAnimControl.GetCurrentFrame() * m_iScrollRate) > (m_sdlSurfaceEntity->h - m_iHeight) )
	{
		if ( m_awgAnimControl.GetOscilate() )
		{
			m_awgAnimControl.SetFrameRate(m_awgAnimControl.GetFrameRate()*-1);
			m_awgAnimControl.Animate();
			m_awgAnimControl.Animate();
		}
		else
		{
			m_awgAnimControl.SetCurrentFrame(0);
		}
	}
}

void AWG2dEntity::Render(SDL_Surface *sdlSurfaceDisplay)
{
	if ( m_sdlSurfaceEntity == NULL || sdlSurfaceDisplay == NULL )
	{
		return;
	}

	if ( m_iScrollRate > 0 )
	{
		AWG2dSprite::Draw(sdlSurfaceDisplay,m_sdlSurfaceEntity,m_fX,m_fY,m_iAnimState*m_iWidth,m_awgAnimControl.GetCurrentFrame()*m_iScrollRate,m_iWidth,m_iHeight);
	}
	else
	{
		AWG2dSprite::Draw(sdlSurfaceDisplay,m_sdlSurfaceEntity,m_fX,m_fY,m_iAnimState*m_iWidth,m_awgAnimControl.GetCurrentFrame()*m_iHeight,m_iWidth,m_iHeight);
	}
}

void AWG2dEntity::Cleanup()
{
	if ( m_sdlSurfaceEntity )
	{
		SDL_FreeSurface(m_sdlSurfaceEntity);
	}

	m_sdlSurfaceEntity = NULL;
}

void AWG2dEntity::SetScrollRate(const int iScrollRate)
{
	m_iScrollRate = iScrollRate;

	m_awgAnimControl.SetMaxFrames((m_sdlSurfaceEntity->h - m_iHeight)/m_iScrollRate);
}