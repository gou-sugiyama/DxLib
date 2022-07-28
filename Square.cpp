#include"DxLib.h"
#include "Square.h"

CSquare::CSquare() 
{
	x = 320;
	y = 240;
	height = D_SQUARE_HEIGHT;
	width = D_SQUARE_WIDTH;
}

void CSquare::Render()const
{
	DrawBoxAA(x - width / 2, y - height / 2, 
		x + width / 2, y + height / 2, 0xFFFFFF, TRUE);
}