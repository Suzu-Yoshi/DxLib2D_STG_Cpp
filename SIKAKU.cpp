/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* SIKAKU.cpp     																				   */
/* SIKAKU�N���X																				   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "SIKAKU.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
SIKAKU::SIKAKU()
{
	return;
}

//�R���X�g���N�^�̃I�[�o�[���[�h
SIKAKU::SIKAKU(int left,int top,int width,int height)
{
	this->Left = left;
	this->Top = top;
	this->Width = width;
	this->Height = height;

	return;
}

//�f�X�g���N�^
SIKAKU::~SIKAKU()
{
	return;
}

//�l�p�̈ʒu��ݒ�
void SIKAKU::SetValue(int left, int top, int width, int height)
{
	this->Left = left;
	this->Top = top;
	this->Width = width;
	this->Height = height;

	this->Right = left + width;
	this->Bottom = top + height;

	return;
}

//�l�p�̒��S��X�ʒu���擾
int SIKAKU::GetCenterX(void)
{
	return this->Left + this->Width / 2;
}

//�l�p�̒��S��Y�ʒu���擾
int SIKAKU::GetCenterY(void)
{
	return this->Top + this->Height / 2;
}
