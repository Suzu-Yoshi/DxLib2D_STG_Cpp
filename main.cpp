/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* main.cpp     																				�@ */
/* C++��STG																						�@ */

//##########�w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "main.hpp"
#include "FPS.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"
#include "ANIMATION.hpp"
#include "CHARACTOR.hpp"

//########## �O���[�o���I�u�W�F�N�g ##########
FPS *fps = new FPS(GAME_FPS_SPEED);							//FPS�N���X�̃I�u�W�F�N�g�𐶐�
KEYDOWN *keydown = new KEYDOWN();							//KEYDOWN�N���X�̃I�u�W�F�N�g�𐶐�

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	IMAGE *jiki = new IMAGE(MY_IMG_DIR_JIKI, MY_IMG_NAME_JIKI_1);
	if (jiki->GetIsLoad() == false) { return -1; };	//�摜�ǂݍ��݃`�F�b�N

	ANIMATION *baku = new ANIMATION(MY_ANIME_DIR_BAKU, MY_ANIME_NAME_BAKU_1, 16, 16, 1, BAKU_1_HEIGHT, BAKU_1_HEIGHT, 0.05, true);
	if (baku->GetIsLoad() == false) { return -1; };	//�摜�ǂݍ��݃`�F�b�N

	CHARACTOR * chara = new CHARACTOR(CHARA_SPEED_FAST);
	if (chara->GetIsCreate() == false) { return -1; };	//�L�����N�^�쐬�`�F�b�N

	chara->SetX_Y(0, GAME_HEIGHT / 2 - chara->GetWidth() / 2);	//�L�����N�^����ʂ̔����̈ʒu�ɕ\��
	chara->SetIsKeyOperation(true);	//�L�����N�^�̓L�[���삪�ł���

	while (TRUE)	//�������[�v
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		keydown->KeyDownUpdate();	//�L�[�̓��͏�Ԃ��X�V����

		fps->Update();				//FPS�̏���[�X�V]

		keydown->IsKeyDown(KEY_INPUT_LEFT);

		//�����������Q�[���̃V�[���������灥��������

		keydown->IsKeyDown(KEY_INPUT_UP);

		jiki->Draw();
		baku->Draw();

		chara->Operation(keydown);
		chara->Draw();

		//�����������Q�[���̃V�[�������܂Ł���������

		fps->Draw(0, 0);				//FPS�̏���[�`��]

		ScreenFlip();				//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		fps->Wait();				//FPS�̏���[�҂�]
	}

	delete jiki;

	delete fps;				//FPS��j��
	delete keydown;			//keydown��j��
	delete baku;


	DxLib_End();			//�c�w���C�u�����g�p�̏I������

	return 0;
}