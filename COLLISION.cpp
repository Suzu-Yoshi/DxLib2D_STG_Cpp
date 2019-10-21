/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* COLLISION.cpp     																			   */
/* COLLISION�N���X																				   */

//##########�w�b�_�[�t�@�C���ǂݍ��� ##########
#include "COLLISION.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
COLLISION::COLLISION()
{
	this->Sikaku = new SIKAKU();			//�l�p�N���X�쐬
	this->SetIsDraw(true);

	return;
}

//�f�X�g���N�^
COLLISION::~COLLISION()
{
	delete Sikaku;

	return;
}

//�Փˌ��m�`�F�b�N
//���@���FCollision�F�Փ˂�������
bool COLLISION::DetectionCheck(COLLISION aite)
{
	if (this->Sikaku->Top < aite.Sikaku->Bottom &&
		this->Sikaku->Left < aite.Sikaku->Right &&
		this->Sikaku->Bottom > aite.Sikaku->Top &&
		this->Sikaku->Right > aite.Sikaku->Left)
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
		DrawBox(this->Sikaku->Left, this->Sikaku->Top, this->Sikaku->Right, this->Sikaku->Bottom, GetColor(255,0,0), false);	//�g�����`��
	}
	return;
}

//�l�p�̈ʒu��ݒ�
void COLLISION::SetSikaku(int left, int top, int width, int height)
{
	this->Sikaku->SetValue(left, top, width, height);
	return;
}

//�����蔻��͈̔͂�`��i�I�[�o�[���[�h�j
//���@���Funsigned int�FGetColor(?,?,?)�̖߂�l
void COLLISION::Draw(unsigned int Color)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->Sikaku->Left, this->Sikaku->Top, this->Sikaku->Right, this->Sikaku->Bottom, Color, false);	//�g�����`��
	}
	return;
}