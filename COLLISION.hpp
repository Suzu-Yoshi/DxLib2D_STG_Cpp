/* COLLISION.hpp     																			   */
/* COLLISION�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "SIKAKU.hpp"

//########## �N���X�̒�` ##########

class COLLISION
{
private:
	
	SIKAKU *Sikaku;	//�����蔻��̗̈�

	bool IsDraw;	//�����蔻��͈̔͂�`�悷�邩�H

public:
	COLLISION();			//�R���X�g���N�^
	virtual ~COLLISION();	//�f�X�g���N�^

	bool DetectionCheck(COLLISION);		//�Փˌ��m

	void SetIsDraw(bool);				//�����蔻��͈̔͂�`�悷�邩
	void SetSikaku(int, int, int, int);	//�l�p�̈ʒu��ݒ�

	void Draw(void);					//�����蔻��͈̔͂�`��
	void Draw(unsigned int);			//�I�[�o�[���[�h
};

