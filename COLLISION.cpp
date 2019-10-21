/* COLLISION.cpp     																			   */
/* COLLISIONクラス																				   */

//##########ヘッダーファイル読み込み ##########
#include "COLLISION.hpp"

//########## クラスの定義 ##########

//コンストラクタ
COLLISION::COLLISION()
{
	return;
}

//デストラクタ
COLLISION::~COLLISION()
{
	return;
}

//衝突検知チェック
//引　数：Collision：衝突した相手
bool COLLISION::DetectionCheck(COLLISION aite)
{
	if (this->sikaku->Top < aite.sikaku->GetBottom() &&
		this->sikaku->Left < aite.sikaku->GetRight() &&
		this->sikaku->GetBottom() > aite.sikaku->Top &&
		this->sikaku->GetRight() > aite.sikaku->Left)
	{
		return true;	//当たった
	}

	return false;		//当たっていない
}

//当たり判定の範囲を描画するか
void COLLISION::SetIsDraw(bool draw)
{
	this->IsDraw = draw;
	return;
}

//当たり判定の範囲を描画
void COLLISION::Draw(void)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->sikaku->Left, this->sikaku->Top, this->sikaku->GetRight(), this->sikaku->GetBottom(), GetColor(0, 0, 0), false);	//枠だけ描画
	}
	return;
}

//当たり判定の範囲を描画（オーバーロード）
//引　数：unsigned int：GetColor(?,?,?)の戻り値
void COLLISION::Draw(unsigned int Color)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->sikaku->Left, this->sikaku->Top, this->sikaku->GetRight(), this->sikaku->GetBottom(), Color, false);	//枠だけ描画
	}
	return;
}