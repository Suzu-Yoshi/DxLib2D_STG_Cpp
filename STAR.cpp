/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* STAR.cpp     																				　 */
/* STARクラス 																					　 */

//##########ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "STAR.hpp"

//########## クラスの定義 ##########

//コンストラクタ
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

//デストラクタ
STAR::~STAR()
{
	delete animation;

	return;
}

//爆発アニメ描画
void STAR::DrawAnime(void)
{
	if (this->GetIsDraw() == false)	//星が描画していないとき
	{
		if (this->animation->GetIsAnimeStop() == false)	//アニメが続いているとき
		{
			this->animation->Draw(
				this->Getsikaku_draw_GetCenterX() - BAKU_1_WIDTH / 2,
				this->Getsikaku_draw_GetCenterY() - BAKU_1_HEIGHT / 2
			);
		}
	}

	return;
}