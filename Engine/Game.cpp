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
	// 800 x 600

	x = x - velocityX;
	y = y + velocityY;


	if (wnd.kbd.KeyIsPressed(VK_F1)) {
		r = 30;
		g = 150;
		b = 200;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		velocityX = velocityX + 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		velocityX = velocityX - 0.05;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		velocityY = velocityY - 0.05;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		velocityY = velocityY + 0.05;
	}
}

void Game::ComposeFrame()
{
	if (x == 50) {
		x = 400;
	}

	else if (x == 799) {

	}

	else if (y == 1) {

	}

	else if (y == 599) {

	}

	else {
		gfx.PutPixel(-5 + x, y, r, g, b);
		gfx.PutPixel(-4 + x, y, r, g, b);
		gfx.PutPixel(-3 + x, y, r, g, b);
		gfx.PutPixel(3 + x, y, r, g, b);
		gfx.PutPixel(4 + x, y, r, g, b);
		gfx.PutPixel(5 + x, y, r, g, b);
		gfx.PutPixel(x, -5 + y, r, g, b);
		gfx.PutPixel(x, -4 + y, r, g, b);
		gfx.PutPixel(x, -3 + y, r, g, b);
		gfx.PutPixel(x, 3 + y, r, g, b);
		gfx.PutPixel(x, 4 + y, r, g, b);
		gfx.PutPixel(x, 5 + y, r, g, b);
	}
}
