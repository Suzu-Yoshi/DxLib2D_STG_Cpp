/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* LOG.hpp     																					�@ */
/* DxLib��Log.txt�𑀍삷��																		�@ */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include <stdio.h>

//########## �N���X�̒�` ##########
class LOG
{
	bool IsWriteLog;		//���O���������H

public:
	LOG();	//�R���X�g���N�^
	~LOG();	//�f�X�g���N�^

	void SetIsWriteLog(bool);		//���O���������ݒ肷��
	void Write(const char*, ...);	//���O����������(printf�Ɠ�������)
};

