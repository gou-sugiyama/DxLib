#pragma once
#define D_CIRCLE_RAD 5.0f
class CCircle
{
private:
	//ピボット位置
	float x;
	float y;

	//半径
	float radius;

	//クリックしているか
	bool isClick;

public:
	CCircle();
	~CCircle();
	void Update();
	void Render();
};

