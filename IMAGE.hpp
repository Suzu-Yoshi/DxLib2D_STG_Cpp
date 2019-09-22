/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* IMAGE.cpp     																				�@ */
/* �摜�N���X 																					�@ */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include <string>

//########## �}�N����` ##########
#define IMAGE_ERROR_TTILE "IMAGE_ERROR"					//�G���[�^�C�g��
#define IMAGE_ERROR_MSG	"�摜���ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//########## �N���X�̒�` ##########

class IMAGE
{
private:
	std::string FilePath;	//�p�X
	std::string FileName;	//���O

	int Handle;				//�n���h��

	int X;					//X�ʒu
	int Y;					//Y�ʒu
	int Width;				//��
	int Height;				//����

public:
	IMAGE(char *);					//�R���X�g���N�^
	~IMAGE();						//�f�X�g���N�^

	std::string GetFileName(void);	//���O���擾

	int GetX(void);					//X�ʒu���擾
	int GetY(void);					//Y�ʒu���擾
	int GetWidth(void);				//�����擾
	int GetHeight(void);			//�������擾

	void Draw(void);				//�摜��`��
};

