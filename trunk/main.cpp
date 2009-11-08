/**
 * \file    main.cpp
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sun Nov  1 16:24:18 2009
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
 * The main function.
 */

#include <SDL/SDL.h>

#include "AWG2dApp.h"

/**
 * The main procedure.  Does the following:
 *  - Creates instance of AWG2dApp
 *  - Executes the Run() function
 *  - Returns the return code from Run()
 *
 * \param argv the command line
 * \param argc the number of options in the command line
 * \return return code
 * \author Tony Garlanger
 */
int main ( int argc, char *argv[] )
{
	AWG2dApp theApp;

	return theApp.Run();
}