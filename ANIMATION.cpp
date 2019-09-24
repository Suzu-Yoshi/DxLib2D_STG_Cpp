/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* ANIMATION.cpp     																			�@ */
/* �A�j���[�V�����N���X 																		�@ */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "ANIMATION.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
//���@���Fint�F�摜�̑�������
//���@���Fint�F�摜�̉������̕�����
//���@���Fint�F�摜�̏c�����̕�����
//���@���Fint�F�摜�̕������ꂽ���̑傫��
//���@���Fint�F�摜�̕������ꂽ�c�̑傫��
ANIMATION::ANIMATION(const char *dir, const char *name,int SplitNumALL,int SpritNumX,int SpritNumY,int SpritWidth,int SpritHeight)
{
	//�����o�ϐ���������
	this->FilePath = "";	//�p�X
	this->FileName = "";	//���O

	this->Handle.resize(SplitNumALL);			//resize�Fvector�̗v�f����ύX����
	this->Handle_itr = this->Handle.begin();	//�擪�̃|�C���^������

	this->X = 0;			//X�ʒu
	this->Y = 0;			//Y�ʒu
	this->Width = 0;		//��
	this->Height = 0;		//����

	this->IsLoad = false;	//�ǂݍ��߂����H

	//�摜��ǂݍ���
	std::string LoadfilePath;	//�摜�̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	//�摜�𕪊����ēǂݍ���
	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SpritNumY, SpritWidth, SpritHeight,&this->Handle[0]);

	if (this->Handle[0] == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		std::string ErroeMsg(ANIMATION_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');						//���s
		ErroeMsg += LoadfilePath;					//�摜�̃p�X

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(ANIMATION_ERROR_TTILE),
			MB_OK);

		return;
	}

	this->FilePath = LoadfilePath;		//�摜�̃p�X��ݒ�
	this->FileName = name;				//�摜�̖��O��ݒ�

	GetGraphSize(
		this->Handle[0],	//���̃n���h���̉摜�̑傫�����擾
		&this->Width,		//Width�̃A�h���X��n��
		&this->Height		//Height�̃A�h���X��n��
	);

	this->IsLoad = true;		//�ǂݍ��߂�

	return;
}

//�f�X�g���N�^
ANIMATION::~ANIMATION()
{
	//�͈̓x�[�X�� for ���[�v
	//vector�Ȃǂ̃R���e�i�N���X�Ŏg�p�ł���
	//auto�F�^���_�F�R���p�C���������l���琄�_���Č^�����߂Ă����
	for (int handle : this->Handle)	
	{
		DeleteGraph(handle);
	}

	//vector�̃�����������s��
	std::vector<int> v;			//���vector���쐬����
	this->Handle.swap(v);		//��ƒ��g�����ւ���

	return;
}

//�t�@�C���̖��O���擾
std::string ANIMATION::GetFileName(void)
{
	return this->FileName;
}

//X�ʒu��ݒ�
void ANIMATION::SetX(int numX)
{
	this->X = numX;	return;
}

//Y�ʒu��ݒ�
void ANIMATION::SetY(int numY)
{
	this->Y = numY;	return;
}

//X�ʒu���擾
int ANIMATION::GetX(void)
{
	return this->X;
}

//Y�ʒu���擾
int ANIMATION::GetY(void)
{
	return this->Y;
}

//�����擾
int ANIMATION::GetWidth(void)
{
	return this->Width;
}

//�������擾
int ANIMATION::GetHeight(void)
{
	return this->Height;
}

//�ǂݍ��߂��H
bool ANIMATION::GetIsLoad(void)
{
	return this->IsLoad;
}

//�摜��`��
void ANIMATION::Draw(void)
{
	DrawGraph(this->X, this->Y, *this->Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
	return;
}