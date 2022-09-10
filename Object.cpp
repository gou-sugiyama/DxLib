#include"DxLib.h"
#include "Object.h"
#include<math.h>

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

//--------------------------------
// 円と矩形の当たり判定
//--------------------------------
bool CheckHitBox_Circle(CObject* box, CObject* circle) {

	//old, nowの更新
	box->UpdateFlg();
	circle->UpdateFlg();

	//必要な情報の準備
	float distance = pow(double(box->GetX()) - double(circle->GetX()), 2.0)
		+ pow(double(box->GetY()) - double(circle->GetY()), 2.0);
	float range = pow(double(box->GetWidth() / 2) + double(circle->GetWidth() / 2), 2.0);

	//-------------------------------
	// 	当たった瞬間
	//-------------------------------
	if (box->GetOldHitFlg() == false
		&& circle->GetOldHitFlg() == false
		&& distance <= range)
	{
		box->SetNowFlg(true);
		circle->SetNowFlg(true);

		box->HitAction();
		circle->HitAction();

		return true;
	}
	//------------------------------
	//	重なっている間
	//------------------------------
	else if (box->GetOldHitFlg() == true
		&& circle->GetOldHitFlg() == true
		&& distance <= range)
	{
		box->OverLapAction();
		circle->OverLapAction();
	}
	else //それ以外は当たっていない(false)
	{
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

//--------------------------
// 円と円の当たり判定 
//--------------------------
bool CheckHitCircle(CObject* obj1, CObject* obj2)
{
	//old, nowの更新
	obj1->UpdateFlg();
	obj2->UpdateFlg();

	//必要な情報の準備
	float distance = pow(double(obj1->GetX()) - double(obj2->GetX()), 2.0)
						+ pow(double(obj1->GetY()) - double(obj2->GetY()), 2.0);
	float range = pow(double(obj1->GetWidth() / 2) + double(obj2->GetWidth() / 2), 2.0);

	//-------------------------------
	// 	当たった瞬間
	//-------------------------------
	if (obj1->GetOldHitFlg() == false
		&& obj2->GetOldHitFlg() == false
		&& distance <= range)
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
	else if (obj1->GetOldHitFlg() == true
		&& obj2->GetOldHitFlg() == true
		&& distance <= range)
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