/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYER�N���X																					   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "PLAYER.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
PLAYER::PLAYER()
{
	this->tama.resize(1);					//resize�Fvector�̗v�f����ύX����
	this->tama_itr = this->tama.begin();	//�擪�̃|�C���^������

	return;
}

//�f�X�g���N�^
PLAYER::~PLAYER()
{

	return;
}

//����
void PLAYER::Operation(KEYDOWN *keydown)
{
	if (keydown->IsKeyDown(KEY_INPUT_SPACE))			//�X�y�[�X�L�[�������Ă���Ƃ�
	{
		this->CreateTama(TAMA_TYPE_TAMA, TAMA_COLOR_AKA);
	}

	return;
}

//�e���쐬
void PLAYER::CreateTama(int type, int color)
{
	this->tama.push_back(TAMA());

}

//�e��`��
void PLAYER::DrawTama(void)
{

}

//�e���폜
void PLAYER::DeleteTama(void)
{

}