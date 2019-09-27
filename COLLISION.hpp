/* COLLISION.hpp     																			   */
/* COLLISION�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"

//########## �N���X�̒�` ##########

class Collision
{
private:
	int top;		//�����蔻��̏�̈ʒu
	int left;		//�����蔻��̍��̈ʒu
	int bottom;		//�����蔻��̉��̈ʒu
	int right;		//�����蔻��̉E�̈ʒu

public:
	Collision();	//�R���X�g���N�^
	~Collision();	//�f�X�g���N�^

	void SetValue(int, int, int, int);	//�l��ݒ�
	bool DetectionCheck(Collision);		//�Փˌ��m
};

