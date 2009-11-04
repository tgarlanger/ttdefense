/***************************************************************************
 *            AWG2dAnimation.h
 *
 *  Sun Oct 18 20:35:56 2009
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

class AWG2dAnimation
{
private:
    int m_iCurrentFrame;
    int m_iFrameInc;
    int m_iFrameRate; //Milliseconds
    long m_lOldTime;
    int m_iMaxFrames;
    bool m_bOscillate;

public:
    AWG2dAnimation();

	~AWG2dAnimation(void);

    void Animate();

    void SetFrameRate(int iRate);

	int GetFrameRate();

    void SetCurrentFrame(int iFrame);

    int GetCurrentFrame();

	int GetMaxFrames();

	bool GetOscilate();

	void SetMaxFrames(int iFrames);

	void SetOscillate(bool bOscillate);
};