/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* ANIMATION.hpp     																			�@ */
/* �A�j���[�V�����N���X 																		�@ */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include <string>
#include <vector>

//########## �}�N����`�Q�摜�̃t�@�C���p�X�Ɩ��O ##########

//########## �}�N����`�F�G���[���b�Z�[�W##########
#define ANIMATION_ERROR_TTILE	"ANIMATION_ERROR"						//�G���[�^�C�g��
#define ANIMATION_ERROR_MSG		"�A�j���[�V�������ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//########## �N���X�̒�` ##########
class ANIMATION
{
private:
	std::string FilePath;	//�p�X
	std::string FileName;	//���O

	std::vector<int> Handle;	//�n���h��

	std::vector<int>::iterator Handle_itr;	//�n���h���̃C�e���[�^(�|�C���^)

	int X;					//X�ʒu
	int Y;					//Y�ʒu
	int Width;				//��
	int Height;				//����

	bool IsLoad;			//�ǂݍ��߂����H

public:
	ANIMATION(const char *, const char *, int, int, int, int, int );	//�R���X�g���N�^
	~ANIMATION();	//�f�X�g���N�^

	std::string GetFileName(void);	//���O���擾

	void SetX(int);					//X�ʒu��ݒ�
	void SetY(int);					//Y�ʒu��ݒ�
	int GetX(void);					//X�ʒu���擾
	int GetY(void);					//Y�ʒu���擾
	int GetWidth(void);				//�����擾
	int GetHeight(void);			//�������擾

	bool GetIsLoad(void);			//�ǂݍ��߂��H

	void Draw(void);				//�摜��`��
};

