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

	CCircle circle1;
	circle1.SetisMovable();
	CCircle circle2(320,240,100);

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

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		
		circle2.Update();
		circle1.Update();
		CheckHitCircle(&circle2, &circle1);
		PreventOverlapCircle(&circle1, &circle2);
		circle2.Render();
		circle1.Render();

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
