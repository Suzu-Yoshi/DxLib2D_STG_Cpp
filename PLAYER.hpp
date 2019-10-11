/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYER�N���X																					   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "main.hpp"
#include "IMAGE.hpp"
#include "COLLISION.hpp"
#include "KEYDOWN.hpp"
#include "TAMA.hpp"
#include "CHARACTOR.hpp"
#include "FPS.hpp"

//########## �w�b�_�t�@�C���̒�` ##########
#define CREATE_OK_FLAME	5	//5�t���[���Ԋu�ŘA������
#define DELETE_OK_FLAME	1	//1�t���[���Ԋu�ŘA���폜

//########## �N���X�̒�` ##########
class PLAYER : public CHARACTOR
{
private:
	std::vector<TAMA> tama;					//�e�N���X
	std::vector<TAMA>::iterator tama_itr;	//�n���h���̃C�e���[�^(�|�C���^)

	int TamaNumber;					//�쐬�����e�̔ԍ�
	int CreateTimeNowFlame;			//�e���쐬�����t���[������
	int CreateTimeBeforeFlame;		//�e��O��쐬�����t���[������

	int DeleteTimeNowFlame;			//�e���폜�����t���[������
	int DeleteTimeBeforeFlame;		//�e��O��폜�����t���[������

public:
	PLAYER();			//�R���X�g���N�^
	virtual ~PLAYER();	//�f�X�g���N�^

	void OperationTama(KEYDOWN *);	//����

	void CreateTama(void);		//�e���쐬
	void OpeDrawTama(void);		//�e��`��
	void DeleteTama(int);		//�e���폜

};

