/* COLLISION.cpp     																			   */
/* COLLISION�N���X																				   */

//##########�w�b�_�[�t�@�C���ǂݍ��� ##########
#include "COLLISION.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
COLLISION::COLLISION()
{
	return;
}

//�f�X�g���N�^
COLLISION::~COLLISION()
{
	return;
}

//�l��ݒ�
void COLLISION::SetValue(int setTop, int setLeft, int setBottom, int setRight)
{
	this->top = setTop;			//�����蔻��͈̔͂����ݒ�
	this->left = setLeft;		//�����蔻��͈̔͂�����ݒ�
	this->bottom = setBottom;	//�����蔻��͈̔͂�����ݒ�
	this->right = setRight;		//�����蔻��͈̔͂��E��ݒ�

	return;
}

//�Փˌ��m�`�F�b�N
//���@���FCollision�F�Փ˂�������
bool COLLISION::DetectionCheck(COLLISION aite)
{
	if (this->top < aite.bottom &&
		this->left < aite.right &&
		this->bottom > aite.top &&
		this->right > aite.left)
	{
		return true;	//��������
	}

	return false;		//�������Ă��Ȃ�
}
