#pragma once
#define D_CIRCLE_RAD 5.0f
class CCircle
{
private:
	//�s�{�b�g�ʒu
	float x;
	float y;

	//���a
	float radius;

	//�N���b�N���Ă��邩
	bool isClick;

public:
	CCircle();
	~CCircle();
	void Update();
	void Render();
};

