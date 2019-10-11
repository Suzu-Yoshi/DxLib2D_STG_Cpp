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

	this->TamaNumber = 0;	//�e�̔ԍ���������

	//�A�ˊ֘A��������
	this->CreateTimeNowFlame = 0;
	this->CreateTimeBeforeFlame = 0;
	this->DeleteTimeNowFlame = 0;
	this->DeleteTimeBeforeFlame = 0;

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
		this->CreateTimeNowFlame = fps->GetTotalFlameCnt();	//���݂̑��t���[�������擾

		if (this->CreateTimeBeforeFlame == 0)	//��ԍŏ��ɒe���쐬����Ƃ�
		{
			this->CreateTimeBeforeFlame = this->CreateTimeNowFlame - CREATE_OK_FLAME;
		}

		if (this->CreateTimeNowFlame - this->CreateTimeBeforeFlame >= CREATE_OK_FLAME)	//�A�ˉ\�Ȃ��
		{
			this->CreateTama();	//�e���쐬
			this->CreateTimeBeforeFlame = fps->GetTotalFlameCnt();	//�ȑO�̑��t���[���� = ���݂̑��t���[����
		}
	}

	return;
}

//�e���쐬
void PLAYER::CreateTama(void)
{
	this->tama.emplace_back(
		TAMA(
			this->GetRight(),
			this->GetCenterY(),
			TamaNumber));		//�v�f��ǉ�

	this->TamaNumber++;	//�e�̐��𑝂₷

	return;
}

//�e�𑀍쁕�`��
void PLAYER::OpeDrawTama(void)
{
	bool RetOperation;

	//�g��for�F
	//for(����for���Ŏg����f�[�^ : �E��for���ŉ�vector)
	//auto�F�^���_�F����Ƀf�[�^�^�𐄑����Ă����
	//auto&&�F���j�o�[�T���Q�ƁF
	//https://marycore.jp/prog/cpp/universal-reference/
	for (auto&& for_tama : this->tama)
	{
		//�X�̒e�̑���
		RetOperation = for_tama.Operation();

		if (RetOperation == true)
		{
			//�X�̒e�̕`��
			for_tama.Draw();
		}
		else
		{
			this->DeleteTimeNowFlame = fps->GetTotalFlameCnt();	//���݂̑��t���[�������擾

			if (this->DeleteTimeBeforeFlame == 0)	//��ԍŏ��ɒe���폜����Ƃ�
			{
				this->DeleteTimeBeforeFlame = this->DeleteTimeNowFlame - DELETE_OK_FLAME;
			}

			if (this->DeleteTimeNowFlame - this->DeleteTimeBeforeFlame >= DELETE_OK_FLAME)	//�A�������\�Ȃ��
			{
				this->DeleteTama(for_tama.GetNo());	//�e���폜

				this->DeleteTimeBeforeFlame = fps->GetTotalFlameCnt();	//�ȑO�̑��t���[���� = ���݂̑��t���[����
			}
		}
	}

	//�e�̐���`��
	DrawFormatString(0, 20, GetColor(255, 255, 255), "�e�̐��F%4d", TamaNumber);

	return;
}

//�e���폜
void PLAYER::DeleteTama(int DeleteNumber)
{
	if (!this->tama.empty())	//�x�N�^�[�̗v�f����łȂ����
	{
		std::swap(this->tama[DeleteNumber], this->tama.back());	//�폜�ΏۂƖ���������
		this->tama[DeleteNumber].SetNo(DeleteNumber);			//�폜�Ώۂ�No�Ɩ���������
		this->tama.pop_back();	//�������폜
		this->TamaNumber--;		//�e�̐������炷
	}

	return;
}