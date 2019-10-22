/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* COLLISION.cpp     																			   */
/* COLLISION�N���X																				   */

//##########�w�b�_�[�t�@�C���ǂݍ��� ##########
#include "COLLISION.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
COLLISION::COLLISION()
{
	this->SetIsDraw(true);	//�����蔻��͈̔͂�`�悷��

	return;
}

//�f�X�g���N�^
COLLISION::~COLLISION()
{
	return;
}

//�Փˌ��m�`�F�b�N
//���@���FCollision�F�Փ˂�������
bool COLLISION::DetectionCheck(COLLISION *aite)
{
	if (this->Top < aite->Bottom &&
		this->Left < aite->Right &&
		this->Bottom > aite->Top &&
		this->Right > aite->Left)
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
		DrawBox(this->Left, this->Top, this->Right, this->Bottom, GetColor(255,0,0), false);	//�g�����`��
	}
	return;
}

//�����蔻��͈̔͂�`��i�I�[�o�[���[�h�j
//���@���Funsigned int�FGetColor(?,?,?)�̖߂�l
void COLLISION::Draw(unsigned int Color)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->Left, this->Top, this->Right, this->Bottom, Color, false);	//�g�����`��
	}
	return;
}