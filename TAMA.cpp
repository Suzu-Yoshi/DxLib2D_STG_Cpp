/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMA�N���X																					   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "TAMA.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
TAMA::TAMA()
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(0, 0);	//�����ݒ�

	return;
}

//�R���X�g���N�^
TAMA::TAMA(int SetX, int SetY)
{
	this->SetAnime(MY_ANIME_DIR_TAMA, MY_ANIME_NAME_TAMA_AKA, 4, 4, 1, TAMA_WIDTH, TAMA_HEIGHT, TAMA_DRAW_SPEED);

	this->SetInitInfo(SetX, SetY);	//�����ݒ�

	return;
}

//�����ݒ�
void TAMA::SetInitInfo(int SetX, int SetY)
{
	this->SetSpeed(TAMA_MOVE_SPEED_SLOW);	//������ݒ�

	this->SetX(SetX);		//�ʒu��ݒ�
	this->SetY(SetY);		//�ʒu��ݒ�

	this->IsEnbled = true;	//�e�𖳌���

	return;
}

//�e�̃A�j���[�V�������쐬
void TAMA::SetAnime(const char *dir, const char *path, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed)
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

	this->SetX(this->Anime->GetWidth());		//�ʒu��ݒ�
	this->SetY(this->GetCenterY());			//�ʒu��ݒ�

	this->IsEnbled = true;	//�e�𖳌���

	return;
}
//�f�X�g���N�^
TAMA::~TAMA()
{
	if (!this->Anime)	//emplace_back�ŌĂ΂��Ƃ��̑Ώ�
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

//������ݒ�
void TAMA::SetSpeed(int sp)
{
	this->Speed = sp;
	return;
}

//�������擾
int TAMA::GetSpeed(void)
{
	return this->Speed;
}

//X�ʒu���擾
int TAMA::GetX(void)
{
	return this->X;
}

//Y�ʒu���擾
int TAMA::GetY(void)
{
	return this->Y;
}

//X�ʒu��ݒ�
void TAMA::SetX(int SetX)
{
	this->X = SetX;
	return;
}

//Y�ʒu��ݒ�
void TAMA::SetY(int SetY)
{
	this->Y = SetY;
	return;
}

//���S�l���擾
int TAMA::GetCenterX(void)
{
	return (this->X + this->Anime->GetWidth()) / 2;
}

//���S�l���擾
int TAMA::GetCenterY(void)
{
	return (this->Y + this->Anime->GetHeight()) / 2;
}

//����
void TAMA::Operation(void)
{
 	this->SetX(this->X + this->Speed);
	return;
}

//�摜��`��
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//�`�悵�ėǂ��Ȃ�
	{
		this->Anime->Draw(this->GetX(), this->GetY());
	}
}