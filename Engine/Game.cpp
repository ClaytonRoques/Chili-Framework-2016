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
	int x = 400;
	int y = 300;
	// 800 x 600

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		x = x - 200;

		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			y = y - 150;
		}

		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			y = y + 150;
		}

		gfx.PutPixel(-5 + x, y, 255, 255, 255);
		gfx.PutPixel(-4 + x, y, 255, 255, 255);
		gfx.PutPixel(-3 + x, y, 255, 255, 255);
		gfx.PutPixel(3 + x, y, 255, 255, 255);
		gfx.PutPixel(4 + x, y, 255, 255, 255);
		gfx.PutPixel(5 + x, y, 255, 255, 255);
		gfx.PutPixel(x, -5 + y, 255, 255, 255);
		gfx.PutPixel(x, -4 + y, 255, 255, 255);
		gfx.PutPixel(x, -3 + y, 255, 255, 255);
		gfx.PutPixel(x, 3 + y, 255, 255, 255);
		gfx.PutPixel(x, 4 + y, 255, 255, 255);
		gfx.PutPixel(x, 5 + y, 255, 255, 255);
	}

	else if (wnd.kbd.KeyIsPressed(VK_UP)) {
		y = y - 150;

		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			x = x + 200;
		}

		gfx.PutPixel(-5 + x, y, 255, 255, 255);
		gfx.PutPixel(-4 + x, y, 255, 255, 255);
		gfx.PutPixel(-3 + x, y, 255, 255, 255);
		gfx.PutPixel(3 + x, y, 255, 255, 255);
		gfx.PutPixel(4 + x, y, 255, 255, 255);
		gfx.PutPixel(5 + x, y, 255, 255, 255);
		gfx.PutPixel(x, -5 + y, 255, 255, 255);
		gfx.PutPixel(x, -4 + y, 255, 255, 255);
		gfx.PutPixel(x, -3 + y, 255, 255, 255);
		gfx.PutPixel(x, 3 + y, 255, 255, 255);
		gfx.PutPixel(x, 4 + y, 255, 255, 255);
		gfx.PutPixel(x, 5 + y, 255, 255, 255);
	}
	
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		x = x + 200;

		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			y = y + 150;
		}

		gfx.PutPixel(-5 + x, y, 255, 255, 255);
		gfx.PutPixel(-4 + x, y, 255, 255, 255);
		gfx.PutPixel(-3 + x, y, 255, 255, 255);
		gfx.PutPixel(3 + x, y, 255, 255, 255);
		gfx.PutPixel(4 + x, y, 255, 255, 255);
		gfx.PutPixel(5 + x, y, 255, 255, 255);
		gfx.PutPixel(x, -5 + y, 255, 255, 255);
		gfx.PutPixel(x, -4 + y, 255, 255, 255);
		gfx.PutPixel(x, -3 + y, 255, 255, 255);
		gfx.PutPixel(x, 3 + y, 255, 255, 255);
		gfx.PutPixel(x, 4 + y, 255, 255, 255);
		gfx.PutPixel(x, 5 + y, 255, 255, 255);
	}

	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		y = y + 150;
		gfx.PutPixel(-5 + x, y, 255, 255, 255);
		gfx.PutPixel(-4 + x, y, 255, 255, 255);
		gfx.PutPixel(-3 + x, y, 255, 255, 255);
		gfx.PutPixel(3 + x, y, 255, 255, 255);
		gfx.PutPixel(4 + x, y, 255, 255, 255);
		gfx.PutPixel(5 + x, y, 255, 255, 255);
		gfx.PutPixel(x, -5 + y, 255, 255, 255);
		gfx.PutPixel(x, -4 + y, 255, 255, 255);
		gfx.PutPixel(x, -3 + y, 255, 255, 255);
		gfx.PutPixel(x, 3 + y, 255, 255, 255);
		gfx.PutPixel(x, 4 + y, 255, 255, 255);
		gfx.PutPixel(x, 5 + y, 255, 255, 255);
	}

	else {
		gfx.PutPixel(-5 + x, y, 255, 255, 255);
		gfx.PutPixel(-4 + x, y, 255, 255, 255);
		gfx.PutPixel(-3 + x, y, 255, 255, 255);
		gfx.PutPixel(3 + x, y, 255, 255, 255);
		gfx.PutPixel(4 + x, y, 255, 255, 255);
		gfx.PutPixel(5 + x, y, 255, 255, 255);
		gfx.PutPixel(x, -5 + y, 255, 255, 255);
		gfx.PutPixel(x, -4 + y, 255, 255, 255);
		gfx.PutPixel(x, -3 + y, 255, 255, 255);
		gfx.PutPixel(x, 3 + y, 255, 255, 255);
		gfx.PutPixel(x, 4 + y, 255, 255, 255);
		gfx.PutPixel(x, 5 + y, 255, 255, 255);
	}
}
