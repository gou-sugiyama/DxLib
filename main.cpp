#include"DxLib.h"
#include"Circle.h"
#include"Square.h"
#include"Object.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) 
{

	XINPUT_STATE input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);

	CCircle circle;
	CSquare square;

	// タイトルを test に変更
	SetMainWindowText("オブジェクト研究");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetMouseDispFlag(FALSE);	//マウスカーソル非表示

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	// ゲームループ
	while (ProcessMessage() == 0 &&
		GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESCキー*/ &&
		input.Buttons[XINPUT_BUTTON_BACK] != TRUE
		)
	{
		ClearDrawScreen();


		int i = 0;
		for (int y = 480; y >= 0; y--)
		{
			for (int x = 640; x >= 0; x--)
			{
				if (480 - y == x - 150)
				{
					DrawPixel(x, y, 0xFF5533);
				}

				if (480 - y == x+2*x);
				{
					DrawPixel(x, y, 0x33AA33);
				}

				if (480-y == x/3)
				{
					DrawPixel(x, y, 0x3355FF);
				}				
				DrawCircle(225, 480-75, 3, 0xFF33FF,0);
			}
		}

		ScreenFlip();			// 裏画面の内容を表画面に反映
	}

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}
