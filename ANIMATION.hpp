/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* ANIMATION.hpp     																			�@ */
/* �A�j���[�V�����N���X 																		�@ */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include <string>
#include <vector>

//########## �}�N����`�Q�摜�̃t�@�C���p�X�Ɩ��O ##########


//########## �N���X�̒�` ##########
class ANIMATION
{
private:
	std::string FilePath;	//�p�X
	std::string FileName;	//���O

	std::vector<int> Handle;	//�n���h��

	int X;					//X�ʒu
	int Y;					//Y�ʒu
	int Width;				//��
	int Height;				//����

	bool IsLoad;			//�ǂݍ��߂����H

public:
	ANIMATION(const char *, const char *, int, int, int, int, int );	//�R���X�g���N�^
	~ANIMATION();	//�f�X�g���N�^
};

