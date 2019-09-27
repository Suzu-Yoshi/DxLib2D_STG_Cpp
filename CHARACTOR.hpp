/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTOR�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "IMAGE.hpp"
#include "ANIMATION.hpp"
#include "KEYDOWN.hpp"

//########## �}�N����` ##########

#define PATH_MAX	128		//�p�X�̏���l
#define HANDLE_MAX	 12		//�n���h���̏���l

//########## �N���X�̒�` ##########

class CHARACTOR
{
private:


public:
	int X;							//�L�����N�^�[��X�ʒu
	int Y;							//�L�����N�^�[��Y�ʒu
	int Width;						//�L�����N�^�[�̕�
	int Height;						//�L�����N�^�[�̍���

	int Speed;						//���x

	BOOL IsView;					//�\�����邩

	VOID MoveUp(VOID);				//��ɓ���
	VOID MoveLeft(VOID);			//���ɓ���
	VOID MoveDown(VOID);			//���ɓ���
	VOID MoveRight(VOID);			//�E�ɓ���

	CHARACTOR();					//�R���X�g���N�^
	virtual ~CHARACTOR();			//�f�X�g���N�^
};

