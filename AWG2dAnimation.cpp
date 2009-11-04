//           AWG2dAnimation.cpp
//  Sun Oct 18 20:35:56 2009
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

#include <SDL/SDL.h>

#include "AWG2dAnimation.h"

AWG2dAnimation::AWG2dAnimation(void)
	:m_iCurrentFrame(0),
	m_iMaxFrames(0),
	m_iFrameInc(1),
	m_iFrameRate(100),
	m_lOldTime(0),
	m_bOscillate(false)
{
	
}

AWG2dAnimation::~AWG2dAnimation(void)
{
}

void AWG2dAnimation::Animate(void)
{
	if((m_lOldTime + m_iFrameRate) > SDL_GetTicks())
	{
        return;
    }

    m_lOldTime = SDL_GetTicks();

    m_iCurrentFrame += m_iFrameInc;

    if(m_bOscillate)
	{
        if(m_iFrameInc > 0)
		{
			if ( m_iCurrentFrame >= m_iMaxFrames - 1 )
			{
                m_iFrameInc = -m_iFrameInc;
            }
        }
		else
		{
            if(m_iCurrentFrame <= 0)
			{
                m_iFrameInc = -m_iFrameInc;
            }
        }
    }
	else
	{
		if ( m_iCurrentFrame >= m_iMaxFrames - 1 )
		{
            m_iCurrentFrame = 0;
        }
    }
}

void AWG2dAnimation::SetFrameRate(int iRate)
{
	m_iFrameRate = iRate;
}

int AWG2dAnimation::GetFrameRate()
{
	return m_iFrameRate;
}

void AWG2dAnimation::SetCurrentFrame(int iFrame)
{
	if ( iFrame > 0 || iFrame > m_iMaxFrames )
	{
		return;
	}

	m_iCurrentFrame = iFrame;
}

int AWG2dAnimation::GetCurrentFrame(void)
{
	return m_iCurrentFrame;
}

int AWG2dAnimation::GetMaxFrames()
{
	return m_iMaxFrames;
}

bool AWG2dAnimation::GetOscilate()
{
	return m_bOscillate;
}

void AWG2dAnimation::SetMaxFrames(int iFrames)
{
	if ( iFrames < 1 )
	{
		printf("Invalid Parameter to SetMaxFrames(%i)",iFrames);
		return;
	}

	m_iMaxFrames = iFrames;
}

void AWG2dAnimation::SetOscillate(bool bOscillate)
{
	m_bOscillate = bOscillate;
}