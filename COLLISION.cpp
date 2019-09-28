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
void COLLISION::SetValue(int setLeft, int setTop, int setRight, int setBottom)
{
	this->left = setLeft;		//�����蔻��͈̔͂�����ݒ�
	this->top = setTop;			//�����蔻��͈̔͂����ݒ�

	this->right = setRight;		//�����蔻��͈̔͂��E��ݒ�
	this->bottom = setBottom;	//�����蔻��͈̔͂�����ݒ�

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

//�����蔻��͈̔͂�`�悷�邩
void COLLISION::SetIsDraw(bool draw)
{
	this->IsDraw = draw;
	return;
}

//�����蔻��͈̔͂�`��
void COLLISION::Draw(void)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->left, this->top, this->right, this->bottom, GetColor(0, 0, 0),1);
	}
	return;
}

//�����蔻��͈̔͂�`��i�I�[�o�[���[�h�j
//���@���Funsigned int�FGetColor(?,?,?)�̖߂�l
void COLLISION::Draw(unsigned int Color)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->left, this->top, this->right, this->bottom, Color, false);	//�g�����`��
	}
	return;
}