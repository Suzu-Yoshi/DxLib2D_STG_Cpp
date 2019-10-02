/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* TAMA.cpp     																				   */
/* TAMA�N���X																					   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "TAMA.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
//���@���Fint�F�e�̃^�C�v
//���@���Fint�F�e�̐F
TAMA::TAMA(int type, int color)
{
	std::string SelectTamaPath;	//�e�̉摜�̃p�X

	int SplitNumALL;
	int SpritNumX;
	int SplitNumY;
	int SplitWidth;
	int SplitHeight;
	double changeSpeed;
	bool IsLoop;

	switch (type)
	{
	case TAMA_TYPE_TAMA:
		switch (color)
		{
			SplitNumALL = 4;
			SpritNumX = 4;
			SplitNumY = 1;
			SplitWidth = TAMA_WIDTH;
			SplitHeight = TAMA_HEIGHT;
			changeSpeed = TAMA_SPEED;
			IsLoop = TRUE;

		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_TAMA_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_TAMA_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_TAMA_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_TAMA_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_TAMA_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_TAMA_PINK;
			break;
		}
		break;

	case TAMA_TYPE_HISI:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_HISI_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_HISI_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_HISI_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_HISI_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_HISI_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_HISI_PINK;
			break;
		}
		break;

	case TAMA_TYPE_MARU:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_MARU_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_MARU_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_MARU_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_MARU_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_MARU_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_MARU_PINK;
			break;
		}
		break;

	case TAMA_TYPE_SIROMARU:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_SIROMARU_PINK;
			break;
		}
		break;

	case TAMA_TYPE_TATEMARU:
		switch (color)
		{
		case TAMA_COLOR_AKA:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_AKA;
			break;
		case TAMA_COLOR_AO:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_AO;
			break;
		case TAMA_COLOR_MIDORI:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_MIDORI;
			break;
		case TAMA_COLOR_MURASAKI:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_MURASAKI;
			break;
		case TAMA_COLOR_ORANGE:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_ORANGE;
			break;
		case TAMA_COLOR_PINK:
			SelectTamaPath = MY_ANIME_NAME_TATEMARU_PINK;
			break;
		}
		break;
	}

	SplitNumALL = 4;
	SpritNumX = 4;
	SplitNumY = 1;
	SplitWidth = TAMA_WIDTH;
	SplitHeight = TAMA_HEIGHT;
	changeSpeed = TAMA_SPEED;
	IsLoop = TRUE;

	this->anime = new ANIMATION(
		MY_ANIME_DIR_TAMA, 
		SelectTamaPath.c_str(),
		SplitNumALL,
		SpritNumX,
		SplitNumY,
		SplitWidth,
		SplitHeight,
		changeSpeed,
		IsLoop);	//�e�𐶐�

	this->SetX_Y(0, 0);		//�ʒu��ݒ�
	this->IsEnbled = false;	//�e�𖳌���

	return;
}

//�f�X�g���N�^
TAMA::~TAMA()
{
	delete this->anime;
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
	this->X = SetX; this->Y = SetY; return;
}

//�摜��`��
void TAMA::Draw(void)
{
	if (this->IsEnbled == true)	//�`�悵�ėǂ��Ȃ�
	{
		this->anime->Draw();
	}
}