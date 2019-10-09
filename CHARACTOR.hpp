/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.hpp     																			   */
/* CHARACTOR�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "main.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"
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

	int X;							//X�ʒu
	int Y;							//Y�ʒu
	int Width;						//��
	int Height;						//����
	int Speed;						//���x
	bool IsAlive;					//�����Ă��邩
	bool IsCreate;					//�쐬�ł�����
	bool IsKeyOperation;			//�L�[�{�[�h�ő��삪�ł��邩
	bool IsDraw;					//�`��ł��邩

	IMAGE *image;					//�L�����̉摜
	COLLISION *collision;			//�����蔻��

public:

	VOID MoveUp(VOID);				//��ɓ���
	VOID MoveLeft(VOID);			//���ɓ���
	VOID MoveDown(VOID);			//���ɓ���
	VOID MoveRight(VOID);			//�E�ɓ���

	CHARACTOR();					//�R���X�g���N�^
	virtual ~CHARACTOR();			//�f�X�g���N�^

	int GetSpeed(void);				//�������擾
	void SetSpeed(int);				//������ݒ�
	
	bool GetIsAlive(void);			//�����Ă��邩�擾
	void SetIsAlive(bool);			//�����Ă��邩�ݒ�
	
	void SetX_Y(int,int);			//X�ʒu��Y�ʒu��ݒ�
	bool GetIsCreate(void);			//�쐬�ł������擾

	void SetIsKeyOperation(bool);	//�L�[�{�[�h�ő��삪�ł��邩�ݒ肷��

	int GetX(void);					//X�ʒu���擾
	int GetY(void);					//Y�ʒu���擾
	int GetWidth(void);				//�����擾
	int GetHeight(void);			//�������擾

	int GetCenterX(void);			//���S�l���擾
	int GetCenterY(void);			//���S�l���擾

	int GetRight(void);				//�E�̈ʒu���擾
	int GetBottom(void);			//���̈ʒu���擾

	int GetCentorX(void);			//X�̒��S�ʒu���擾
	int GetCentorY(void);			//Y�̒��S�ʒu���擾

	void Operation(KEYDOWN *);		//����
	void Draw(void);				//�`��

};

