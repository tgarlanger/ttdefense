/**
 * \file    AWG2dApp.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Oct 18 16:57:07 2009
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
 * The AWG2dApp class is the main controller of the application
 */

#pragma once

#include <vector>

#include "AWG2dSprite.h"
#include "AWG2dConsts.h"
#include "AWG2dEvent.h"
#include "AWG2dAnimation.h"
#include "AWG2dEntity.h"
#include "AWG2dMap.h"

/**
 * \class AWG2dApp AWG2dApp.h "AWG2dApp.h"
 * \brief AWG2dApp is the main controller of the application
 *
 * Class handles initializing, rendering, looping and cleanup
 *
 * \see AWG2dSprite
 * \see AWG2dConsts
 * \see AWG2dEvent
 * \see AWG2dAnimation
 * \see AWG2dEntity
 * \see AWG2dMap
 */
class AWG2dApp : public AWG2dEvent
{
private:
    bool m_bRunning;    /**< true if the application is running */
    bool m_bDebugMode;  /**< true if the application is in debug mode */

    SDL_Surface *m_sdlSurfaceDisplay; /**< surface to display to*/
    SDL_Surface *m_sdlSurfaceTest; /**< used for testing */

    SDL_Surface *m_sdlSurfaceBackground; /**< background image surface */

    AWG2dMap m_mapActive;

    /**
     * List of all available sprites
     */
    std::vector<SDL_Surface*> m_sdlSpriteList;

    /**
     * Parses the command line arguments and handles settings
     *
     * \return wether the arguments were valid and applicaion should run
     */
    bool HandleArgs();

    /**
     * Display a message if in debug mode
     *
     * \param[in] strMessage Message to display
     * \return nothing
     */
    void DebugMessage(const char *strMessage);

    AWG2dAnimation yoshi; /**< will be removed */

    AWG2dEntity Entity1; /**< will be removed */
	
public:
    /**
     * Default Constructor
     */
    AWG2dApp(void);

    /**
     * Destructor
     */
    ~AWG2dApp(void);

    /**
     * Runs the application
     *
     * \return error code
     */
    int Run(void);

    /**
     * Initialize the application
     *
     * \returns whether or not the initialization was successful
     */
    bool Init(void);

    /**
     * Handles any SDL_Events that occur while running
     *
     * \return nothing
     */
    void OnEvent(SDL_Event* Event);

    /**
     * Handles keyboard input
     *
     * \param[in] sym keyboard symbol
     * \param[in] mod keyboard modifiers
     * \param[in] unicode unicode value of symbol
     * \return nothing
     */
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

    /**
     * Draws the AWG2dApp to the screen
     *
     * \return nothing
     */
    void Render(void);

    /**
     * Main loop of the application, other functions are called from here
     *
     * \return nothing
     */
    void Loop(void);

    /**
     * Cleans up application, frees memory
     */
    void CleanUp(void);
};