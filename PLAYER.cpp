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
	//vector�̃�����������s��
	std::vector<TAMA> v;	//���vector���쐬����
	this->tama.swap(v);		//��ƒ��g�����ւ���

	return;
}

//����
void PLAYER::Operation(KEYDOWN *keydown)
{
	if (keydown->IsKeyDown(KEY_INPUT_SPACE))			//�X�y�[�X�L�[�������Ă���Ƃ�
	{
		this->CreateTama();
	}

	return;
}

//�e���쐬
void PLAYER::CreateTama(void)
{
	this->tama.emplace_back(TAMA());	//�v�f��ǉ�
	
	return;
}

//�e��`��
void PLAYER::DrawTama(void)
{
	for (TAMA for_tama : this->tama)
	{
		for_tama.Draw();	//�`��
	}
}

//�e���폜
void PLAYER::DeleteTama(std::vector<TAMA>::iterator itr)
{
	if (!this->tama.empty())	//�x�N�^�[�̗v�f����łȂ����
	{
		this->tama.erase(itr);	//�v�f��ǉ�
	}
}