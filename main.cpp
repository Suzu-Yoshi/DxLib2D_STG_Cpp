/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* main.cpp     																				�@ */
/* C++��STG																						�@ */

//##########�w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "FPS.hpp"
#include "KEYDOWN.hpp"
#include "CHARACTOR.hpp"

#include <math.h>

//########## �}�N����` ##########
#define GAME_WIDTH	800		//��ʂ̉��̑傫��
#define GAME_HEIGHT	600		//��ʂ̏c�̑傫��
#define GAME_COLOR	32		//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_NAME	"GAME TITLE"		//�E�B���h�E�̃^�C�g��
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE�F�E�B���h�E���[�h / FALSE�F�t���X�N���[��

#define SET_WINDOW_ST_MODE_DEFAULT			0	//�f�t�H���g
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//�^�C�g���o�[�Ȃ�
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//�^�C�g���o�[�ƃt���[���Ȃ�
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//�t���[���Ȃ�

#define GAME_FPS_SPEED					   60

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	FPS *fps = new FPS(GAME_FPS_SPEED);							//FPS�N���X�̃I�u�W�F�N�g�𐶐�
	KEYDOWN *keydown = new KEYDOWN();							//KEYDOWN�N���X�̃I�u�W�F�N�g�𐶐�
	
	CHARACTOR *chara = new CHARACTOR();

	while (TRUE)	//�������[�v
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		keydown->KeyDownUpdate();	//�L�[�̓��͏�Ԃ��X�V����

		fps->Update();				//FPS�̏���[�X�V]

		keydown->IsKeyDown(KEY_INPUT_LEFT);
		
		//�����������Q�[���̃V�[���������灥��������

		keydown->IsKeyDown(KEY_INPUT_UP);

		chara->MoveUp();



		//�����������Q�[���̃V�[�������܂Ł���������

		fps->Draw(0,0);				//FPS�̏���[�`��]

		ScreenFlip();				//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		fps->Wait();				//FPS�̏���[�҂�]
	}

	delete fps;				//FPS��j��
	delete keydown;			//keydown��j��

	DxLib_End();			//�c�w���C�u�����g�p�̏I������

	return 0;
}