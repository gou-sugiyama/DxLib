#include"DxLib.h"
#include "Circle.h"

CCircle::CCircle() {
	x = 0;
	y = 0;
	radius = D_CIRCLE_RAD;
}
CCircle::~CCircle(){}

void CCircle::Update() {
	int mouseX = 0;
	int mouseY = 0;
	GetMousePoint(&mouseX, &mouseY);
	x = (float)mouseX;
	y = (float)mouseY;
}

void CCircle::Render() {
	DrawCircleAA(x, y, radius, 10, 0xFFFFFF);
}