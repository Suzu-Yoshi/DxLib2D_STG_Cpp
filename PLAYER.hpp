/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYER�N���X																				   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "main.hpp"
#include "CHARACTOR.hpp"
#include "IMAGE.hpp"
#include "COLLISION.hpp"
#include "KEYDOWN.hpp"
#include "PLAYER.hpp"

//########## �N���X�̒�` ##########
class PLAYER : public CHARACTOR
{
public:
	PLAYER();			//�R���X�g���N�^
	virtual ~PLAYER();	//�f�X�g���N�^
};

