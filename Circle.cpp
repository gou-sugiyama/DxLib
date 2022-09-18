#include"DxLib.h"
#include "Circle.h"

//---------------------------
// コンストラクタ
//---------------------------
CCircle::CCircle() 
{
	col = GetColor(D_COLOR_WHITE);
	x = 0;
	y = 0;
	radius = D_CIRCLE_RAD;
	height = radius * 2;
	width = radius * 2;

	isClick = false;
	isMovable = false;
}

//---------------------------
// 引数付きコンストラクタ
//---------------------------
CCircle::CCircle(float x, float y,float radius )
{
	col = GetColor(D_COLOR_WHITE);
	this->x = x;
	this->y = y;
	this->radius = radius;
	height = radius * 2;
	width = radius * 2;

	isClick = false;
	isMovable = false;
}

//-----------------------------
// デストラクタ
//-----------------------------
CCircle::~CCircle(){}

//----------------------------
// 更新
//----------------------------
void CCircle::Update()
{
	if (isMovable)
	{
		int mouseX = 0;
		int mouseY = 0;
		GetMousePoint(&mouseX, &mouseY);
		if (isClick == true)
		{
			x += 2;
		}
		else
		{
			x = (float)mouseX;
		y = (float)mouseY;
		}

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			isClick = true;
		}

		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
		{
			isClick = false;
		}
	}
}

//----------------------
// 描画
//----------------------
void CCircle::Render()const 
{
	DrawCircleAA(x, y, radius, 20, col);
	
	{
		int i = 0;
		DrawFormatString(0, 150 + i++ * 20, 0x22FF88, "x:%lf", x);
		DrawFormatString(0, 150 + i++ * 20, 0x22FF88, "y:%lf", y);

		int mouseX;
		int mouseY;
		GetMousePoint(&mouseX, &mouseY);
		//mouse
		DrawFormatString(0, 150 + i++ * 20, 0x2288FF,
			"Mouse:x:%d",mouseX );
		DrawFormatString(0, 150 + i++ * 20, 0x2288FF,
			"Mousey:%d", mouseY);
	}
}

//----------------------
// 当たった時の処理
//----------------------
void CCircle::HitAction()
{
	col = GetColor(D_COLOR_WHITE);
	DrawString(0, 0, "HIT", col);
}

//-----------------------------
// 重なっている間の処理
//-----------------------------
void CCircle::OverLapAction() 
{
	col = GetColor(D_COLOR_ORANGE);
	DrawString(0, 20, "OVERLAP", col);
}

//-------------------------
// 離れたときの処理
//-------------------------
void CCircle::ReleaseAction() 
{
	col = GetColor(D_COLOR_WHITE);
	DrawString(0, 40, "RELEASE", col);
}