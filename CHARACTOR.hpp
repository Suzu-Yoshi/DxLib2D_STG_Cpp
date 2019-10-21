/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTOR�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "main.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"
#include "SIKAKU.hpp"
#include "COLLISION.hpp"

//########## �}�N����` ##########

//�ړ����x
#define CHARA_SPEED_1_SLOW	1
#define CHARA_SPEED_2_FAST	4
#define CHARA_SPEED_3_STAR	8

//########## �N���X�̒�` ##########

class CHARACTOR
{
private:

	SIKAKU *sikaku_draw;			//�L�����̕`�悷��̈�
	IMAGE *image;					//�L�����̉摜
	COLLISION *collision;			//�����蔻��

	int Speed;						//���x
	bool IsAlive;					//�����Ă��邩
	bool IsCreate;					//�쐬�ł�����
	bool IsKeyOperation;			//�L�[�{�[�h�ő��삪�ł��邩
	bool IsDraw;					//�`��ł��邩

public:

	VOID MoveUp(VOID);				//��ɓ���
	VOID MoveLeft(VOID);			//���ɓ���
	VOID MoveDown(VOID);			//���ɓ���
	VOID MoveRight(VOID);			//�E�ɓ���

	CHARACTOR();					//�R���X�g���N�^
	virtual ~CHARACTOR();			//�f�X�g���N�^

	int GetSpeed(void);				//�������擾
	bool GetIsAlive(void);			//�����Ă��邩�擾
	bool GetIsCreate(void);			//�쐬�ł������擾

	void SetSpeed(int);				//������ݒ�
	void SetIsAlive(bool);			//�����Ă��邩�ݒ�
	void SetIsKeyOperation(bool);	//�L�[�{�[�h�ő��삪�ł��邩�ݒ肷��

	bool Init(const char*, const char*, int, int);	//�����ݒ�
	bool Init(const char*, const char*);			//�����ݒ�
	void Operation(KEYDOWN *);		//����
	void Draw(void);				//�`��

};

