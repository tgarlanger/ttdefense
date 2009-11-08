/**
 * \file    AWG2dEvent.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Oct 18 20:12:14 2009
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
 * The AWG2dEvent class is a base class for handling SDL_Events.
 */

#pragma once

#include <SDL/SDL.h>

/**
 * \class AWG2dEvent AWG2dEvent.h "AWG2dEvent.h"
 * \brief AWG2dEvent is a base class for handling SDL_Events
 *
 * Class is used to handle SDL_Events
 *
 * \see AWG2dApp
 */
class AWG2dEvent
{
public:
    /**
     * Default Constructor
     */
    AWG2dEvent();

    /**
     * Destructor
     */
    virtual ~AWG2dEvent();

    /**
     * Handles SDL_Events
     *
     * \param[in] Event SDL_Event to handle
     * \return nothing
     */
    virtual void OnEvent(SDL_Event* Event);

    /**
     * Handles Input Focus Event
     *
     * \return nothing
     */
    virtual void OnInputFocus();

    /**
     * Handles Input Blur Event
     *
     * \return nothing
     */
    virtual void OnInputBlur();

    /**
     * Handles Key Down Event
     *
     * \param[in] sym keyboard symbol
     * \param[in] mod keyboard modifiers
     * \param[in] unicode unicode value of symbol
     * \return nothing
     */
    virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

    /**
     * Handles Key Up Event
     *
     * \param[in] sym keyboard symbol
     * \param[in] mod keyboard modifiers
     * \param[in] unicode unicode value of symbol
     * \return nothing
     */
    virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

    /**
     * Handles Mouse Focus Event
     *
     * \return nothing
     */
    virtual void OnMouseFocus();

    /**
     * Handles Mouse Blur Event
     *
     * \return nothing
     */
    virtual void OnMouseBlur();

    /**
     * Handles Mouse Movement Event
     *
     * \param[in] mX The x coordinate of the mouse
     * \param[in] mY The y coordinate of the mouse
     * \param[in] relX Relative x movement
     * \param[in] relY Relative y movement
     * \param[in] Left Is the left button pressed
     * \param[in] Right Is the right button pressed
     * \param[in] Middle Is the middle button pressed
     * \return nothing
     */
    virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

    /**
     * Handles Mouse Wheel Event
     *
     * \param[in] Up is the mouse scrolling up
     * \param[in] Down is the mouse scrolling down
     * \return nothing
     */
    virtual void OnMouseWheel(bool Up, bool Down);  //Not implemented

    /**
     * Handles Left Mouse Button Down Event
     *
     * \param[in] mX The x coordinate of the mouse
     * \param[in] mY The y coordinate of the mouse
     * \return nothing
     */
    virtual void OnLButtonDown(int mX, int mY);

    /**
     * Handles Left Mouse Button Up Event
     *
     * \param[in] mX The x coordinate of the mouse
     * \param[in] mY The y coordinate of the mouse
     * \return nothing
     */
    virtual void OnLButtonUp(int mX, int mY);

    /**
     * Handles Right Mouse Button Down Event
     *
     * \param[in] mX The x coordinate of the mouse
     * \param[in] mY The y coordinate of the mouse
     * \return nothing
     */
    virtual void OnRButtonDown(int mX, int mY);

    /**
     * Handles Right Mouse Button Up Event
     *
     * \param[in] mX The x coordinate of the mouse
     * \param[in] mY The y coordinate of the mouse
     * \return nothing
     */
    virtual void OnRButtonUp(int mX, int mY);

    /**
     * Handles Middle Mouse Button Down Event
     *
     * \param[in] mX The x coordinate of the mouse
     * \param[in] mY The y coordinate of the mouse
     * \return nothing
     */
    virtual void OnMButtonDown(int mX, int mY);

    /**
     * Handles Middle Mouse Button Up Event
     *
     * \param[in] mX The x coordinate of the mouse
     * \param[in] mY The y coordinate of the mouse
     * \return nothing
     */
    virtual void OnMButtonUp(int mX, int mY);

    /**
     * Handles Joy Stick Axis Event
     *
     * \return nothing
     */
    virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);

    /**
     * Handles Joy stick Button Down Event
     *
     * \return nothing
     */
    virtual void OnJoyButtonDown(Uint8 which, Uint8 button);

    /**
     * Handles Joy Stick Button Up Event
     *
     * \return nothing
     */
    virtual void OnJoyButtonUp(Uint8 which, Uint8 button);

    /**
     * Handles Joy Stick Hat Button Event
     *
     * \return nothing
     */
    virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);

    /**
     * Handles Joy Stick Ball Event
     *
     * \return nothing
     */
    virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);

    /**
     * Handles Minimize Event
     *
     * \return nothing
     */
    virtual void OnMinimize();

    /**
     * Handles Restore Event
     *
     * \return nothing
     */
    virtual void OnRestore();

    /**
     * Handles Resize Event
     *
     * \param[in] w width of window
     * \param[in] h height of window
     * \return nothing
     */
    virtual void OnResize(int w,int h);

    /**
     * Handles Expose Event
     *
     * \return nothing
     */
    virtual void OnExpose();

    /**
     * Handles Exit Event
     *
     * \return nothing
     */
    virtual void OnExit();

    /**
     * Handles User Event
     *
     * \return nothing
     */
    virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};