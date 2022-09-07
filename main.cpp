#include"DxLib.h"
#include"Circle.h"
#include"Square.h"
#include"Object.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) 
{

	XINPUT_STATE input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);

	CCircle circle;
	CSquare square;

	// �^�C�g���� test �ɕύX
	SetMainWindowText("�I�u�W�F�N�g����");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetMouseDispFlag(FALSE);	//�}�E�X�J�[�\����\��

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	// �Q�[�����[�v
	while (ProcessMessage() == 0 &&
		GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESC�L�[*/ &&
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

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
