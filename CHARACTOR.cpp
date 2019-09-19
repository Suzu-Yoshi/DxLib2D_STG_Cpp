/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.cpp     																				   */
/* CHARACTOR�N���X																				   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "CHARACTOR.hpp"
#include "KEYDOWN.hpp"

//########## �N���X�̒�` ##########

//��ɓ���
VOID CHARACTOR::MoveUp(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_UP))
	{
		DrawString(100, 100, "UP", RGB(255,255,255));
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveLeft(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_LEFT))
	{
		DrawString(100, 100, "LEFT", RGB(255, 255, 255));
	}

	return;
}

//���ɓ���
VOID CHARACTOR::MoveDown(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_DOWN))
	{
		DrawString(100, 100, "DOWN", RGB(255, 255, 255));
	}

	return;
}

//�E�ɓ���
VOID CHARACTOR::MoveRight(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_RIGHT))
	{
		DrawString(100, 100, "RIGHT", RGB(255, 255, 255));
	}

	return;
}

//�R���X�g���N�^
CHARACTOR::CHARACTOR()
{
	this->charactor_keydown = new KEYDOWN();
}

//�f�X�g���N�^
CHARACTOR::~CHARACTOR()
{
	delete this->charactor_keydown;
}
