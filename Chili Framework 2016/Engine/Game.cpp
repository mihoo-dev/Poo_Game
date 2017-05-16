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
	gfx.BeginFrame(); //erase
	UpdateModel();  
	ComposeFrame();   //render
	gfx.EndFrame();   //present
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{
		}
		else
		{
			vy -= 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{
		}
		else
		{
			vy += 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{
		}
		else
		{
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight)
		{
		}
		else
		{
			vx += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		vx = 0;
		vy = 0;
	}

	x = x + vx;
	y = y + vy;

	if (x + 5 > gfx.ScreenWidth)
	{
		x = gfx.ScreenWidth - 5;
	}
	if (x - 5 < 0)
	{
		x = 5;
	}
	if (y + 5 >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6;
	}
	if (y - 5 < 0)
	{
		y = 5;
	}

	controlIsPressed = false;
	if (x > 200 && x < 300)
	{
		controlIsPressed = true;
	}
	

	
}

void Game::ComposeFrame()
{	
	if (controlIsPressed)
	{
		//gfx = graphics
		
		if (wnd.kbd.KeyIsPressed(VK_SHIFT))
		{
			gfx.PutPixel(x - 3, y, 0, 255, 255);
			gfx.PutPixel(x - 6, y, 0, 255, 255);
			gfx.PutPixel(x - 5, y, 0, 255, 255);
			gfx.PutPixel(x + 5, y, 0, 255, 255);
			gfx.PutPixel(x + 6, y, 0, 255, 255);
			gfx.PutPixel(x + 3, y, 0, 255, 255);
			gfx.PutPixel(x, y - 3, 0, 255, 255);
			gfx.PutPixel(x, y - 6, 0, 255, 255);
			gfx.PutPixel(x, y - 5, 0, 255, 255);
			gfx.PutPixel(x, y + 5, 0, 255, 255);
			gfx.PutPixel(x, y + 6, 0, 255, 255);
			gfx.PutPixel(x, y + 3, 0, 255, 255);
		}
		else
		{
			gfx.PutPixel(x - 5, y, 0, 255, 255);
			gfx.PutPixel(x - 4, y, 0, 255, 255);
			gfx.PutPixel(x - 3, y, 0, 255, 255);
			gfx.PutPixel(x + 3, y, 0, 255, 255);
			gfx.PutPixel(x + 4, y, 0, 255, 255);
			gfx.PutPixel(x + 5, y, 0, 255, 255);
			gfx.PutPixel(x, y - 5, 0, 255, 255);
			gfx.PutPixel(x, y - 4, 0, 255, 255);
			gfx.PutPixel(x, y - 3, 0, 255, 255);
			gfx.PutPixel(x, y + 3, 0, 255, 255);
			gfx.PutPixel(x, y + 4, 0, 255, 255);
			gfx.PutPixel(x, y + 5, 0, 255, 255);
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		gfx.PutPixel(x - 3, y, 255, 255, 255);
		gfx.PutPixel(x - 6, y, 255, 255, 255);
		gfx.PutPixel(x - 5, y, 255, 255, 255);
		gfx.PutPixel(x + 5, y, 255, 255, 255);
		gfx.PutPixel(x + 6, y, 255, 255, 255);
		gfx.PutPixel(x + 3, y, 255, 255, 255);
		gfx.PutPixel(x, y - 3, 255, 255, 255);
		gfx.PutPixel(x, y - 6, 255, 255, 255);
		gfx.PutPixel(x, y - 5, 255, 255, 255);
		gfx.PutPixel(x, y + 5, 255, 255, 255);
		gfx.PutPixel(x, y + 6, 255, 255, 255);
		gfx.PutPixel(x, y + 3, 255, 255, 255);
	}
	else
	{
		gfx.PutPixel(x - 5, y, 255, 255, 255);
		gfx.PutPixel(x - 4, y, 255, 255, 255);
		gfx.PutPixel(x - 3, y, 255, 255, 255);
		gfx.PutPixel(x + 3, y, 255, 255, 255);
		gfx.PutPixel(x + 4, y, 255, 255, 255);
		gfx.PutPixel(x + 5, y, 255, 255, 255);
		gfx.PutPixel(x, y - 5, 255, 255, 255);
		gfx.PutPixel(x, y - 4, 255, 255, 255);
		gfx.PutPixel(x, y - 3, 255, 255, 255);
		gfx.PutPixel(x, y + 3, 255, 255, 255);
		gfx.PutPixel(x, y + 4, 255, 255, 255);
		gfx.PutPixel(x, y + 5, 255, 255, 255);
	}
	
}
