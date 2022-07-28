#include"DxLib.h"
#include "Circle.h"

CCircle::CCircle() 
{
	col = GetColor(D_COLOR_WHITE);
	x = 0;
	y = 0;
	radius = D_CIRCLE_RAD;
	height = radius;
	width = radius;

	isClick = false;
}
CCircle::~CCircle(){}

void CCircle::Update()
{
	int mouseX = 0;
	int mouseY = 0;
	GetMousePoint(&mouseX, &mouseY);
	x = (float)mouseX;
	y = (float)mouseY;
}

void CCircle::Render()const 
{
	DrawCircleAA(x, y, radius, 10, col);
}

void CCircle::HitAction()
{
	col = GetColor(D_COLOR_ORANGE);
	DrawString(0, 0, "HIT", col);
}

void CCircle::ReleaseAction() 
{
	col = GetColor(D_COLOR_WHITE);
	DrawString(0, 20, "RELEASE", col);
}