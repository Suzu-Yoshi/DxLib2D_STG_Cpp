/* COLLISION.cpp     																			   */
/* COLLISIONクラス																				   */

//##########ヘッダーファイル読み込み ##########
#include "Collision.hpp"

//########## クラスの定義 ##########

//コンストラクタ
Collision::Collision()
{
	return;
}

//デストラクタ
Collision::~Collision()
{
	return;
}

//値を設定
void Collision::SetValue(int setTop, int setLeft, int setBottom, int setRight)
{
	this->top = setTop;			//当たり判定の範囲を上を設定
	this->left = setLeft;		//当たり判定の範囲を左を設定
	this->bottom = setBottom;	//当たり判定の範囲を下を設定
	this->right = setRight;		//当たり判定の範囲を右を設定

	return;
}

//衝突検知
bool Collision::DetectionCheck(Collision aite)
{

	return false;
}