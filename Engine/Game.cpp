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
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (inhibitRight) {

		}
		else
		{
			vx = vx + 1;
			inhibitRight = true;
		}
	}

	else {
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (inhibitLeft) {

		}
		else
		{
			vx = vx - 1;
			inhibitLeft = true;
		}
	}

	else {
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (inhibitDown) {

		}
		else
		{
			vy = vy + 1;
			inhibitDown = true;
		}
	}

	else {
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitUp) {

		}
		else
		{
			vy = vy - 1;
			inhibitUp = true;
		}
	}

	else {
		inhibitUp = false;
	}

	x = x + vx;
	y = y + vy;

	if (x + 5 >= gfx.ScreenWidth) {
		x = 799 - 6;
		vx = 0;
	}

	if (x - 5 < 0) {
		x = 5;
		vx = 0;
	}

	if (y + 5 >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 6;
		vy = 0;
	}

	if (y - 5 < 0) {
		y = 5;
		vy = 0;
	}

	if (wnd.kbd.KeyIsPressed(VK_F1)) {
		r = 30;
		g = 150;
		b = 200;
	}
	else {
		r = 255;
		g = 255;
		b = 255;
	}

	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);

	// Determine if boxes are colliding
	// Max x is 200 + 5, 205
	// Min x is 200 - 5, 195
	// Max y is 500 + 5, 505
	// Min y is 500 - 5, 495

	if (x - 5 <= xa + 5 && x + 5 >= xa - 5
		&& y + 5 >= ya - 5 && y - 5 <= ya + 5) {
		colliding = true;
	}
	else {
		colliding = false;
	}
}

void Game::ComposeFrame()
{
	if (colliding) {
		r = 30;
		g = 150;
		b = 200;
	}
	else {
		r = 255;
		g = 255;
		b = 255;
	}
	if (shapeIsChanged) {
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

	else {
		gfx.PutPixel(-5 + x, -5 + y, r, g, b);
		gfx.PutPixel(-5 + x, -4 + y, r, g, b);
		gfx.PutPixel(-5 + x, -3 + y, r, g, b);
		gfx.PutPixel(-4 + x, -5 + y, r, g, b);
		gfx.PutPixel(-3 + x, -5 + y, r, g, b);
		gfx.PutPixel(-5 + x, 5 + y, r, g, b);
		gfx.PutPixel(-5 + x, 4 + y, r, g, b);
		gfx.PutPixel(-5 + x, 3 + y, r, g, b);
		gfx.PutPixel(-4 + x, 5 + y, r, g, b);
		gfx.PutPixel(-3 + x, 5 + y, r, g, b);
		gfx.PutPixel(5 + x, -5 + y, r, g, b);
		gfx.PutPixel(5 + x, -4 + y, r, g, b);
		gfx.PutPixel(5 + x, -3 + y, r, g, b);
		gfx.PutPixel(4 + x, -5 + y, r, g, b);
		gfx.PutPixel(3 + x, -5 + y, r, g, b);
		gfx.PutPixel(5 + x, 5 + y, r, g, b);
		gfx.PutPixel(5 + x, 4 + y, r, g, b);
		gfx.PutPixel(5 + x, 3 + y, r, g, b);
		gfx.PutPixel(4 + x, 5 + y, r, g, b);
		gfx.PutPixel(3 + x, 5 + y, r, g, b);
	}

	gfx.PutPixel(-5 + xa, -5 + ya, r, g, b);
	gfx.PutPixel(-5 + xa, -4 + ya, r, g, b);
	gfx.PutPixel(-5 + xa, -3 + ya, r, g, b);
	gfx.PutPixel(-4 + xa, -5 + ya, r, g, b);
	gfx.PutPixel(-3 + xa, -5 + ya, r, g, b);
	gfx.PutPixel(-5 + xa, 5 + ya, r, g, b);
	gfx.PutPixel(-5 + xa, 4 + ya, r, g, b);
	gfx.PutPixel(-5 + xa, 3 + ya, r, g, b);
	gfx.PutPixel(-4 + xa, 5 + ya, r, g, b);
	gfx.PutPixel(-3 + xa, 5 + ya, r, g, b);
	gfx.PutPixel(5 + xa, -5 + ya, r, g, b);
	gfx.PutPixel(5 + xa, -4 + ya, r, g, b);
	gfx.PutPixel(5 + xa, -3 + ya, r, g, b);
	gfx.PutPixel(4 + xa, -5 + ya, r, g, b);
	gfx.PutPixel(3 + xa, -5 + ya, r, g, b);
	gfx.PutPixel(5 + xa, 5 + ya, r, g, b);
	gfx.PutPixel(5 + xa, 4 + ya, r, g, b);
	gfx.PutPixel(5 + xa, 3 + ya, r, g, b);
	gfx.PutPixel(4 + xa, 5 + ya, r, g, b);
	gfx.PutPixel(3 + xa, 5 + ya, r, g, b);
}

void Game::DrawBox() {
	const int r_fixed = 0;
	const int g_fixed = 255;
	const int b_fixed = 0;

	gfx.PutPixel(-5 + xa, -5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + xa, -4 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + xa, -3 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-4 + xa, -5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-3 + xa, -5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + xa, 5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + xa, 4 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-5 + xa, 3 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-4 + xa, 5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(-3 + xa, 5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + xa, -5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + xa, -4 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + xa, -3 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(4 + xa, -5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(3 + xa, -5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + xa, 5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + xa, 4 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(5 + xa, 3 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(4 + xa, 5 + ya, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(3 + xa, 5 + ya, r_fixed, g_fixed, b_fixed);
}