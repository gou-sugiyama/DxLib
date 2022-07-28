#pragma once
class CObject
{
protected:
	//�s�{�b�g�ʒu
	float x = 0;
	float y = 0;

	//�����蔻��
	float height = 0;
	float width = 0;

public:
	virtual void Update() = 0;
	virtual void Render()const = 0;

	//�����������̏���
	virtual void HitAction() = 0;
	virtual void ReleaseAction() = 0;

	//get�֐�
	float GetX()const { return x; }
	float GetY()const { return y; }
	float GetHeight()const { return height; }
	float GetWidth()const { return width; }
};

bool CheckOverLap(CObject* obj1, CObject* obj2);