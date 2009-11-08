/**
 * \file    AWG2dEntity.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Oct 18 21:21:40 2009
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
 * The AWG2dEntity class represents a viewable object on the screen.
 */
 
#pragma once

#include <vector>

#include "AWG2dAnimation.h"
#include "AWG2dSprite.h"
/**
 * \class AWG2dEntity AWG2dEntity.h "AWG2dEntity.h"
 * \brief AWG2dEntity represents an object viewed on screen
 *
 * Class is used to display a viewable object on the screen
 *
 * \see AWG2dAnimation
 * \see AWG2dSprite
 */
class AWG2dEntity
{
protected:
    AWG2dAnimation m_awgAnimControl; /**< controls the animation of the entity*/
    SDL_Surface *m_sdlSurfaceEntity; /**< surface to display to screen */

    int m_iScrollRate; /**< how much to scroll the image by */

public:
    /**
     * Default Constructor
     */
    AWG2dEntity(void);

    /**
     * Destructor
     */
    ~AWG2dEntity(void);

    /**
     * Load an entity from a file
     *
     * \param[in] strFile string representing the file to open
     * \param[in] iWidth width of a frame
     * \param[in] iHeight height of a frame
     * \param[in] iMaxFrames total frames of the animation
     * \return wether the load was successful
     */
    virtual bool Load(char *strFile, int iWidth, int iHeight, int iMaxFrames);

    /**
     * Updates the entity
     *
     * \return nothing
     */
    virtual void Loop();

    /**
     * Draws the AWG2dEntity to the screen
     *
     * \param[out] sdlSurfaceDisplay SDL_Surfacce to render to
     * \return nothing
     */
    virtual void Render(SDL_Surface *sdlSurfaceDisplay);

    /**
     * Cleans up entity, frees memory
     */
    virtual void Cleanup();

    /**
     * changes the scroll rate
     *
     * \param[in] iScrollRate new scroll rate to use
     * \return nothing
     */
    virtual void SetScrollRate(const int iScrollRate);

    float m_fX;         /**< The x coordinate */
    float m_fY;         /**< The y coordinate */
    int m_iWidth;       /**< width of a frame*/
    int m_iHeight;      /**< height of a frame*/
    int m_iAnimState;   /**< state of the animation*/

    /**
     * Static vector of all the entities
     */
    static std::vector<AWG2dEntity*> staticEntityList;
};