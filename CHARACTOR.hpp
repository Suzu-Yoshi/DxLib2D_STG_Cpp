/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTOR�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "IMAGE.hpp"
#include "ANIMATION.hpp"
#include "COLLISION.hpp"
#include "KEYDOWN.hpp"

//########## �}�N����` ##########

//�ړ����x
#define CHARA_SPEED_SLOW	1
#define CHARA_SPEED_FAST	4
#define CHARA_SPEED_STAR	8

//########## �N���X�̒�` ##########

class CHARACTOR
{
private:

	int X;							//X�ʒu
	int Y;							//Y�ʒu
	int Width;						//��
	int Height;						//����
	int Speed;						//���x
	bool IsAlive;					//�����Ă��邩
	bool IsCreate;					//�쐬�ł�����
	bool IsKeyOperation;			//�L�[�{�[�h�ő��삪�ł��邩

	IMAGE *image;					//�L�����̉摜
	COLLISION *collision;			//�����蔻��

public:

	VOID MoveUp(VOID);				//��ɓ���
	VOID MoveLeft(VOID);			//���ɓ���
	VOID MoveDown(VOID);			//���ɓ���
	VOID MoveRight(VOID);			//�E�ɓ���

	CHARACTOR(int);				//�R���X�g���N�^
	virtual ~CHARACTOR();			//�f�X�g���N�^

	int GetSpeed(void);				//�������擾
	void SetSpeed(int);				//������ݒ�
	
	bool GetIsAlive(void);			//�����Ă��邩�擾
	void SetIsAlive(bool);			//�����Ă��邩�ݒ�
	
	void SetX_Y(int,int);			//X�ʒu��Y�ʒu��ݒ�
	bool GetIsCreate(void);			//�쐬�ł������擾

	void SetIsKeyOperation(bool);	//�L�[�{�[�h�ő��삪�ł��邩�ݒ肷��

	int GetWidth(void);				//�����擾
	int GetHeight(void);			//�������擾

	void Operation(KEYDOWN *);		//����
	void Draw(void);				//�`��

};

