/* COLLISION.cpp     																			   */
/* COLLISION�N���X																				   */

//##########�w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Collision.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
Collision::Collision()
{
	return;
}

//�f�X�g���N�^
Collision::~Collision()
{
	return;
}

//�l��ݒ�
void Collision::SetValue(int setTop, int setLeft, int setBottom, int setRight)
{
	this->top = setTop;			//�����蔻��͈̔͂����ݒ�
	this->left = setLeft;		//�����蔻��͈̔͂�����ݒ�
	this->bottom = setBottom;	//�����蔻��͈̔͂�����ݒ�
	this->right = setRight;		//�����蔻��͈̔͂��E��ݒ�

	return;
}

//�Փˌ��m
bool Collision::DetectionCheck(Collision aite)
{

	return false;
}