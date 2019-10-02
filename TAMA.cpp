/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMA�N���X																					   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "TAMA.hpp"

//########## �N���X�̒�` ##########

int i = 0;

//�R���X�g���N�^
TAMA::TAMA()
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_SPEED);

	return;
}

//�e�̃A�j���[�V�������쐬
void TAMA::SetAnime(const char *dir , const char *path,int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed)
{
	this->Anime = new ANIMATION(
		dir,
		path,
		SplitNumALL,
		SpritNumX,
		SplitNumY,
		SplitWidth,
		SplitHeight,
		changeSpeed,
		true);	//�e�𐶐�

	this->SetX_Y(10*i++,10);		//�ʒu��ݒ�
	this->IsEnbled = true;	//�e�𖳌���

	return;
}
//�f�X�g���N�^
TAMA::~TAMA()
{
	if (!this->Anime)
	{
		delete this->Anime;
	}
	return;
}

//�e��L��/�����ɂ���
void TAMA::SetIsEnbled(bool set)
{
	this->IsEnbled = set; return;
}

//X�ʒu��Y�ʒu��ݒ�
void TAMA::SetX_Y(int SetX, int SetY)
{
	this->X = SetX; this->Y = SetY;
	this->Anime->SetX(this->X);
	this->Anime->SetY(this->Y);
	
	return;
}

//�摜��`��
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//�`�悵�ėǂ��Ȃ�
	{
		this->Anime->Draw();
	}
}