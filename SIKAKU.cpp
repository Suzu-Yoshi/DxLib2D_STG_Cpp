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

int SIKAKU::GetRight(void)
{
	return this->Left + this->Width;
}

int SIKAKU::GetBottom(void)
{
	return this->Top + this->Height;
}

int SIKAKU::GetCenterX(void)
{
	return this->Left + this->Width / 2;
}

int SIKAKU::GetCenterY(void)
{
	return this->Top + this->Height / 2;
}
