/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* COLLISION.cpp     																			   */
/* COLLISIONクラス																				   */

//##########ヘッダーファイル読み込み ##########
#include "COLLISION.hpp"

//########## クラスの定義 ##########

//コンストラクタ
COLLISION::COLLISION()
{
	this->Sikaku = new SIKAKU();			//四角クラス作成
	this->SetIsDraw(true);

	return;
}

//デストラクタ
COLLISION::~COLLISION()
{
	delete Sikaku;

	return;
}

//衝突検知チェック
//引　数：Collision：衝突した相手
bool COLLISION::DetectionCheck(COLLISION aite)
{
	if (this->Sikaku->Top < aite.Sikaku->Bottom &&
		this->Sikaku->Left < aite.Sikaku->Right &&
		this->Sikaku->Bottom > aite.Sikaku->Top &&
		this->Sikaku->Right > aite.Sikaku->Left)
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
		DrawBox(this->Sikaku->Left, this->Sikaku->Top, this->Sikaku->Right, this->Sikaku->Bottom, GetColor(255,0,0), false);	//枠だけ描画
	}
	return;
}

//四角の位置を設定
void COLLISION::SetSikaku(int left, int top, int width, int height)
{
	this->Sikaku->SetValue(left, top, width, height);
	return;
}

//当たり判定の範囲を描画（オーバーロード）
//引　数：unsigned int：GetColor(?,?,?)の戻り値
void COLLISION::Draw(unsigned int Color)
{
	if (this->IsDraw == true)
	{
		DrawBox(this->Sikaku->Left, this->Sikaku->Top, this->Sikaku->Right, this->Sikaku->Bottom, Color, false);	//枠だけ描画
	}
	return;
}