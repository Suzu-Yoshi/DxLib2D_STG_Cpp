/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* PLAYER.cpp     																				   */
/* PLAYERクラス																					   */

//########## ヘッダーファイル読み込み ##########
#include "PLAYER.hpp"

//########## クラスの定義 ##########

//コンストラクタ
PLAYER::PLAYER()
{
	this->tama.resize(1);					//resize：vectorの要素数を変更する
	this->tama_itr = this->tama.begin();	//先頭のポインタを入れる

	return;
}

//デストラクタ
PLAYER::~PLAYER()
{

	return;
}

//操作
void PLAYER::Operation(KEYDOWN *keydown)
{
	if (keydown->IsKeyDown(KEY_INPUT_SPACE))			//スペースキーを押しているとき
	{
		this->CreateTama(TAMA_TYPE_TAMA, TAMA_COLOR_AKA);
	}

	return;
}

//弾を作成
void PLAYER::CreateTama(int type, int color)
{
	this->tama.push_back(TAMA());

}

//弾を描画
void PLAYER::DrawTama(void)
{

}

//弾を削除
void PLAYER::DeleteTama(void)
{

}