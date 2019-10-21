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

//�Փˌ��m�`�F�b�N
//���@���FCollision�F�Փ˂�������
bool COLLISION::DetectionCheck(COLLISION aite)
{
	if (this->sikaku->Top < aite.sikaku->GetBottom() &&
		this->sikaku->Left < aite.sikaku->GetRight() &&
		this->sikaku->GetBottom() > aite.sikaku->Top &&
		this->sikaku->GetRight() > aite.sikaku->Left)
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
		DrawBox(this->sikaku->Left, this->sikaku->Top, this->sikaku->GetRight(), this->sikaku->GetBottom(), GetColor(0, 0, 0), false);	//�g�����`��
	}
	return;
}

//�����蔻��͈̔͂�`��i�I�[�o�[���[�h�j
//���@���Funsigned int�FGetColor(?,?,?)�̖߂�l
void COLLISION::Draw(unsigned int Color)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->sikaku->Left, this->sikaku->Top, this->sikaku->GetRight(), this->sikaku->GetBottom(), Color, false);	//�g�����`��
	}
	return;
}