/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

#include <algorithm>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
    auto x = wnd.mouse.GetPosX();
    auto y = wnd.mouse.GetPosY();
    bool swap = wnd.kbd.KeyIsPressed(GLFW_KEY_SPACE);
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            gfx.PutPixel(std::clamp(x + i, 0, static_cast<int>(Graphics::ScreenWidth) - 1), std::clamp(y + j, 0, static_cast<int>(Graphics::ScreenHeight) - 1), 
                swap ? 0 : 255, 0, swap ? 255 : 0);
            gfx.PutPixel(std::clamp(x - i - 1, 0, static_cast<int>(Graphics::ScreenWidth) - 1), std::clamp(y - j - 1, 0, static_cast<int>(Graphics::ScreenHeight) - 1), 
                Color(swap ? 255 : 0, 0, swap ? 0 : 255));
        }
    }
}
