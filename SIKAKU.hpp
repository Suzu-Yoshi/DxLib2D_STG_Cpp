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

public:
	SIKAKU();					//�R���X�g���N�^
	SIKAKU(int, int, int, int);	//�R���X�g���N�^�̃I�[�o�[���[�h
	virtual ~SIKAKU();	//�f�X�g���N�^

	int GetRight(void);		//�l�p�̉E����X�ʒu���擾
	int GetBottom(void);	//�l�p�̉E����Y�ʒu���擾

	int GetCenterX(void);	//�l�p�̒��S��X�ʒu���擾
	int GetCenterY(void);	//�l�p�̒��S��Y�ʒu���擾

};

