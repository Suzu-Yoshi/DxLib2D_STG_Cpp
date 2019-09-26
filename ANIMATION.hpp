/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* ANIMATION.hpp     																			�@ */
/* �A�j���[�V�����N���X 																		�@ */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include <string>
#include <vector>

//########## �}�N����`�F�摜�̃t�@�C���p�X�Ɩ��O ##########
#define MY_ANIME_DIR_BAKU		R"(.\MY_ANIME\bakuhatsu\)"		//�����̉摜�t�@�C���̏ꏊ

#define MY_ANIME_NAME_BAKU_1	R"(bakuhatsu_01.png)"			//�����̉摜�̖��O
#define BAKU_1_WIDTH	70	//�������镝�̑傫��
#define BAKU_1_HEIGHT	64	//�������鍂���̑傫��

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

	int X;						//X�ʒu
	int Y;						//Y�ʒu
	int Width;					//��
	int Height;					//����

	double NextChangeSpeed;	//�A�j���[�V������ύX���鑬��(�b)
	int ChangeMaxCnt;			//�A�j���[�V��������t���[���̍ő�l
	int ChangeCnt;				//�A�j���[�V��������t���[���̃J�E���g

	bool IsAnimeLoop;			//�A�j���[�V�����̓��[�v����H

	bool IsLoad;				//�ǂݍ��߂����H

	bool IsDraw;				//�`�悵�Ă��ǂ��H

public:
	ANIMATION(const char *, const char *, int, int, int, int, int, double,bool);	//�R���X�g���N�^
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

