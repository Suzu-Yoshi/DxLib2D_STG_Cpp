/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* IMAGE.cpp     																				�@ */
/*       																						�@ */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "IMAGE.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
IMAGE::IMAGE(char *path)
{



	this->Handle = LoadGraph(path);	//�摜��ǂݍ���
	
	if (this->Handle == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		std::string ErroeMsg(IMAGE_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT(IMAGE_ERROR_MSG);		//�G���[���b�Z�[�W
		ErroeMsg += TEXT('\n');					//���s
		ErroeMsg += path;						//�摜�̃p�X

		MessageBox(
			NULL, 
			ErroeMsg.c_str,	//char * ��Ԃ�
			TEXT(IMAGE_ERROR_TTILE),
			MB_OK);

		return;
	}


	this->FilePath = path;			//�摜�̃p�X��ݒ�


	return;
}

//�f�X�g���N�^
IMAGE::~IMAGE()
{
	DeleteGraph(this->Handle);		//�ǂݍ��񂾉摜���폜
	
	return;
}
