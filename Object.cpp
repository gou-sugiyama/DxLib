#include "Object.h"
#include"math.h"
#include"Circle.h"

//-------------------------
// 絶対値を求める
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
// 矩形と矩形の当たり判定 
//--------------------------
bool CheckHitBox(CObject* obj1, CObject* obj2)
{
	//old, nowの更新
	obj1->UpdateFlg();
	obj2->UpdateFlg();

	//必要な情報の準備
	float distanceX = obj1->GetX() - obj2->GetX();
	float distanceY = obj1->GetY() - obj2->GetY();
	float rangeX = obj1->GetWidth() / 2 + obj2->GetWidth() / 2;
	float rangeY = obj1->GetHeight() / 2 + obj2->GetHeight() / 2;

	//-------------------------------
	// 	当たった瞬間
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
	//	重なっている間
	//------------------------------
	else if(obj1->GetOldHitFlg() == true 
		&& obj2->GetOldHitFlg() == true
		&& absf(&distanceX) <= rangeX
		&& absf(&distanceY) <= rangeY)
	{
		obj1->OverLapAction();
		obj2->OverLapAction();
	}
	else //それ以外は当たっていない(false)
	{
		obj1->SetNowFlg(false);
		obj2->SetNowFlg(false);
	}


	//-----------------
	//  離れたとき
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
// 円と矩形の当たり判定
//--------------------------------
bool CheckHitBox_Circle(CObject* box, CCircle* circle) 
{
	//必要な情報の準備
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
		//old, nowの更新
		box->UpdateFlg();
		circle->UpdateFlg();

		box->SetNowFlg(false);
		circle->SetNowFlg(false);
	}

	//-----------------
	//  離れたとき
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