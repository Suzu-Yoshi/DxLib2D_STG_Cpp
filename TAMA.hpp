/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.hpp     																				   */
/* TAMA�N���X																					   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "ANIMATION.hpp"
#include "COLLISION.hpp"
#include "main.hpp"

//########## �}�N����`�F�摜�̃t�@�C���p�X�Ɩ��O ##########
#define MY_ANIME_DIR_TAMA		R"(.\MY_ANIME\tama\)"		//�e�̉摜�t�H���_�̏ꏊ

#define MY_ANIME_NAME_TAMA_AKA		R"(tama_aka_01.png)"		//�e�̉摜�̖��O
#define MY_ANIME_NAME_TAMA_AO		R"(tama_ao_01.png)"			//�e�̉摜�̖��O

#define TAMA_WIDTH	12	//�������镝�̑傫��
#define TAMA_HEIGHT	12	//�������鍂���̑傫��

#define HISI_WIDTH	12	//�������镝�̑傫��
#define HISI_HEIGHT	12	//�������鍂���̑傫��

#define MARU_WIDTH	12	//�������镝�̑傫��
#define MARU_HEIGHT	12	//�������鍂���̑傫��

#define SIROMARU_WIDTH	14	//�������镝�̑傫��
#define SIROMARU_HEIGHT	14	//�������鍂���̑傫��

#define TATEMARU_WIDTH	14	//�������镝�̑傫��
#define TATEMARU_HEIGHT	24	//�������鍂���̑傫��

#define TAMA_DRAW_SPEED		0.1	//�e�̕`���ύX���鑬��

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

#define TAMA_MOVE_SPEED_SLOW	4	//�e�̓�������
#define TAMA_MOVE_SPEED_MIDDLE	8	//�e�̓�������
#define TAMA_MOVE_SPEED_FAST	16	//�e�̓�������

//########## �N���X�̒�` ##########

class TAMA
{
private:
	ANIMATION *Anime;		//�e�̃A�j���[�V����
	COLLISION *collision;	//�����蔻��
	SIKAKU *sikaku_draw;	//�`��̗̈�

	int ATK;				//�U����
	int Speed;				//����

	int No;					//�e�̔ԍ�

	bool IsEnbled;			//�e���L����

public:
	TAMA();						//�R���X�g���N�^
	TAMA(int);					//�R���X�g���N�^�̃I�[�o�[���[�h

	virtual ~TAMA();			//�f�X�g���N�^

	void SetAnime(const char *, const char *, int, int, int, int, int, double);	//�e�̃A�j���[�V�������쐬
	void SetIsEnbled(bool);		//�`���ݒ�

	void SetInitInfo(int, int, int, int, int);	//�����ݒ�

	void SetSpeed(int);			//������ݒ�
	int GetSpeed(void);			//�������擾

	int  GetNo(void);			//No���擾
	void SetNo(int);			//No��ݒ�

	void moveTama(void);		//�e���ړ�
	bool Operation(void);		//����

	void Draw();				//�摜��`��

};
