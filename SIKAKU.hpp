/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* SIKAKU.hpp     																				   */
/* SIKAKU�N���X																					   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########

//########## �}�N����` ##########

//########## �N���X�̒�` ##########

class SIKAKU
{
public:
	int Left;		//X�ʒu
	int Top;		//Y�ʒu
	int Width;		//��
	int Height;		//����
	int Right;		//X�ʒu�{��
	int Bottom;		//Y�ʒu�{����

public:
	SIKAKU();					//�R���X�g���N�^
	SIKAKU(int, int, int, int);	//�R���X�g���N�^�̃I�[�o�[���[�h
	virtual ~SIKAKU();	//�f�X�g���N�^

	void SetValue(int, int, int, int);	//�l�p�̈ʒu��ݒ�

	int GetCenterX(void);	//�l�p�̒��S��X�ʒu���擾
	int GetCenterY(void);	//�l�p�̒��S��Y�ʒu���擾

};

