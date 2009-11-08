/**
 * \file    AWG2dAnimation.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Nov  1 16:01:16 2009
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
 * The AWG2dAnimation class handles frames for an animation
 */

#pragma once

/**
 * \class AWG2dAnimation AWG2dAnimation.h "AWG2dAnimation.h"
 * \brief AWG2dAnimation handles frames for an animation
 *
 * Class handles the frame, rate, oscillation of an animation
 */
class AWG2dAnimation
{
private:
    int m_iCurrentFrame; /**< current frame of the animation */
    int m_iFrameInc; /**< amount to increment the frames */
    int m_iFrameRate; /**< frame rate in milliseconds */
    long m_lOldTime; /**< last time frame was updated */
    int m_iMaxFrames; /**< total number of frames */
    bool m_bOscillate; /**< true if animation oscillates */

public:
    /**
     * Default Constructor
     */
    AWG2dAnimation();

    /**
     * Destructor
     */
    ~AWG2dAnimation(void);

    /**
     * Updates the Current Frame
     *
     * \return nothing
     */
    void Animate();

    /**
     * Changes the frame rate
     *
     * \param[in] iRate new frame rate to use
     * \return nothing
     */
    void SetFrameRate(int iRate);

    /**
     * Gets the current frame rate
     *
     * \return Current frame rate
     */
    int GetFrameRate();

    /**
     * Changes the current frame
     *
     * \param[in] iFrame frame to set the animation to
     * \return nothing
     */
    void SetCurrentFrame(int iFrame);

    /**
     * Gets the current frame
     *
     * \return current frame
     */
    int GetCurrentFrame();

    /**
     * Gets the maximum frame number
     *
     * \return max frame number
     */
    int GetMaxFrames();

    /**
     * Gets the oscillation status
     *
     * \return true if the animation oscillates
     */
    bool GetOscilate();

    /**
     * Changes the maximum frame
     *
     * \param[in] iFrames value to set m_iMaxFrames to
     * \return nothing
     */
    void SetMaxFrames(int iFrames);

    /**
     * Changes the oscillation status
     *
     * \param[in] bOscillate value to set m_bOscillate to
     * \return nothing
     */
    void SetOscillate(bool bOscillate);
};