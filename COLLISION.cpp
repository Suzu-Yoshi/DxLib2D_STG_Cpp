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

//値を設定
void COLLISION::SetValue(int setLeft, int setTop, int setRight, int setBottom)
{
	this->left = setLeft;		//当たり判定の範囲を左を設定
	this->top = setTop;			//当たり判定の範囲を上を設定

	this->right = setRight;		//当たり判定の範囲を右を設定
	this->bottom = setBottom;	//当たり判定の範囲を下を設定

	return;
}

//衝突検知チェック
//引　数：Collision：衝突した相手
bool COLLISION::DetectionCheck(COLLISION aite)
{
	if (this->top < aite.bottom &&
		this->left < aite.right &&
		this->bottom > aite.top &&
		this->right > aite.left)
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
		DrawBox(this->left, this->top, this->right, this->bottom, GetColor(0, 0, 0),1);
	}
	return;
}

//当たり判定の範囲を描画（オーバーロード）
//引　数：unsigned int：GetColor(?,?,?)の戻り値
void COLLISION::Draw(unsigned int Color)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->left, this->top, this->right, this->bottom, Color, false);	//枠だけ描画
	}
	return;
}