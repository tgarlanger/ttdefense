/***************************************************************************
 *            AWG2dScrollAnim.h
 *
 *  Sun Nov  1 12:41:52 2009
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

#include "AWG2dAnimation.h"
#include "AWG2dSprite.h"

class AWG2dScrollAnim : public AWG2dAnimation
{
private:
	int m_iScrollRate;

	bool m_bScrolling;

	int m_iFrameHeight;

	int m_iImageHeight;

public:
	AWG2dScrollAnim();

	~AWG2dScrollAnim();

	void Animate();

	int GetScrollRate();

	void SetScrollRate(const int iScrollRate);

	void SetMaxFrames(const unsigned int iFrameHeight, const unsigned int iImageHeight);
};