//           AWG2dScrollAnim.cpp
//  Sun Nov  1 12:41:52 2009
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

#include "AWG2dScrollAnim.h"

AWG2dScrollAnim::AWG2dScrollAnim()
	:m_iScrollRate(10),
	m_bScrolling(1)
{
}

AWG2dScrollAnim::~AWG2dScrollAnim()
{
}

void AWG2dScrollAnim::Animate()
{
}

int AWG2dScrollAnim::GetScrollRate()
{
	return m_iScrollRate;
}

void AWG2dScrollAnim::SetScrollRate(const int iScrollRate)
{
	if ( iScrollRate < 1 )
	{
		printf("Invalid Parameter to SetScrollRate(%i)",iScrollRate);
		return;
	}
	
	m_iScrollRate = iScrollRate;
	
	if ( m_iScrollRate == 0 )
	{
		m_bScrolling = false;
	}
}

void AWG2dScrollAnim::SetMaxFrames(const unsigned int iFrameHeight, const unsigned int iImageHeight)
{
	m_iFrameHeight = iFrameHeight;
	m_iImageHeight = iImageHeight;
	
}