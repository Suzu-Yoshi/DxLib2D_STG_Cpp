/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* CHARACTOR.cpp     																				   */
/* CHARACTORクラス																				   */

//########## ヘッダーファイル読み込み ##########
#include "CHARACTOR.hpp"
#include "KEYDOWN.hpp"

//########## クラスの定義 ##########

//上に動く
VOID CHARACTOR::MoveUp(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_UP))
	{
		DrawString(100, 100, "TESYT", RGB(14, 144, 144));
	}

	return;
}

//左に動く
VOID CHARACTOR::MoveLeft(VOID)
{
	return;
}

//下に動く
VOID CHARACTOR::MoveDown(VOID)
{
	return;
}

//右に動く
VOID CHARACTOR::MoveRight(VOID)
{
	return;
}

//コンストラクタ
CHARACTOR::CHARACTOR()
{
	this->charactor_keydown = new KEYDOWN();
}

//デストラクタ
CHARACTOR::~CHARACTOR()
{
	delete this->charactor_keydown;
}
