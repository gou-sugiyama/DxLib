#pragma once
class CObject
{
protected:
	//ピボット位置
	float x = 0;
	float y = 0;

	//当たり判定
	float height = 0;
	float width = 0;

public:
	virtual void Update() = 0;
	virtual void Render()const = 0;

	//当たった時の処理
	virtual void HitAction() = 0;
	virtual void ReleaseAction() = 0;

	//get関数
	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetHeight()const { return height; }
	float GetWidth()const { return width; }
};

bool CheckOverLap(CObject* obj1, CObject* obj2);