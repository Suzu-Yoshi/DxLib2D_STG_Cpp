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
#include "PLAYER.hpp"
#include "STAR.hpp"

//########## �O���[�o���I�u�W�F�N�g ##########
FPS *fps = new FPS(GAME_FPS_SPEED);							//FPS�N���X�̃I�u�W�F�N�g�𐶐�
KEYDOWN *keydown = new KEYDOWN();							//KEYDOWN�N���X�̃I�u�W�F�N�g�𐶐�
STAR *star[STAR_TATE_MAX][STAR_YOKO_MAX];					//���N���X�̃I�u�W�F�N�g�z��𐶐�

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	IMAGE *back = new IMAGE(MY_IMG_DIR_BACK, MY_IMG_NAME_BACK);	//�w�i�摜�𐶐�
	if (back->GetIsLoad() == false) { return -1; }				//�ǂݍ��ݎ��s��

	PLAYER *player = new PLAYER();	//�v���C���[����
	if (player->SetInitPlayer() == false) { return -1; }		//�v���C���[�̏����ݒ�

	player->SetIsKeyOperation(true);							//�L�����N�^�̓L�[���삪�ł���
	player->SetSpeed(CHARA_SPEED_1_SLOW);						//�L�����N�^�[�̑�����ݒ�

	for (int tate = 0; tate < STAR_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
		{
			star[tate][yoko] = new STAR();	//�X�̐��𐶐�
			if (star[tate][yoko]->SetInitStar(
				STAR_START_X + yoko * (STAR_WIDTH + STAR_MARGIN),
				STAR_START_Y + tate * (STAR_HEIGHT + STAR_MARGIN)
			) == false) {	return -1;	}		//���̏����ݒ�
			star[tate][yoko]->SetIsKeyOperation(false);								//�L�����N�^�̓L�[���삪�ł��Ȃ�
			star[tate][yoko]->SetSpeed(CHARA_SPEED_0_NONE);							//�L�����N�^�[�̑�����ݒ�
		}
	}

	while (TRUE)	//�������[�v
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		keydown->KeyDownUpdate();	//�L�[�̓��͏�Ԃ��X�V����

		fps->Update();				//FPS�̏���[�X�V]

		keydown->IsKeyDown(KEY_INPUT_LEFT);

		//�����������Q�[���̃V�[���������灥��������

		keydown->IsKeyDown(KEY_INPUT_UP);

		back->Draw(0, 0);

		for (int tate = 0; tate < STAR_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
			{
				star[tate][yoko]->Draw();		//���̕`��
				star[tate][yoko]->DrawAnime();	//�����̃A�j��
			}
		}

		player->Operation(keydown);
		player->OperationTama(keydown);
		player->Draw();
		player->OpeDrawTama();

		//�����������Q�[���̃V�[�������܂Ł���������

		fps->Draw(0, 0);				//FPS�̏���[�`��]

		ScreenFlip();				//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		fps->Wait();				//FPS�̏���[�҂�]
	}

	delete back;			//back��p��
	delete player;			//player��j��
	for (int tate = 0; tate < STAR_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < STAR_YOKO_MAX; yoko++)
		{
			delete star[tate][yoko];
		}
	}
	delete fps;				//FPS��j��
	delete keydown;			//keydown��j��

	DxLib_End();			//�c�w���C�u�����g�p�̏I������

	return 0;
}