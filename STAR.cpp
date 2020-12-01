/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* STAR.cpp     																				�@ */
/* STAR�N���X 																					�@ */

//##########�w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "STAR.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
STAR::STAR()
{
	animation = new ANIMATION(
		MY_ANIME_BOMB_PATH,
		BAKU_1_ALL_CNT,
		BAKU_1_YOKO_CNT,
		BAKU_1_TATE_CNT,
		BAKU_1_WIDTH,
		BAKU_1_HEIGHT,
		BAKU_1_ANI_SPEED,
		false);

	return;
}

//�f�X�g���N�^
STAR::~STAR()
{
	delete animation;

	return;
}

//�����A�j���`��
void STAR::DrawAnime(void)
{
	if (this->GetIsDraw() == false)	//�����`�悵�Ă��Ȃ��Ƃ�
	{
		if (this->animation->GetIsAnimeStop() == false)	//�A�j���������Ă���Ƃ�
		{
			this->animation->Draw(
				this->Getsikaku_draw_GetCenterX() - BAKU_1_WIDTH / 2,
				this->Getsikaku_draw_GetCenterY() - BAKU_1_HEIGHT / 2
			);
		}
	}

	return;
}