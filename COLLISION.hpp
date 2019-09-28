/* COLLISION.hpp     																			   */
/* COLLISION�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"

//########## �N���X�̒�` ##########

class COLLISION
{
private:
	int top;		//�����蔻��̏�̈ʒu
	int left;		//�����蔻��̍��̈ʒu
	int bottom;		//�����蔻��̉��̈ʒu
	int right;		//�����蔻��̉E�̈ʒu

	bool IsDraw;	//�����蔻��͈̔͂�`�悷�邩�H

public:
	COLLISION();	//�R���X�g���N�^
	~COLLISION();	//�f�X�g���N�^

	void SetValue(int, int, int, int);	//�l��ݒ�
	bool DetectionCheck(COLLISION);		//�Փˌ��m

	void SetIsDraw(bool);				//�����蔻��͈̔͂�`�悷�邩

	void Draw(void);					//�����蔻��͈̔͂�`��
	void Draw(unsigned int);			//�I�[�o�[���[�h
};

