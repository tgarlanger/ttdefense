/**
 * \file    AWG2dScrollAnim.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Nov  1 12:41:52 2009
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
 * The AWG2dMap class represents a scrolling animation
 */

#pragma once

#include "AWG2dAnimation.h"
#include "AWG2dSprite.h"

/**
 * \class AWG2dScrollAnim AWG2dScrollAnim.h "AWG2dScrollAnim.h"
 * \brief AWG2dScrollAnim represents a scrolling animation
 *
 * Class is used for scrolling animations rather than frame based animations
 *
 * \see AWG2dAnimation
 * \see AWG2dSprite
 */
class AWG2dScrollAnim : public AWG2dAnimation
{
private:
    int m_iScrollRate; /**< scroll rate */
    bool m_bScrolling; /**< is it scrolling */
    int m_iFrameHeight; /**< height of an individual frame */
    int m_iImageHeight; /**< height of the entire image */

public:
    /**
     * Default Constructor
     */
    AWG2dScrollAnim();

    /**
     * Destructor
     */
    ~AWG2dScrollAnim();

    /**
     * Updates the animation
     *
     * \return nothing
     */
    void Animate();

    /**
     * Gets the current scroll rate
     *
     * \return the current scroll rate
     */
    int GetScrollRate();

    /**
     * Changes the scroll rate
     *
     * \param[in] iScrollRate the scroll rate to change to
     * \return noting
     */
    void SetScrollRate(const int iScrollRate);

    /**
     * Changes the maxmimum number of frames
     *
     * \param[in] iFrameHeight height of an individual frame
     * \param[in] iImageHeight height of the entire image
     * \return nothing
     */
    void SetMaxFrames(const unsigned int iFrameHeight, const unsigned int iImageHeight);
};