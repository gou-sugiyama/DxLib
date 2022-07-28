#include "Object.h"
#include"Circle.h"

//-------------------------
// ��Βl�����߂�
//-------------------------
float absf(void* num) 
{
	if(*(float*)num<0)
	{
		*(float*)num = *(float*)num * -1;
	}
	return *(float*)num;
}

//--------------------------
// ���� ��`���d�Ȃ��Ă�����
//--------------------------
bool CheckOverLap(CObject* obj1, CObject* obj2)
{
	//�K�v�ȏ��̏���
	float distanceX = obj1->GetX() - obj2->GetX();
	float distanceY = obj1->GetY() - obj2->GetY();
	float rangeX = obj1->GetWidth() / 2 + obj2->GetWidth() / 2;
	float rangeY = obj1->GetHeight() / 2 + obj2->GetHeight() / 2;

	if (absf(&distanceX) <= rangeX && absf(&distanceY) <= rangeY) 
	{
		obj1->HitAction();
		obj2->HitAction();

		return true;
	}

	return false;
}