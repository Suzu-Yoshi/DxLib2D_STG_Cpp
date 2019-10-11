/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* fps.hpp     																					   */
/* FPS(Flame Per Second)�N���X																	   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"

//########## �N���X�̒�` ##########
class FPS
{
private:
	int			value;					//FPS�l
	double		drawValue;				//Draw����Ƃ���FPS�l
	DWORD		calcStartTime;			//0�t���[���ڂ̊J�n����
	DWORD		calcEndTime;			//�ݒ肵���t���[���̏I������
	DWORD		flameCount;				//�t���[���̃J�E���g
	double		calcAverage; 			//FPS���v�Z���邽�߂̕��σT���v����

	int			TotalFlameCnt;			//���݂̑��t���[����

public:

	//�R���X�g���N�^
	//���@���Fint�@�FFPS�l
	FPS(int);

	//�w�肵��FPS�ɂȂ�悤�ɑ҂�
	VOID Wait(VOID);

	//��ʍX�V�̎������擾����
	VOID Update(VOID);

	//FPS�̒l��\������
	//���@���Fint�@�F�l��\������X�ʒu
	//���@���Fint�@�F�l��\������Y�ʒu
	VOID Draw(int, int);

	//FPS�l���擾����
	int Getvalue(VOID);

	//���t���[�����擾����
	int GetTotalFlameCnt(VOID);

	//�f�X�g���N�^
	virtual ~FPS();
};

//########## �O���I�u�W�F�N�g ##########
extern FPS *fps;