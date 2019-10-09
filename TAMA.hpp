/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.hpp     																				   */
/* TAMA�N���X																					   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "ANIMATION.hpp"

//########## �}�N����`�F�摜�̃t�@�C���p�X�Ɩ��O ##########
#define MY_ANIME_DIR_TAMA		R"(.\MY_ANIME\tama\)"		//�e�̉摜�t�H���_�̏ꏊ

#define MY_ANIME_NAME_TAMA_AKA		R"(tama_aka_01.png)"		//�e�̉摜�̖��O
#define MY_ANIME_NAME_TAMA_AO		R"(tama_ao_01.png)"			//�e�̉摜�̖��O
#define MY_ANIME_NAME_TAMA_MIDORI	R"(tama_midori_01.png)"		//�e�̉摜�̖��O
#define MY_ANIME_NAME_TAMA_MURASAKI	R"(tama_murasaki_01.png)"	//�e�̉摜�̖��O
#define MY_ANIME_NAME_TAMA_ORANGE	R"(tama_orage_01.png)"		//�e�̉摜�̖��O
#define MY_ANIME_NAME_TAMA_PINK		R"(tama_pink_01.png)"		//�e�̉摜�̖��O

#define MY_ANIME_NAME_HISI_AKA		R"(hisigata_aka_01.png)"		//�Ђ��`�̉摜�̖��O
#define MY_ANIME_NAME_HISI_AO		R"(hisigata_ao_01.png)"			//�Ђ��`�̉摜�̖��O
#define MY_ANIME_NAME_HISI_MIDORI	R"(hisigata_midori_01.png)"		//�Ђ��`�̉摜�̖��O
#define MY_ANIME_NAME_HISI_MURASAKI	R"(hisigata_murasaki_01.png)"	//�Ђ��`�̉摜�̖��O
#define MY_ANIME_NAME_HISI_ORANGE	R"(hisigata_orage_01.png)"		//�Ђ��`�̉摜�̖��O
#define MY_ANIME_NAME_HISI_PINK		R"(hisigata_pink_01.png)"		//�Ђ��`�̉摜�̖��O

#define MY_ANIME_NAME_MARU_AKA		R"(maru_aka_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_MARU_AO		R"(maru_ao_01.png)"			//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_MARU_MIDORI	R"(maru_midori_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_MARU_MURASAKI	R"(maru_murasaki_01.png)"	//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_MARU_ORANGE	R"(maru_orage_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_MARU_PINK		R"(maru_pink_01.png)"		//�ۂ̉摜�̖��O

#define MY_ANIME_NAME_SIROMARU_AKA		R"(siromaru_aka_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_SIROMARU_AO		R"(siromaru_ao_01.png)"			//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_SIROMARU_MIDORI	R"(siromaru_midori_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_SIROMARU_MURASAKI	R"(siromaru_murasaki_01.png)"	//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_SIROMARU_ORANGE	R"(siromaru_orage_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_SIROMARU_PINK		R"(siromaru_pink_01.png)"		//�ۂ̉摜�̖��O

#define MY_ANIME_NAME_TATEMARU_AKA		R"(tatemaru_aka_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_TATEMARU_AO		R"(tatemaru_ao_01.png)"			//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_TATEMARU_MIDORI	R"(tatemaru_midori_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_TATEMARU_MURASAKI	R"(tatemaru_murasaki_01.png)"	//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_TATEMARU_ORANGE	R"(tatemaru_orage_01.png)"		//�ۂ̉摜�̖��O
#define MY_ANIME_NAME_TATEMARU_PINK		R"(tatemaru_pink_01.png)"		//�ۂ̉摜�̖��O

#define TAMA_WIDTH	13	//�������镝�̑傫��
#define TAMA_HEIGHT	12	//�������鍂���̑傫��

#define HISI_WIDTH	12	//�������镝�̑傫��
#define HISI_HEIGHT	12	//�������鍂���̑傫��

#define MARU_WIDTH	12	//�������镝�̑傫��
#define MARU_HEIGHT	12	//�������鍂���̑傫��

#define SIROMARU_WIDTH	14	//�������镝�̑傫��
#define SIROMARU_HEIGHT	14	//�������鍂���̑傫��

#define TATEMARU_WIDTH	14	//�������镝�̑傫��
#define TATEMARU_HEIGHT	24	//�������鍂���̑傫��

#define TAMA_SPEED		0.1	//�e�̑���

#define TAMA_TYPE_TAMA		1	//�e�̎��
#define TAMA_TYPE_HISI		2	//�e�̎��
#define TAMA_TYPE_MARU		3	//�e�̎��
#define TAMA_TYPE_SIROMARU	4	//�e�̎��
#define TAMA_TYPE_TATEMARU	5	//�e�̎��

#define TAMA_COLOR_AKA		1	//�e�̐F
#define TAMA_COLOR_AO		2	//�e�̐F
#define TAMA_COLOR_MIDORI	3	//�e�̐F
#define TAMA_COLOR_MURASAKI	4	//�e�̐F
#define TAMA_COLOR_ORANGE	5	//�e�̐F
#define TAMA_COLOR_PINK		6	//�e�̐F

//########## �N���X�̒�` ##########

class TAMA
{
private:
	ANIMATION *Anime;		//�e�̃A�j���[�V����
	int ATK;				//�U����
	int Speed;				//����

	int X;					//�c�̈ʒu
	int Y;					//���̈ʒu

	bool IsEnbled;			//�e���L����

public:
	TAMA();						//�R���X�g���N�^
	virtual ~TAMA();			//�f�X�g���N�^

	void SetAnime(const char *, const char *,int, int, int, int, int, double);	//�e�̃A�j���[�V�������쐬
	void SetIsEnbled(bool);		//�`���ݒ�

	int  GetX(void);			//X�ʒu���擾
	int  GetY(void);			//Y�ʒu���擾

	void SetX(int);				//X�ʒu��ݒ�
	void SetY(int);				//Y�ʒu��ݒ�

	int GetCenterX(void);		//���S�l���擾
	int GetCenterY(void);		//���S�l���擾

	void Operation(void);		//����

	void Draw();				//�摜��`��
};