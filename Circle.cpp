#include"DxLib.h"
#include "Circle.h"

//---------------------------
// �R���X�g���N�^
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
}

//-----------------------------
// �f�X�g���N�^
//-----------------------------
CCircle::~CCircle(){}

//----------------------------
// �X�V
//----------------------------
void CCircle::Update()
{
	int mouseX = 0;
	int mouseY = 0;
	GetMousePoint(&mouseX, &mouseY);
	x = (float)mouseX;
	y = (float)mouseY;
}

//----------------------
// �`��
//----------------------
void CCircle::Render()const 
{
	DrawCircleAA(x, y, radius, 20, col);
}

//----------------------
// �����������̏���
//----------------------
void CCircle::HitAction()
{
	col = GetColor(D_COLOR_WHITE);
	DrawString(0, 0, "HIT", col);
}

//-----------------------------
// �d�Ȃ��Ă���Ԃ̏���
//-----------------------------
void CCircle::OverLapAction() 
{
	col = GetColor(D_COLOR_ORANGE);
	DrawString(0, 20, "OVERLAP", col);
}

//-------------------------
// ���ꂽ�Ƃ��̏���
//-------------------------
void CCircle::ReleaseAction() 
{
	col = GetColor(D_COLOR_WHITE);
	DrawString(0, 40, "RELEASE", col);
}