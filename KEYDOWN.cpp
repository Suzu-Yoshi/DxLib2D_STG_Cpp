/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* KEYDOWN.cpp     																				   */
/* KEYDOWN�N���X																				   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "KEYDOWN.hpp"

//########## �N���X�̒�` ##########

//�C���X�^���X�𐶐�
char KEYDOWN::AllKeyState[256];

//�L�[�̓��͏�Ԃ��X�V����
VOID KEYDOWN::KeyDownUpdate(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL KEYDOWN::IsKeyDown(int keycode)
{
	if (this->AllKeyState[keycode] != 0)
		return TRUE;
	else
		return FALSE;
}

//�R���X�g���N�^
KEYDOWN::KEYDOWN()
{
}

//�f�X�g���N�^
KEYDOWN::~KEYDOWN()
{
}


//########## �O���I�u�W�F�N�g ##########
extern KEYDOWN *keydown;