#pragma once
#include"Object.h"

#define D_SQUARE_HEIGHT 200.0f
#define D_SQUARE_WIDTH 200.0f
class CSquare : public CObject
{
public:
	CSquare();
	~CSquare() {}

	void Update()override {};
	void Render()const override;

	void HitAction()override{}
	void ReleaseAction()override {}
};

