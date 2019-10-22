/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* STAR.hpp     																				�@ */
/* STAR�N���X 																					�@ */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "CHARACTOR.hpp"

//########## �}�N����` ##########
#define STAR_TATE_MAX	15
#define STAR_YOKO_MAX	19

#define STAR_WIDTH		30
#define STAR_HEIGHT		30

#define STAR_MARGIN		5

#define STAR_START_Y	STAR_HEIGHT + STAR_MARGIN
#define STAR_START_X	(STAR_WIDTH + STAR_MARGIN) * 4

//########## �N���X�̒�` ##########

class STAR : public CHARACTOR	//CHARACTOR�N���X���p��
{
private:
	
public:
	STAR();				//�R���X�g���N�^
	virtual ~STAR();	//�f�X�g���N�^
};

//########## �O���I�u�W�F�N�g ##########
extern STAR *star[STAR_TATE_MAX][STAR_YOKO_MAX];