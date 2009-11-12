//           AWG2dApp.cpp
//  Sun Oct 18 16:57:07 2009
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

#include "AWG2dApp.h"
/*
#include "AWG2dArea.h"
#include "AWG2dCamera.h"
 */

AWG2dApp::AWG2dApp(void)
	:m_bRunning(true),
	m_bDebugMode(true),
	m_sdlSurfaceDisplay(NULL),
	m_sdlSurfaceTest(NULL)
{

}

AWG2dApp::~AWG2dApp(void)
{

}

int AWG2dApp::Run(void)
{
	if (!HandleArgs())
	{
	}

	if (Init() == false)
	{
        return -1;
    }

    SDL_Event Event;

    while(m_bRunning)
	{
        while(SDL_PollEvent(&Event))
		{
            OnEvent(&Event);
        }

        Loop();

        Render();
    }

    CleanUp();

    return 0;
}

bool AWG2dApp::HandleArgs()
{

	return true;
}

bool AWG2dApp::Init(void)
{
    DebugMessage("Begin Initialization:\n\n");
    DebugMessage("\tInitializing Everything...");
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL Init Everything failed");
        return false;
    }
    DebugMessage("Done!\n");

    DebugMessage("\tInitializing Video Mode...");
    if((m_sdlSurfaceDisplay = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
        printf("Screen failed to initialize");
        return false;
    }
    DebugMessage("Done!\n");

    DebugMessage("\tLoading Map...");
    if (!m_mapActive.Load("./data/maps/1.map",m_sdlSpriteList))
    {
        printf("Map Failed to load!");
        return false;
    }
    DebugMessage("Done!\n");

    /*
    if ((m_sdlSurfaceTest = AWG2dSprite::Load("./yoshi.bmp")) == NULL)
    {
            return false;
    }

    yoshi.SetMaxFrames(8);
    yoshi.SetOscillate(false);
    */

    // Load Background
    DebugMessage("\tLoading Background...");
    if ((m_sdlSurfaceBackground = AWG2dSprite::Load("./graphics/backgrounds/Water.png")) == NULL )
    {
            return false;
    }
    DebugMessage("Done!\n");

    //AWG2dSprite::Transparent(m_sdlSurfaceTest, 255, 0, 255);

    SDL_EnableKeyRepeat(1,SDL_DEFAULT_REPEAT_INTERVAL/3);

    DebugMessage("Initialization Complete!");
    
    return true;
}

void AWG2dApp::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT)
    {
        m_bRunning = false;
    }
}

void AWG2dApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    /*
    switch(sym)
    {
    case SDLK_UP:
		AWG2dCamera::staticCameraControl.Move( 0,  5);
		break;
    case SDLK_DOWN:
		AWG2dCamera::staticCameraControl.Move( 0, -5);
		break;
    case SDLK_LEFT:
		AWG2dCamera::staticCameraControl.Move( 5,  0);
		break;
    case SDLK_RIGHT:
		AWG2dCamera::staticCameraControl.Move(-5,  0);
		break;
    default:
		break;
    }
    */
}

void AWG2dApp::Render(void)
{
    //AWG2dSprite::Draw(m_sdlSurfaceDisplay,m_sdlSurfaceTest,0,0);
    //AWG2dSprite::Draw(m_sdlSurfaceDisplay,m_sdlSurfaceTest,0,0,100,100,100,100);
    //AWG2dSprite::Draw(m_sdlSurfaceDisplay,m_sdlSurfaceTest,290,220,0,yoshi.GetCurrentFrame()*64,64,64);
    AWG2dSprite::Draw(m_sdlSurfaceDisplay,m_sdlSurfaceBackground,0,0);

    for(int i = 0;i < AWG2dEntity::staticEntityList.size();i++)
    {
        if(!AWG2dEntity::staticEntityList[i])
        {
            continue;
        }

        AWG2dEntity::staticEntityList[i]->Render(m_sdlSurfaceDisplay);
    }

    SDL_Flip(m_sdlSurfaceDisplay);
}

void AWG2dApp::Loop(void)
{
    for(int i = 0;i < AWG2dEntity::staticEntityList.size();i++)
    {
        if(!AWG2dEntity::staticEntityList[i])
        {
            continue;
        }

        AWG2dEntity::staticEntityList[i]->Loop();
    }
}

void AWG2dApp::CleanUp(void)
{
    SDL_FreeSurface(m_sdlSurfaceDisplay);
    SDL_FreeSurface(m_sdlSurfaceTest);
    SDL_FreeSurface(m_sdlSurfaceBackground);

    int i;

    for(i = 0;i < AWG2dEntity::staticEntityList.size();i++)
    {
        if(!AWG2dEntity::staticEntityList[i])
        {
                continue;
        }

        AWG2dEntity::staticEntityList[i]->Cleanup();
    }

    for (i = 0; i < m_sdlSpriteList.size(); i++)
    {
        if (!m_sdlSpriteList[i])
        {
            continue;
        }

        SDL_FreeSurface(m_sdlSpriteList[i]);
    }

    AWG2dEntity::staticEntityList.clear();

    SDL_Quit();
}

void AWG2dApp::DebugMessage(const char *strMessage)
{
    if (m_bDebugMode)
    {
        printf(strMessage);
    }
}