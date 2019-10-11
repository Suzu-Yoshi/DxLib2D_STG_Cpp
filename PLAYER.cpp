/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYER�N���X																					   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "PLAYER.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
PLAYER::PLAYER()
{
	this->tama.reserve(10);	//�e�̌��݂̗\�z�ő�������\�ߌ��߂Ă���
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
void PLAYER::OperationTama(KEYDOWN *keydown)
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
	this->tama.emplace_back(TAMA(this->GetRight(),this->GetCenterY()));			//�v�f��ǉ�

	return;
}

//�e�𑀍쁕�`��
void PLAYER::OpeDrawTama(void)
{

	//�g��for�ōs���ƁA�g��for���I���Ƃ��A�g���Ă����ϐ��̃f�X�g���N�^����������I�H
	for (std::vector<TAMA>::iterator itr = this->tama.begin(); itr != this->tama.end(); ++itr)
	{
		itr->Operation();	//����
		itr->Draw();		//�`��
	}

	return;
}

//�e���폜
void PLAYER::DeleteTama(int DeleteNumber)
{
	std::swap(this->tama[DeleteNumber], this->tama.back());	//�폜�ΏۂƖ���������
	this->tama.pop_back();									//�������폜

	/*
	if (!this->tama.empty())	//�x�N�^�[�̗v�f����łȂ����
	{
		this->tama.erase(itr);	//�v�f��ǉ�
	}
	*/

	return;
}