#include "Object.h"
#include"math.h"
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
// ��`�Ƌ�`�̓����蔻�� 
//--------------------------
bool CheckHitBox(CObject* obj1, CObject* obj2)
{
	//old, now�̍X�V
	obj1->UpdateFlg();
	obj2->UpdateFlg();

	//�K�v�ȏ��̏���
	float distanceX = obj1->GetX() - obj2->GetX();
	float distanceY = obj1->GetY() - obj2->GetY();
	float rangeX = obj1->GetWidth() / 2 + obj2->GetWidth() / 2;
	float rangeY = obj1->GetHeight() / 2 + obj2->GetHeight() / 2;

	//-------------------------------
	// 	���������u��
	//-------------------------------
	if (obj1->GetOldHitFlg() == false 
		&& obj2->GetOldHitFlg() == false
		&&absf(&distanceX) <= rangeX 
		&& absf(&distanceY) <= rangeY) 
	{
		obj1->SetNowFlg(true);
		obj2->SetNowFlg(true);

		obj1->HitAction();
		obj2->HitAction();

		return true;
	}
	//------------------------------
	//	�d�Ȃ��Ă����
	//------------------------------
	else if(obj1->GetOldHitFlg() == true 
		&& obj2->GetOldHitFlg() == true
		&& absf(&distanceX) <= rangeX
		&& absf(&distanceY) <= rangeY)
	{
		obj1->OverLapAction();
		obj2->OverLapAction();
	}
	else //����ȊO�͓������Ă��Ȃ�(false)
	{
		obj1->SetNowFlg(false);
		obj2->SetNowFlg(false);
	}


	//-----------------
	//  ���ꂽ�Ƃ�
	//-----------------
	if (obj1->GetOldHitFlg() == true
		&& obj2->GetOldHitFlg() == true
		&& obj1->GetNowHitFlg() == false
		&& obj2->GetNowHitFlg() == false)
	{
		obj1->ReleaseAction();
		obj2->ReleaseAction();
	}

	return false;
}

#include"DxLib.h"
//--------------------------------
// �~�Ƌ�`�̓����蔻��
//--------------------------------
bool CheckHitBox_Circle(CObject* box, CCircle* circle) 
{
	//�K�v�ȏ��̏���
	float diagonal = (box->GetHeight() / 2) * (box->GetHeight() / 2)
						+ (box->GetWidth() / 2) * (box->GetWidth() / 2);
	float distance = (box->GetX() - circle->GetX()) * (box->GetX() - circle->GetX())
						+ (box->GetY() - circle->GetY()) * (box->GetY() - circle->GetY());

	DrawFormatString(0, 20 * 4, 0xFFFFFF, "%.1lf",sqrt(diagonal)+ circle->GetRadius());
	DrawFormatString(0, 20 * 5, 0xFFFFFF, "%.1lf", sqrt(distance) );

	if (sqrt(distance) <= (sqrt(diagonal) + circle->GetRadius())) 
	{
		return CheckHitBox(box, circle);
	}
	else
	{
		//old, now�̍X�V
		box->UpdateFlg();
		circle->UpdateFlg();

		box->SetNowFlg(false);
		circle->SetNowFlg(false);
	}

	//-----------------
	//  ���ꂽ�Ƃ�
	//-----------------
	if (box->GetOldHitFlg() == true
		&& circle->GetOldHitFlg() == true
		&& box->GetNowHitFlg() == false
		&& circle->GetNowHitFlg() == false)
	{
		box->ReleaseAction();
		circle->ReleaseAction();
	}
	return false;
}