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
	FilePath = "";	//�p�X
	FileName = "";	//���O

	Handle = -1;	//�n���h��

	X = 0;			//X�ʒu
	Y = 0;			//Y�ʒu
	Width = 0;		//��
	Height = 0;		//����

	IsLoad = false;	//�ǂݍ��߂����H

	//�摜��ǂݍ���
	std::string LoadfilePath;	//�摜�̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	this->Handle = LoadDivGraph(LoadfilePath.c_str());	//�摜��ǂݍ���

	if (this->Handle == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		std::string ErroeMsg(IMAGE_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');					//���s
		ErroeMsg += LoadfilePath;				//�摜�̃p�X

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(IMAGE_ERROR_TTILE),
			MB_OK);

		return;
	}

	this->FilePath = LoadfilePath;		//�摜�̃p�X��ݒ�
	this->FileName = name;				//�摜�̖��O��ݒ�

	GetGraphSize(
		this->Handle,	//���̃n���h���̉摜�̑傫�����擾
		&this->Width,	//Width�̃A�h���X��n��
		&this->Height	//Height�̃A�h���X��n��
	);

	this->IsLoad = true;		//�ǂݍ��߂�

	return;
}

//�f�X�g���N�^
ANIMATION::~ANIMATION()
{
}
