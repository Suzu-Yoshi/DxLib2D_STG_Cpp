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
		DrawString(100, 100, "UP", RGB(255,255,255));
	}

	return;
}

//左に動く
VOID CHARACTOR::MoveLeft(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_LEFT))
	{
		DrawString(100, 100, "LEFT", RGB(255, 255, 255));
	}

	return;
}

//下に動く
VOID CHARACTOR::MoveDown(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_DOWN))
	{
		DrawString(100, 100, "DOWN", RGB(255, 255, 255));
	}

	return;
}

//右に動く
VOID CHARACTOR::MoveRight(VOID)
{
	if (this->charactor_keydown->IsKeyDown(KEY_INPUT_RIGHT))
	{
		DrawString(100, 100, "RIGHT", RGB(255, 255, 255));
	}

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
