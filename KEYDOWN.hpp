/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* KEYDOWN.cpp     																				   */
/* KEYDOWN�N���X																				   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"

//########## �N���X�̒�` ##########

class KEYDOWN
{
private:
	static char AllKeyState[256];		//���ׂẴL�[�̏�Ԃ�����	//static�ŋ��ʂ̕ϐ����g�p����

public:
	static VOID KeyDownUpdate(VOID);	//�L�[�̓��͏�Ԃ��X�V����	//static�ŋ��ʂ̊֐����g�p����

	//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
	//���@���F�L�[�R�[�h
	BOOL IsKeyDown(int);

public:
	KEYDOWN();			//�R���X�g���N�^
	virtual ~KEYDOWN();	//�f�X�g���N�^
};


