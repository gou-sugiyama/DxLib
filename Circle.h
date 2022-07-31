#pragma once
#include"Object.h"
#define D_COLOR_WHITE 255,255,255
#define D_COLOR_ORANGE 255,128,0
#define D_CIRCLE_RAD 20.0f
class CCircle :public CObject
{
private:
	//色
	int col;

	//半径
	float radius;

	//クリックしているか
	bool isClick;

public:
	CCircle();
	~CCircle();
	void Update()override;
	void Render()const override;

	void HitAction()override;
	void OverLapAction()override;
	void ReleaseAction()override;

	float GetRadius()const{ return radius; }
};

